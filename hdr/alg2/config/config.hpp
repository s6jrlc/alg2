//
// alg2: config.hpp
//

#ifndef ALG2_CONFIG_HPP
#define ALG2_CONFIG_HPP

#if       (__cplusplus >= 201100L)
# define    ALG2_CXX11_OR_LATER
# if      (__cplusplus >= 201400L)
#  define   ALG2_CXX14_OR_LATER
#  if     (__cplusplus >= 201700L)
#   define  ALG2_CXX17_OR_LATER
#   if    (__cplusplus >= 202000L)
#    define ALG2_CXX20_OR_LATER
#    define ALG2_CXX20
#   else  // 201700L < ALG2_CXX_VER <= 202000L
#    define ALG2_CXX17
#   endif
#  else   // 201400L < ALG2_CXX_VER <= 201700L
#   define  ALG2_CXX14
#  endif
# else    // 201100L < ALG2_CXX_VER <= 201400L
#  define   ALG2_CXX11
# endif
#endif

#ifdef __cpp_constexpr
# define    ALG2_CXX11_CONSTEXPR constexpr
# if   (__cpp_constexpr >= 201304)
#  define   ALG2_CXX14_CONSTEXPR constexpr
#  if  (__cpp_constexpr >= 201603)
#   define  ALG2_CXX17_CONSTEXPR constexpr
#   if (__cpp_constexpr >= 202002L)
#    define ALG2_CXX20_CONSTEXPR constexpr
#   endif
#  endif
# endif
#endif

#ifndef ALG2_CXX20_CONSTEXPR
# define ALG2_CXX20_CONSTEXPR
#endif
#ifndef ALG2_CXX17_CONSTEXPR
# define ALG2_CXX17_CONSTEXPR
#endif
#ifndef ALG2_CXX14_CONSTEXPR
# define ALG2_CXX14_CONSTEXPR
#endif
#ifndef ALG2_CXX11_CONSTEXPR
# define ALG2_CXX11_CONSTEXPR
#endif

#endif // ALG2_CONFIG_HPP
