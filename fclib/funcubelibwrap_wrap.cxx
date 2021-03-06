/* ----------------------------------------------------------------------------
 * This file was automatically generated by SWIG (http://www.swig.org).
 * Version 3.0.12
 *
 * This file is not intended to be easily readable and contains a number of
 * coding conventions designed to improve portability and efficiency. Do not make
 * changes to this file unless you know what you are doing--modify the SWIG
 * interface file instead.
 * ----------------------------------------------------------------------------- */

// source: funcubelibwrap.i

#define SWIGMODULE funcubelibwrap
#define SWIG_DIRECTORS

#ifdef __cplusplus
/* SwigValueWrapper is described in swig.swg */
template<typename T> class SwigValueWrapper {
  struct SwigMovePointer {
    T *ptr;
    SwigMovePointer(T *p) : ptr(p) { }
    ~SwigMovePointer() { delete ptr; }
    SwigMovePointer& operator=(SwigMovePointer& rhs) { T* oldptr = ptr; ptr = 0; delete oldptr; ptr = rhs.ptr; rhs.ptr = 0; return *this; }
  } pointer;
  SwigValueWrapper& operator=(const SwigValueWrapper<T>& rhs);
  SwigValueWrapper(const SwigValueWrapper<T>& rhs);
public:
  SwigValueWrapper() : pointer(0) { }
  SwigValueWrapper& operator=(const T& t) { SwigMovePointer tmp(new T(t)); pointer = tmp; return *this; }
  operator T&() const { return *pointer.ptr; }
  T *operator&() { return pointer.ptr; }
};

template <typename T> T SwigValueInit() {
  return T();
}
#endif

/* -----------------------------------------------------------------------------
 *  This section contains generic SWIG labels for method/variable
 *  declarations/attributes, and other compiler dependent labels.
 * ----------------------------------------------------------------------------- */

/* template workaround for compilers that cannot correctly implement the C++ standard */
#ifndef SWIGTEMPLATEDISAMBIGUATOR
# if defined(__SUNPRO_CC) && (__SUNPRO_CC <= 0x560)
#  define SWIGTEMPLATEDISAMBIGUATOR template
# elif defined(__HP_aCC)
/* Needed even with `aCC -AA' when `aCC -V' reports HP ANSI C++ B3910B A.03.55 */
/* If we find a maximum version that requires this, the test would be __HP_aCC <= 35500 for A.03.55 */
#  define SWIGTEMPLATEDISAMBIGUATOR template
# else
#  define SWIGTEMPLATEDISAMBIGUATOR
# endif
#endif

/* inline attribute */
#ifndef SWIGINLINE
# if defined(__cplusplus) || (defined(__GNUC__) && !defined(__STRICT_ANSI__))
#   define SWIGINLINE inline
# else
#   define SWIGINLINE
# endif
#endif

/* attribute recognised by some compilers to avoid 'unused' warnings */
#ifndef SWIGUNUSED
# if defined(__GNUC__)
#   if !(defined(__cplusplus)) || (__GNUC__ > 3 || (__GNUC__ == 3 && __GNUC_MINOR__ >= 4))
#     define SWIGUNUSED __attribute__ ((__unused__))
#   else
#     define SWIGUNUSED
#   endif
# elif defined(__ICC)
#   define SWIGUNUSED __attribute__ ((__unused__))
# else
#   define SWIGUNUSED
# endif
#endif

#ifndef SWIG_MSC_UNSUPPRESS_4505
# if defined(_MSC_VER)
#   pragma warning(disable : 4505) /* unreferenced local function has been removed */
# endif
#endif

#ifndef SWIGUNUSEDPARM
# ifdef __cplusplus
#   define SWIGUNUSEDPARM(p)
# else
#   define SWIGUNUSEDPARM(p) p SWIGUNUSED
# endif
#endif

/* internal SWIG method */
#ifndef SWIGINTERN
# define SWIGINTERN static SWIGUNUSED
#endif

/* internal inline SWIG method */
#ifndef SWIGINTERNINLINE
# define SWIGINTERNINLINE SWIGINTERN SWIGINLINE
#endif

/* exporting methods */
#if defined(__GNUC__)
#  if (__GNUC__ >= 4) || (__GNUC__ == 3 && __GNUC_MINOR__ >= 4)
#    ifndef GCC_HASCLASSVISIBILITY
#      define GCC_HASCLASSVISIBILITY
#    endif
#  endif
#endif

