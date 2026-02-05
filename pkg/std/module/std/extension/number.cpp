module;
#include <cstddef>
#include <cstdint>
#if __has_include(<stdfloat>)
#include <stdfloat>
#endif

export module std:extension.number;
import           :core;

export
{
    using std::size_t;
    using std::ptrdiff_t;
    using std::nullptr_t;
    using std::max_align_t;
    constexpr auto NULL_ = NULL;

    #if defined(INT8_MIN) and defined(INT8_MAX) 
    using std::int8_t;
    #endif
    #if defined(INT16_MIN) and defined(INT16_MAX) 
    using std::int16_t;
    #endif
    #if defined(INT32_MIN) and defined(INT32_MAX) 
    using std::int32_t;
    #endif
    #if defined(INT64_MIN) and defined(INT64_MAX) 
    using std::int64_t;
    #endif
    using std::int_fast8_t;
    using std::int_fast16_t;
    using std::int_fast32_t;
    using std::int_fast64_t;
    using std::int_least8_t;
    using std::int_least16_t;
    using std::int_least32_t;
    using std::int_least64_t;
    using std::intmax_t;
    #if defined(INTPTR_MIN) and defined(INTPTR_MAX)
    using std::intptr_t;
    #endif 

    #if defined(UINT8_MAX)
    using std::uint8_t;
    #endif
    #if defined(UINT16_MAX)
    using std::uint16_t;
    #endif
    #if defined(UINT32_MAX)
    using std::uint32_t;
    #endif
    #if defined(UINT64_MAX)
    using std::uint64_t;
    #endif
    using std::uint_fast8_t;
    using std::uint_fast16_t;
    using std::uint_fast32_t;
    using std::uint_fast64_t;
    using std::uint_least8_t;
    using std::uint_least16_t;
    using std::uint_least32_t;
    using std::uint_least64_t;
    using std::uintmax_t;
    #if defined(UINTPTR_MAX)
    using std::uintptr_t;
    #endif 

    using float8_t = 
        std::conditional<sizeof(float      )==8,  float,
        std::conditional<sizeof(double     )==8,  double,
        std::conditional<sizeof(long double)==8,  long double,
                                                  void
                                                  >::type>::type>::type;
    using float16_t = 
        std::conditional<sizeof(float      )==16, float,
        std::conditional<sizeof(double     )==16, double,
        std::conditional<sizeof(long double)==16, long double,
                                                  #ifdef __STDCPP_FLOAT16_T__
                                                  std::float16_t
                                                  #else
                                                  void
                                                  #endif
                                                  >::type>::type>::type;
    using float32_t = 
        std::conditional<sizeof(float      )==32, float,
        std::conditional<sizeof(double     )==32, double,
        std::conditional<sizeof(long double)==32, long double,
                                                  #ifdef __STDCPP_FLOAT32_T__
                                                  std::float32_t
                                                  #else
                                                  void
                                                  #endif
                                                  >::type>::type>::type;
    using float64_t = 
        std::conditional<sizeof(float      )==64, float,
        std::conditional<sizeof(double     )==64, double,
        std::conditional<sizeof(long double)==64, long double,
                                                  #ifdef __STDCPP_FLOAT64_T__
                                                  std::float64_t
                                                  #else
                                                  void
                                                  #endif
                                                  >::type>::type>::type;
    using float128_t = 
        std::conditional<sizeof(float      )==128,float,
        std::conditional<sizeof(double     )==128,double,
        std::conditional<sizeof(long double)==128,long double,
                                                  #ifdef __STDCPP_FLOAT128_T__
                                                  std::float128_t
                                                  #else
                                                  void
                                                  #endif
                                                  >::type>::type>::type;
}

