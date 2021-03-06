package main

import (
	"bytes"
	"container/list"
	"fmt"
	"github.com/funcube-dev/go/fcio"
	"io"
	"log"
	"net"
	"net/http"
	"os"
	"strings"
	"time"

	"github.com/knadh/koanf"
	"github.com/knadh/koanf/parsers/toml"
	"github.com/knadh/koanf/providers/env"
	"github.com/knadh/koanf/providers/file"
	"github.com/knadh/koanf/providers/posflag"
	flag "github.com/spf13/pflag"
)

var config = readConfiguration()
var readerQueue = list.New()
var dataChan = make(chan []byte, 64)

func main() {
	log.Printf("Using Config:\n%s\n", ConfigSprintSafe())

	ignore := config.Bool("ignorecheck")
	if !warehouseCredentialsOk() {
		if !ignore {
			log.Fatalf("Failed, in the unlikely event that the data warehouse is down, adding --ignorecheck will skip this error, data submissions will retry")
		}
		log.Println("Failed but was ignored (--ignorecheck), if the warehouse is currently down, this will get you started and data submissions will retry, otherwise all data submissions WILL fail.")
	} else {
		log.Println("*** Warehouse Credentials (siteid/authcode) - OK ***")
	}

	fileName := config.String("file")
	if len(fileName) > 0 {
		fcbinfile, err := os.Open(fileName)
		if err != nil {
			log.Fatalf("Failed to open file %s error:%v", fileName, err)
		}
		reader, err := fcio.NewReadSeekCloser(fcbinfile)
		if err != nil {
			log.Fatalf("Failed to get reader from file %s error:%v", fileName, err)
		}
		readerQueue.PushBack(reader)
	}

	log.Printf("Done\n")

	go sendData()
	go readData()
	go listen()
	commandListen()
}

func ConfigSprintSafe() string {
	b := bytes.Buffer{}
	for _, k := range config.Keys() {
		v := config.Get(k)
		if k == "authcode" {
			ac, ok := v.(string)
			if !ok || len(ac)<2 {
				ac = "**"
			}
			// add last two characters of real authcode
			v = "********" + ac[len(ac)-2:]
		}
		b.Write([]byte(fmt.Sprintf("%s -> %v\n", k, v)))
	}
	return b.String()
}

func warehouseCredentialsOk() bool {
	baseURL := config.String("url")
	siteID := config.String("siteid")
	authCode := config.String("authcode")

	if siteID == "" || authCode == "" {
		log.Printf("Warehouse Credentials check failed, missing authcode and site id, please see:\n\nhttp://warehouse.funcube.org.uk/registration\n\n")
		return false
	}

	// dont use the NewFrame method as that checks for valid data sizes, we need a zero length data frame.
	frame := &Frame{[]byte{}, 0}
	digest, _ := frame.GetWarehouseDigest(authCode)

	warehouseURL := baseURL + "api/data/hex/" + siteID + "/?digest=" + digest

	resp, err := http.Get(warehouseURL)
	if err != nil {
		log.Printf("Warehouse Credentials check failed, cannot connect to: %s (%+v)\n", warehouseURL, err)
		return false
	}
	_ = resp.Body.Close()
	if resp.StatusCode == http.StatusUnauthorized {
		log.Print("Warehouse Credentials check failed, please ensure you have configured the correct values for siteid and authcode\n")
		return false
	}
	if resp.StatusCode >= 400 {
		log.Printf("Warehouse Credentials check failed, error code getting: %s (%d)\n", warehouseURL, resp.StatusCode)
		return false
	}
	return true
}

func readData() {
	for {
		// if there's nothing to read from wait then try again
		if readerQueue.Len() == 0 {
			time.Sleep(time.Second)
			fmt.Printf(".")
			continue
		}
		src := readerQueue.Front().Value.(*fcio.ReadSeekCloser)

		raw := make([]byte, 256)
		bytesRead, err := src.Read(raw)
		if err == io.EOF {
			fmt.Printf("^")
			readerQueue.Remove(readerQueue.Front())
			_ = src.Close()
			err = nil
		}
		if err != nil {
			panic(err)
		}

		if bytesRead != 256 {
			continue
		}

		fmt.Printf("<")		
		select {
		case dataChan <- raw:
		default:
			fmt.Println(" Discarded send channel full.")
		}
	}
}