#ifndef SWIGEXPORT
# if defined(_WIN32) || defined(__WIN32__) || defined(__CYGWIN__)
#   if defined(STATIC_LINKED)
#     define SWIGEXPORT
#   else
#     define SWIGEXPORT __declspec(dllexport)
#   endif
# else
#   if defined(__GNUC__) && defined(GCC_HASCLASSVISIBILITY)
#     define SWIGEXPORT __attribute__ ((visibility("default")))
#   else
#     define SWIGEXPORT
#   endif
# endif
#endif

/* calling conventions for Windows */
#ifndef SWIGSTDCALL
# if defined(_WIN32) || defined(__WIN32__) || defined(__CYGWIN__)
#   define SWIGSTDCALL __stdcall
# else
#   define SWIGSTDCALL
# endif
#endif

/* Deal with Microsoft's attempt at deprecating C standard runtime functions */
#if !defined(SWIG_NO_CRT_SECURE_NO_DEPRECATE) && defined(_MSC_VER) && !defined(_CRT_SECURE_NO_DEPRECATE)
# define _CRT_SECURE_NO_DEPRECATE
#endif

/* Deal with Microsoft's attempt at deprecating methods in the standard C++ library */
#if !defined(SWIG_NO_SCL_SECURE_NO_DEPRECATE) && defined(_MSC_VER) && !defined(_SCL_SECURE_NO_DEPRECATE)
# define _SCL_SECURE_NO_DEPRECATE
#endif

/* Deal with Apple's deprecated 'AssertMacros.h' from Carbon-framework */
#if defined(__APPLE__) && !defined(__ASSERT_MACROS_DEFINE_VERSIONS_WITHOUT_UNDERSCORES)
# define __ASSERT_MACROS_DEFINE_VERSIONS_WITHOUT_UNDERSCORES 0
#endif

/* Intel's compiler complains if a variable which was never initialised is
 * cast to void, which is a common idiom which we use to indicate that we
 * are aware a variable isn't used.  So we just silence that warning.
 * See: https://github.com/swig/swig/issues/192 for more discussion.
 */
#ifdef __INTEL_COMPILER
# pragma warning disable 592
#endif


#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>



typedef long long intgo;
typedef unsigned long long uintgo;


# if !defined(__clang__) && (defined(__i386__) || defined(__x86_64__))
#   define SWIGSTRUCTPACKED __attribute__((__packed__, __gcc_struct__))
# else
#   define SWIGSTRUCTPACKED __attribute__((__packed__))
# endif



typedef struct { char *p; intgo n; } _gostring_;
typedef struct { void* array; intgo len; intgo cap; } _goslice_;




#define swiggo_size_assert_eq(x, y, name) typedef char name[(x-y)*(x-y)*-2+1];
#define swiggo_size_assert(t, n) swiggo_size_assert_eq(sizeof(t), n, swiggo_sizeof_##t##_is_not_##n)

swiggo_size_assert(char, 1)
swiggo_size_assert(short, 2)
swiggo_size_assert(int, 4)
typedef long long swiggo_long_long;
swiggo_size_assert(swiggo_long_long, 8)
swiggo_size_assert(float, 4)
swiggo_size_assert(double, 8)

#ifdef __cplusplus
extern "C" {
#endif
extern void crosscall2(void (*fn)(void *, int), void *, int);
extern char* _cgo_topofstack(void) __attribute__ ((weak));
extern void _cgo_allocate(void *, int);
extern void _cgo_panic(void *, int);
#ifdef __cplusplus
}
#endif

static char *_swig_topofstack() {
  if (_cgo_topofstack) {
    return _cgo_topofstack();
  } else {
    return 0;
  }
}

static void _swig_gopanic(const char *p) {
  struct {
    const char *p;
  } SWIGSTRUCTPACKED a;
  a.p = p;
  crosscall2(_cgo_panic, &a, (int) sizeof a);
}




#define SWIG_contract_assert(expr, msg) \
  if (!(expr)) { _swig_gopanic(msg); } else


static _gostring_ Swig_AllocateString(const char *p, size_t l) {
  _gostring_ ret;
  ret.p = (char*)malloc(l);
  memcpy(ret.p, p, l);
  ret.n = l;
  return ret;
}


static void Swig_free(void* p) {
  free(p);
}

static void* Swig_malloc(int c) {
  return malloc(c);
}


#include "funcubelib/wintypes.h"
#include "funcubelib/funcubeLib.h"
#include "callbackshim.h"


// C++ director class methods.
#include "funcubelibwrap_wrap.h"


#include <map>

namespace {
  struct GCItem {
    virtual ~GCItem() {}
  };

  struct GCItem_var {
    GCItem_var(GCItem *item = 0) : _item(item) {
    }

    GCItem_var& operator=(GCItem *item) {
      GCItem *tmp = _item;
      _item = item;
      delete tmp;
      return *this;
    }

