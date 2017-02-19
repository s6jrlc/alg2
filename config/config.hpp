//
// alg2 : config.hpp
//

#ifndef ALG2_CONFIG_HPP
#define ALG2_CONFIG_HPP

#if __cplusplus >= 201402L
# define ALG2_CXX14
#elif __cplusplus >= 201103L
# define ALG2_CXX11
#endif

#ifdef __cpp_constexpr
# define ALG2_CXX11_CONSTEXPR constexpr
# if (__cpp_constexpr >= 201304)
#  define ALG2_CXX14_CONSTEXPR constexpr
# else
#  define ALG2_CXX14_CONSTEXPR
# endif
#else
# define ALG2_CXX11_CONSTEXPR
# define ALG2_CXX14_CONSTEXPR
#endif

#endif