func sendData() {
	log.Println("Ready to Send...")

	var frame *Frame
	var err error
	for {
		// update from config for each frame
		retryAttempts := config.Int("retryattempts")
		retryWaitSeconds := config.Int("retrywaitseconds")

		// not nil so must have been tried already, decrement retries and check it
		if frame != nil {
			frame.DecrementRetry()
			if frame.CanRetry() {
				// wait before retrying frame
				log.Printf("Retry waiting: %d  attempts remaining: %d of %d, backlog: %d\n", retryWaitSeconds, frame.RemainingRetry(), retryAttempts, len(dataChan))
				time.Sleep(time.Duration(retryWaitSeconds) * time.Second)
			} else {
				// discard frame
				frame = nil
				fmt.Printf("x")
			}
		}
				
		// if we haven't got a frame, try and get one
		if frame == nil {			
			select {
			case frameData := <-dataChan:
				frame, err = NewFrame(frameData, retryAttempts)
				if err != nil {
					frame = nil // if NewFrame returns an error, ensure frame will be nil
					log.Printf("Failed to create frame: (%+v)\n", err)
					continue
				}
			default:
				fmt.Printf("*")
				time.Sleep(time.Millisecond * 500)
				continue
			}
		}

		baseURL := config.String("url")
		siteID := config.String("siteid")
		authCode := config.String("authcode")

		digest, err := frame.GetWarehouseDigest(authCode)
		if err != nil {
			log.Printf("Failed to get digest: (%+v)\n", err)
			continue
		}

		warehouseURL := baseURL + "api/data/hex/" + siteID + "/?digest=" + digest

		resp, err := http.Post(warehouseURL, "application/x-www-form-urlencoded", frame.GetWarehousePayload())
		if err != nil {
			log.Printf("Failed to connect to: %s (%+v)\n", warehouseURL, err)
			continue
		}
		_ = resp.Body.Close()
		if resp.StatusCode >= 400 {
			log.Printf("Error code sending to: %s (%d)\n", warehouseURL, resp.StatusCode)
			continue
		}

		fmt.Printf(">")
		// success clear the current frame so new one is retrieved
		frame = nil
	}
}

func listen() {
	host := config.String("bindaddress")
	port := config.String("dataport")
	hostport := net.JoinHostPort(host, port)
	log.Println("Opening listen socket...")
	lsock, err := net.Listen("tcp4", hostport)
	if err != nil {
		fmt.Println(err)
		return
	}
	defer lsock.Close()
	log.Printf("Listening on socket: %s", hostport)

	for {
		c, err := lsock.Accept()
		if err != nil {
			fmt.Println(err)
			return
		}
		handleConnection(c)
	}
}

func commandListen() {
	host := config.String("bindaddress")
	port := config.String("commandport")
	hostport := net.JoinHostPort(host, port)
	log.Println("Opening command listen socket...")
	lsock, err := net.Listen("tcp4", hostport)
	if err != nil {
		fmt.Println(err)
		return
	}
	defer lsock.Close()
	log.Printf("Listening for commands on socket: %s", hostport)

	for {
		c, err := lsock.Accept()
		if err != nil {
			fmt.Println(err)
			return
		}
		handleCommandConnection(c)
	}
}

func handleConnection(c net.Conn) {
	log.Printf("Connection from: %s", c.RemoteAddr().String())

	tc, err := fcio.NewTimedConn(c, time.Second)
	if err != nil {
		log.Printf("Failed to create TimedConn, ignoring error:%v", err)
		return
	}
	reader, err := fcio.NewReadSeekCloser(tc)
	if err != nil {
		log.Printf("Failed to create reader, ignoring error:%v", err)
		return
	}
	readerQueue.PushBack(reader)
}

func handleCommandConnection(c net.Conn) {
	log.Printf("Connection from: %v", c)
}

func readConfiguration() *koanf.Koanf {
	var konf = koanf.New(".")

	_ = konf.Load(env.Provider("WH_", ".", func(s string) string {
		return strings.Replace(strings.ToLower(
			strings.TrimPrefix(s, "WH_")), "_", ".", -1)
	}), nil)

	for _, fileName := range []string{"/config/fcwarehouse.conf", "./fcwarehouse.conf"} {
		if _, err := os.Stat(fileName); err == nil {
			if err := konf.Load(file.Provider(fileName), toml.Parser()); err != nil {
				log.Fatalf("error loading config: %v", err)
			}
		}
	}

	flag.String("siteid", "", "Site Id for data warehouse")
	flag.String("authcode", "", "Authentication code for data warehouse")
	flag.Bool("ignorecheck", false, "Ignore the results of the warehouse credential check and start anyway")
	flag.String("url", "http://data.amsat-uk.org/", "Url for submitting to data warehouse")
	flag.Int("retryattempts", -1, "Number of warehouse submission retries before moving on to next frame (infinite attempts)")
	flag.Int("retrywaitseconds", 60, "Time to wait between retry attempts")
	flag.String("bindaddress", "0.0.0.0", "Address to bind for TCP listen sockets")
	flag.Int("dataport", int(0xFC06), "Port for incomming decoded data (256 bytes chunks)")
	flag.Int("commandport", int(0xFC07), "Port for incomming commands")
	flag.String("file", "", "Path of funcubebin file to upload to warehouse (multiple of 256 bytes in length)")
	flag.Parse()

	if err := konf.Load(posflag.Provider(flag.CommandLine, ".", konf), nil); err != nil {
		log.Fatalf("error loading config: %v", err)
	}

	return konf
}