    ~GCItem_var() {
      delete _item;
    }

    GCItem* operator->() {
      return _item;
    }

    private:
      GCItem *_item;
  };

  template <typename Type>
  struct GCItem_T : GCItem {
    GCItem_T(Type *ptr) : _ptr(ptr) {
    }

    virtual ~GCItem_T() {
      delete _ptr;
    }

  private:
    Type *_ptr;
  };
}

class Swig_memory {
public:
  template <typename Type>
  void swig_acquire_pointer(Type* vptr) {
    if (vptr) {
      swig_owner[vptr] = new GCItem_T<Type>(vptr);
    }
  }
private:
  typedef std::map<void *, GCItem_var> swig_ownership_map;
  swig_ownership_map swig_owner;
};

template <typename Type>
static void swig_acquire_pointer(Swig_memory** pmem, Type* ptr) {
  if (!pmem) {
    *pmem = new Swig_memory;
  }
  (*pmem)->swig_acquire_pointer(ptr);
}

SwigDirector_CallbackShim::SwigDirector_CallbackShim(int swig_p)
    : CallbackShim(),
      go_val(swig_p), swig_mem(0)
{ }

extern "C" void Swiggo_DeleteDirector_CallbackShim_fclib_a388184c668b9ee2(intgo);
SwigDirector_CallbackShim::~SwigDirector_CallbackShim()
{
  Swiggo_DeleteDirector_CallbackShim_fclib_a388184c668b9ee2(go_val);
  delete swig_mem;
}

extern "C" void Swig_DirectorCallbackShim_callback_run_fclib_a388184c668b9ee2(int);
void SwigDirector_CallbackShim::run() {
  Swig_DirectorCallbackShim_callback_run_fclib_a388184c668b9ee2(go_val);
}

#ifdef __cplusplus
extern "C" {
#endif

void _wrap_Swig_free_fclib_a388184c668b9ee2(void *_swig_go_0) {
  void *arg1 = (void *) 0 ;
  
  arg1 = *(void **)&_swig_go_0; 
  
  Swig_free(arg1);
  
}


void *_wrap_Swig_malloc_fclib_a388184c668b9ee2(intgo _swig_go_0) {
  int arg1 ;
  void *result = 0 ;
  void *_swig_go_result;
  
  arg1 = (int)_swig_go_0; 
  
  result = (void *)Swig_malloc(arg1);
  *(void **)&_swig_go_result = (void *)result; 
  return _swig_go_result;
}


int _wrap_timeGetTime_fclib_a388184c668b9ee2() {
  DWORD result;
  int _swig_go_result;
  
  
  result = timeGetTime();
  *(DWORD **)&_swig_go_result = new DWORD(result); 
  return _swig_go_result;
}


float _wrap_HZ_PER_BIN_get_fclib_a388184c668b9ee2() {
  FLOAT result;
  float _swig_go_result;
  
  
  result = (FLOAT)(FLOAT)HZ_PER_BIN;
  _swig_go_result = result; 
  return _swig_go_result;
}


double _wrap_PI_get_fclib_a388184c668b9ee2() {
  DOUBLE result;
  double _swig_go_result;
  
  
  result = (DOUBLE)(DOUBLE)PI;
  _swig_go_result = result; 
  return _swig_go_result;
}


double _wrap_HALF_PI_get_fclib_a388184c668b9ee2() {
  DOUBLE result;
  double _swig_go_result;
  
  
  result = (DOUBLE)(DOUBLE)HALF_PI;
  _swig_go_result = result; 
  return _swig_go_result;
}


double _wrap_TWO_PI_get_fclib_a388184c668b9ee2() {
  DOUBLE result;
  double _swig_go_result;
  
  
  result = (DOUBLE)(DOUBLE)TWO_PI;
  _swig_go_result = result; 
  return _swig_go_result;
}


void _wrap_LogMessage_fclib_a388184c668b9ee2(intgo _swig_go_0, std::string *_swig_go_1) {
  int arg1 ;
  std::string *arg2 = 0 ;
  
  arg1 = (int)_swig_go_0; 
  arg2 = *(std::string **)&_swig_go_1; 
  
  LogMessage(arg1,(std::string const &)*arg2);
  
}


intgo _wrap_FFTRangeLimit_Off_fclib_a388184c668b9ee2() {
  FFTRangeLimit result;
  intgo _swig_go_result;
  
  
  result = FFTRangeLimit_Off;
  
  _swig_go_result = (intgo)result; 
  return _swig_go_result;
}


intgo _wrap_FFTRangeLimit_010_fclib_a388184c668b9ee2() {
  FFTRangeLimit result;
  intgo _swig_go_result;
  
  
  result = FFTRangeLimit_010;
  
  _swig_go_result = (intgo)result; 
  return _swig_go_result;
}


intgo _wrap_FFTRangeLimit_020_fclib_a388184c668b9ee2() {
  FFTRangeLimit result;
  intgo _swig_go_result;
  
  
  result = FFTRangeLimit_020;
  
  _swig_go_result = (intgo)result; 
  return _swig_go_result;
}


intgo _wrap_FFTRangeLimit_040_fclib_a388184c668b9ee2() {
  FFTRangeLimit result;
  intgo _swig_go_result;
  
  
  result = FFTRangeLimit_040;
  
  _swig_go_result = (intgo)result; 
  return _swig_go_result;
}


intgo _wrap_FFTRangeLimit_080_fclib_a388184c668b9ee2() {
  FFTRangeLimit result;
  intgo _swig_go_result;
  
  
  result = FFTRangeLimit_080;
  
  _swig_go_result = (intgo)result; 
  return _swig_go_result;
}


intgo _wrap_FFTRangeLimit_140_fclib_a388184c668b9ee2() {
  FFTRangeLimit result;
  intgo _swig_go_result;
  
  
  result = FFTRangeLimit_140;
  
  _swig_go_result = (intgo)result; 
  return _swig_go_result;
}


intgo _wrap_FFTRangeLimit_200_fclib_a388184c668b9ee2() {
  FFTRangeLimit result;
  intgo _swig_go_result;
  
  
  result = FFTRangeLimit_200;
  
  _swig_go_result = (intgo)result; 
  return _swig_go_result;
}


intgo _wrap_FFTRangeLimit_Slope_fclib_a388184c668b9ee2() {
  FFTRangeLimit result;
  intgo _swig_go_result;
  
  
  result = FFTRangeLimit_Slope;
  
  _swig_go_result = (intgo)result; 
  return _swig_go_result;
}


intgo _wrap_FFTTunerState_Off_fclib_a388184c668b9ee2() {
  FFTTunerState result;
  intgo _swig_go_result;
  
  
  result = FFTTunerState_Off;
  
  _swig_go_result = (intgo)result; 
  return _swig_go_result;
}


intgo _wrap_FFTTunerState_On_fclib_a388184c668b9ee2() {
  FFTTunerState result;
  intgo _swig_go_result;
  
  
  result = FFTTunerState_On;
  
  _swig_go_result = (intgo)result; 
  return _swig_go_result;
}


intgo _wrap_FFTTunerState_Lock_fclib_a388184c668b9ee2() {
  FFTTunerState result;
  intgo _swig_go_result;
  
  
  result = FFTTunerState_Lock;
  
  _swig_go_result = (intgo)result; 
  return _swig_go_result;
}


intgo _wrap_Library_GetVersion_fclib_a388184c668b9ee2() {
  UINT result;
  intgo _swig_go_result;
  
  
  result = (UINT)Library_GetVersion();
  _swig_go_result = result; 
  return _swig_go_result;
}


intgo _wrap_Library_CheckFftwExists_fclib_a388184c668b9ee2() {
  BOOL result;
  intgo _swig_go_result;
  
  
  result = (BOOL)Library_CheckFftwExists();
  _swig_go_result = result; 
  return _swig_go_result;
}


intgo _wrap_Library_SetOnLogMessageCallback_fclib_a388184c668b9ee2(void** _swig_go_0) {
  OnLogMessageCallback arg1 = (OnLogMessageCallback) 0 ;
  BOOL result;
  intgo _swig_go_result;
  
  arg1 = *(OnLogMessageCallback *)&_swig_go_0; 
  
  result = (BOOL)Library_SetOnLogMessageCallback(arg1);
  _swig_go_result = result; 
  return _swig_go_result;
}


intgo _wrap_Dongle_Initialize_fclib_a388184c668b9ee2() {
  BOOL result;
  intgo _swig_go_result;
  
  
  result = (BOOL)Dongle_Initialize();
  _swig_go_result = result; 
  return _swig_go_result;
}


intgo _wrap_Dongle_Shutdown_fclib_a388184c668b9ee2() {
  BOOL result;
  intgo _swig_go_result;
  
  
  result = (BOOL)Dongle_Shutdown();
  _swig_go_result = result; 
  return _swig_go_result;
}


intgo _wrap_Dongle_Exists_fclib_a388184c668b9ee2() {
  BOOL result;
  intgo _swig_go_result;
  
  
  result = (BOOL)Dongle_Exists();
  _swig_go_result = result; 
  return _swig_go_result;
}


int _wrap_Dongle_GetFrequency_fclib_a388184c668b9ee2() {
  ULONG result;
  int _swig_go_result;
  
  
  result = Dongle_GetFrequency();
  *(ULONG **)&_swig_go_result = new ULONG(result); 
  return _swig_go_result;
}


intgo _wrap_Dongle_SetFrequency_fclib_a388184c668b9ee2(int _swig_go_0) {
  ULONG arg1 ;
  BOOL result;
  intgo _swig_go_result;
  
  arg1 = (ULONG)_swig_go_0; 
  
  result = (BOOL)Dongle_SetFrequency(arg1);
  _swig_go_result = result; 
  return _swig_go_result;
}


intgo _wrap_Dongle_BiasTEnable_fclib_a388184c668b9ee2(intgo _swig_go_0) {
  BOOL arg1 ;
  BOOL result;
  intgo _swig_go_result;
  
  arg1 = (BOOL)_swig_go_0; 
  
  result = (BOOL)Dongle_BiasTEnable(arg1);
  _swig_go_result = result; 
  return _swig_go_result;
}


intgo _wrap_Decode_Initialize_fclib_a388184c668b9ee2() {
  BOOL result;
  intgo _swig_go_result;
  
  
  result = (BOOL)Decode_Initialize();
  _swig_go_result = result; 
  return _swig_go_result;
}


intgo _wrap_Decode_Shutdown_fclib_a388184c668b9ee2() {
  BOOL result;
  intgo _swig_go_result;
  
  
  result = (BOOL)Decode_Shutdown();
  _swig_go_result = result; 
  return _swig_go_result;
}


intgo _wrap_Decode_EnumDevices_fclib_a388184c668b9ee2(void** _swig_go_0) {
  DeviceEnumCallback arg1 = (DeviceEnumCallback) 0 ;
  BOOL result;
  intgo _swig_go_result;
  
  arg1 = *(DeviceEnumCallback *)&_swig_go_0; 
  
  result = (BOOL)Decode_EnumDevices(arg1);
  _swig_go_result = result; 
  return _swig_go_result;
}


intgo _wrap_Decode_Start_fclib_a388184c668b9ee2(_gostring_ _swig_go_0, _gostring_ _swig_go_1, intgo _swig_go_2, intgo _swig_go_3) {
  char *arg1 = (char *) 0 ;
  char *arg2 = (char *) 0 ;
  BOOL arg3 ;
  BOOL arg4 ;
  BOOL result;
  intgo _swig_go_result;
  
  
  arg1 = (char *)malloc(_swig_go_0.n + 1);
  memcpy(arg1, _swig_go_0.p, _swig_go_0.n);
  arg1[_swig_go_0.n] = '\0';
  
  
  arg2 = (char *)malloc(_swig_go_1.n + 1);
  memcpy(arg2, _swig_go_1.p, _swig_go_1.n);
  arg2[_swig_go_1.n] = '\0';
  
  arg3 = (BOOL)_swig_go_2; 
  arg4 = (BOOL)_swig_go_3; 
  
  result = (BOOL)Decode_Start((char const *)arg1,(char const *)arg2,arg3,arg4);
  _swig_go_result = result; 
  free(arg1); 
  free(arg2); 
  return _swig_go_result;
}


intgo _wrap_Decode_StartByIndex_fclib_a388184c668b9ee2(intgo _swig_go_0, intgo _swig_go_1, intgo _swig_go_2, intgo _swig_go_3) {
  int arg1 ;
  int arg2 ;
  BOOL arg3 ;
  BOOL arg4 ;
  BOOL result;
  intgo _swig_go_result;
  
  arg1 = (int)_swig_go_0; 
  arg2 = (int)_swig_go_1; 
  arg3 = (BOOL)_swig_go_2; 
  arg4 = (BOOL)_swig_go_3; 
  
  result = (BOOL)Decode_StartByIndex(arg1,arg2,arg3,arg4);
  _swig_go_result = result; 
  return _swig_go_result;
}


intgo _wrap_Decode_Stop_fclib_a388184c668b9ee2() {
  BOOL result;
  intgo _swig_go_result;
  
  
  result = (BOOL)Decode_Stop();
  _swig_go_result = result; 
  return _swig_go_result;
}


void _wrap_Decode_SetManualTuneFrequency_fclib_a388184c668b9ee2(float _swig_go_0) {
  FLOAT arg1 ;
  
  arg1 = (FLOAT)_swig_go_0; 
  
  Decode_SetManualTuneFrequency(arg1);
  
}


void _wrap_Decode_SetAutoTuneFrequencyRange_fclib_a388184c668b9ee2(float _swig_go_0, float _swig_go_1) {
  FLOAT arg1 ;
  FLOAT arg2 ;
  
  arg1 = (FLOAT)_swig_go_0; 
  arg2 = (FLOAT)_swig_go_1; 
  
  Decode_SetAutoTuneFrequencyRange(arg1,arg2);
  
}


intgo _wrap_Decode_CollectFftOutput_fclib_a388184c668b9ee2(float *_swig_go_0, int *_swig_go_1) {
  FLOAT *arg1 = (FLOAT *) 0 ;
  ULONG *arg2 = (ULONG *) 0 ;
  BOOL result;
  intgo _swig_go_result;
  
  arg1 = *(FLOAT **)&_swig_go_0; 
  arg2 = *(ULONG **)&_swig_go_1; 
  
  result = (BOOL)Decode_CollectFftOutput(arg1,arg2);
  _swig_go_result = result; 
  return _swig_go_result;
}


intgo _wrap_Decode_CollectFftOutputByRange_fclib_a388184c668b9ee2(float _swig_go_0, float _swig_go_1, float *_swig_go_2, int *_swig_go_3) {
  FLOAT arg1 ;
  FLOAT arg2 ;
  FLOAT *arg3 = (FLOAT *) 0 ;
  ULONG *arg4 = (ULONG *) 0 ;
  BOOL result;
  intgo _swig_go_result;
  
  arg1 = (FLOAT)_swig_go_0; 
  arg2 = (FLOAT)_swig_go_1; 
  arg3 = *(FLOAT **)&_swig_go_2; 
  arg4 = *(ULONG **)&_swig_go_3; 
  
  result = (BOOL)Decode_CollectFftOutputByRange(arg1,arg2,arg3,arg4);
  _swig_go_result = result; 
  return _swig_go_result;
}


intgo _wrap_Decode_SetOnDataCallback_fclib_a388184c668b9ee2(void** _swig_go_0) {
  OnDataCallback arg1 = (OnDataCallback) 0 ;
  BOOL result;
  intgo _swig_go_result;
  
  arg1 = *(OnDataCallback *)&_swig_go_0; 
  
  result = (BOOL)Decode_SetOnDataCallback(arg1);
  _swig_go_result = result; 
  return _swig_go_result;
}


void _wrap_Decode_EnableMonitorAudio_fclib_a388184c668b9ee2(intgo _swig_go_0) {
  BOOL arg1 ;
  
  arg1 = (BOOL)_swig_go_0; 
  
  Decode_EnableMonitorAudio(arg1);
  
}


void _wrap_Decode_RemoveDCOffset_fclib_a388184c668b9ee2(intgo _swig_go_0) {
  BOOL arg1 ;
  
  arg1 = (BOOL)_swig_go_0; 
  
  Decode_RemoveDCOffset(arg1);
  
}


intgo _wrap_Decode_RefreshAudioDevices_fclib_a388184c668b9ee2() {
  BOOL result;
  intgo _swig_go_result;
  
  
  result = (BOOL)Decode_RefreshAudioDevices();
  _swig_go_result = result; 
  return _swig_go_result;
}


intgo _wrap_Decode_IsStarted_fclib_a388184c668b9ee2() {
  BOOL result;
  intgo _swig_go_result;
  
  
  result = (BOOL)Decode_IsStarted();
  _swig_go_result = result; 
  return _swig_go_result;
}


intgo _wrap_Decode_SetTrackingParams_fclib_a388184c668b9ee2(intgo _swig_go_0) {
  int arg1 ;
  BOOL result;
  intgo _swig_go_result;
  
  arg1 = (int)_swig_go_0; 
  
  result = (BOOL)Decode_SetTrackingParams(arg1);
  _swig_go_result = result; 
  return _swig_go_result;
}


void _wrap_Decode_SetPeakDetectParams_fclib_a388184c668b9ee2(intgo _swig_go_0, double _swig_go_1) {
  UINT arg1 ;
  DOUBLE arg2 ;
  
  arg1 = (UINT)_swig_go_0; 
  arg2 = (DOUBLE)_swig_go_1; 
  
  Decode_SetPeakDetectParams(arg1,arg2);
  
}


intgo _wrap_Decode_SetWorkerCount_fclib_a388184c668b9ee2(int _swig_go_0) {
  ULONG arg1 ;
  BOOL result;
  intgo _swig_go_result;
  
  arg1 = (ULONG)_swig_go_0; 
  
  result = (BOOL)Decode_SetWorkerCount(arg1);
  _swig_go_result = result; 
  return _swig_go_result;
}


intgo _wrap_Decode_GetWorkerPeaks_fclib_a388184c668b9ee2(float *_swig_go_0, int *_swig_go_1) {
  FLOAT *arg1 = (FLOAT *) 0 ;
  ULONG *arg2 = (ULONG *) 0 ;
  BOOL result;
  intgo _swig_go_result;
  
  arg1 = *(FLOAT **)&_swig_go_0; 
  arg2 = *(ULONG **)&_swig_go_1; 
  
  result = (BOOL)Decode_GetWorkerPeaks(arg1,arg2);
  _swig_go_result = result; 
  return _swig_go_result;
}


intgo _wrap_Decode_GetWorkerAvailability_fclib_a388184c668b9ee2(intgo *_swig_go_0, int *_swig_go_1) {
  UINT *arg1 = (UINT *) 0 ;
  ULONG *arg2 = (ULONG *) 0 ;
  BOOL result;
  intgo _swig_go_result;
  
  arg1 = *(UINT **)&_swig_go_0; 
  arg2 = *(ULONG **)&_swig_go_1; 
  
  result = (BOOL)Decode_GetWorkerAvailability(arg1,arg2);
  _swig_go_result = result; 
  return _swig_go_result;
}


intgo _wrap_Decode_ExcludePeaks_fclib_a388184c668b9ee2(float *_swig_go_0, int *_swig_go_1) {
  FLOAT *arg1 = (FLOAT *) 0 ;
  ULONG *arg2 = (ULONG *) 0 ;
  BOOL result;
  intgo _swig_go_result;
  
  arg1 = *(FLOAT **)&_swig_go_0; 
  arg2 = *(ULONG **)&_swig_go_1; 
  
  result = (BOOL)Decode_ExcludePeaks(arg1,arg2);
  _swig_go_result = result; 
  return _swig_go_result;
}


intgo _wrap_Decode_SetOnDataReadyCallback_fclib_a388184c668b9ee2(void** _swig_go_0) {
  OnDataReadyCallback arg1 = (OnDataReadyCallback) 0 ;
  BOOL result;
  intgo _swig_go_result;
  
  arg1 = *(OnDataReadyCallback *)&_swig_go_0; 
  
  result = (BOOL)Decode_SetOnDataReadyCallback(arg1);
  _swig_go_result = result; 
  return _swig_go_result;
}


intgo _wrap_Decode_CollectLastData_fclib_a388184c668b9ee2(char *_swig_go_0, int *_swig_go_1, float *_swig_go_2, intgo *_swig_go_3) {
  BYTE *arg1 = (BYTE *) 0 ;
  ULONG *arg2 = (ULONG *) 0 ;
  FLOAT *arg3 = (FLOAT *) 0 ;
  INT *arg4 = (INT *) 0 ;
  BOOL result;
  intgo _swig_go_result;
  
  arg1 = *(BYTE **)&_swig_go_0; 
  arg2 = *(ULONG **)&_swig_go_1; 
  arg3 = *(FLOAT **)&_swig_go_2; 
  arg4 = *(INT **)&_swig_go_3; 
  
  result = (BOOL)Decode_CollectLastData(arg1,arg2,arg3,arg4);
  _swig_go_result = result; 
  return _swig_go_result;
}


_gostring_ _wrap_Decode_LastError_fclib_a388184c668b9ee2() {
  char *result = 0 ;
  _gostring_ _swig_go_result;
  
  
  result = (char *)Decode_LastError();
  _swig_go_result = Swig_AllocateString((char*)result, result ? strlen((char*)result) : 0); 
  return _swig_go_result;
}


intgo _wrap_Encode_Initialize_fclib_a388184c668b9ee2() {
  BOOL result;
  intgo _swig_go_result;
  
  
  result = (BOOL)Encode_Initialize();
  _swig_go_result = result; 
  return _swig_go_result;
}


intgo _wrap_Encode_Shutdown_fclib_a388184c668b9ee2() {
  BOOL result;
  intgo _swig_go_result;
  
  
  result = (BOOL)Encode_Shutdown();
  _swig_go_result = result; 
  return _swig_go_result;
}


intgo _wrap_Encode_CanCollect_fclib_a388184c668b9ee2() {
  BOOL result;
  intgo _swig_go_result;
  
  
  result = (BOOL)Encode_CanCollect();
  _swig_go_result = result; 
  return _swig_go_result;
}


intgo _wrap_Encode_AllDataCollected_fclib_a388184c668b9ee2() {
  BOOL result;
  intgo _swig_go_result;
  
  
  result = (BOOL)Encode_AllDataCollected();
  _swig_go_result = result; 
  return _swig_go_result;
}


intgo _wrap_Encode_CollectSamples_fclib_a388184c668b9ee2(char *_swig_go_0, int *_swig_go_1) {
  BYTE *arg1 = (BYTE *) 0 ;
  ULONG *arg2 = (ULONG *) 0 ;
  BOOL result;
  intgo _swig_go_result;
  
  arg1 = *(BYTE **)&_swig_go_0; 
  arg2 = *(ULONG **)&_swig_go_1; 
  
  result = (BOOL)Encode_CollectSamples(arg1,arg2);
  _swig_go_result = result; 
  return _swig_go_result;
}


intgo _wrap_Encode_PushData_fclib_a388184c668b9ee2(char *_swig_go_0, int _swig_go_1) {
  BYTE *arg1 = (BYTE *) 0 ;
  ULONG arg2 ;
  BOOL result;
  intgo _swig_go_result;
  
  arg1 = *(BYTE **)&_swig_go_0; 
  arg2 = (ULONG)_swig_go_1; 
  
  result = (BOOL)Encode_PushData((uint8_t const *)arg1,arg2);
  _swig_go_result = result; 
  return _swig_go_result;
}


CallbackShim *_wrap__swig_NewDirectorCallbackShimCallbackShim_fclib_a388184c668b9ee2(intgo _swig_go_0) {
  int arg1 ;
  CallbackShim *result = 0 ;
  CallbackShim *_swig_go_result;
  
  arg1 = (int)_swig_go_0; 
  
  result = new SwigDirector_CallbackShim(arg1);
  *(CallbackShim **)&_swig_go_result = (CallbackShim *)result; 
  return _swig_go_result;
}


void _wrap_DeleteDirectorCallbackShim_fclib_a388184c668b9ee2(CallbackShim *_swig_go_0) {
  CallbackShim *arg1 = (CallbackShim *) 0 ;
  
  arg1 = *(CallbackShim **)&_swig_go_0; 
  
  delete arg1;
  
}


void _wrap__swig_DirectorCallbackShim_upcall_Run_fclib_a388184c668b9ee2(SwigDirector_CallbackShim *_swig_go_0) {
  SwigDirector_CallbackShim *arg1 = (SwigDirector_CallbackShim *) 0 ;
  
  arg1 = *(SwigDirector_CallbackShim **)&_swig_go_0; 
  
  arg1->_swig_upcall_run();
  
}


void _wrap_delete_CallbackShim_fclib_a388184c668b9ee2(CallbackShim *_swig_go_0) {
  CallbackShim *arg1 = (CallbackShim *) 0 ;
  
  arg1 = *(CallbackShim **)&_swig_go_0; 
  
  delete arg1;
  
}


void _wrap_CallbackShim_run_fclib_a388184c668b9ee2(CallbackShim *_swig_go_0) {
  CallbackShim *arg1 = (CallbackShim *) 0 ;
  
  arg1 = *(CallbackShim **)&_swig_go_0; 
  
  (arg1)->run();
  
}


CallbackShim *_wrap_new_CallbackShim_fclib_a388184c668b9ee2() {
  CallbackShim *result = 0 ;
  CallbackShim *_swig_go_result;
  
  
  result = (CallbackShim *)new CallbackShim();
  *(CallbackShim **)&_swig_go_result = (CallbackShim *)result; 
  return _swig_go_result;
}


void _wrap_g_shimInstance_set_fclib_a388184c668b9ee2(CallbackShim *_swig_go_0) {
  CallbackShim *arg1 = (CallbackShim *) 0 ;
  
  arg1 = *(CallbackShim **)&_swig_go_0; 
  
  g_shimInstance = arg1;
  
}


CallbackShim *_wrap_g_shimInstance_get_fclib_a388184c668b9ee2() {
  CallbackShim *result = 0 ;
  CallbackShim *_swig_go_result;
  
  
  result = (CallbackShim *)g_shimInstance;
  *(CallbackShim **)&_swig_go_result = (CallbackShim *)result; 
  return _swig_go_result;
}


void _wrap_OnDataReadyShim_fclib_a388184c668b9ee2() {
  OnDataReadyShim();
  
}


void _wrap_CleanupCallbackShim_fclib_a388184c668b9ee2() {
  CleanupCallbackShim();
  
}


void _wrap_InitialiseCallbackShim_fclib_a388184c668b9ee2(CallbackShim *_swig_go_0) {
  CallbackShim *arg1 = (CallbackShim *) 0 ;
  
  arg1 = *(CallbackShim **)&_swig_go_0; 
  
  InitialiseCallbackShim(arg1);
  
}


void _wrap_RunCallback_fclib_a388184c668b9ee2() {
  RunCallback();
  
}


#ifdef __cplusplus
}
#endif

