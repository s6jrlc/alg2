//
// alg2 : config.hpp
//

#ifndef ALG2_CONFIG_HPP
#define ALG2_CONFIG_HPP

#if (__cplusplus >= 201700L)
# define ALG2_CXX17
# define ALG2_CXX17_OR_LATER
# define ALG2_CXX14_OR_LATER
# define ALG2_CXX11_OR_LATER
#elif (__cplusplus >= 201400L)
# define ALG2_CXX14
# define ALG2_CXX14_OR_LATER
# define ALG2_CXX11_OR_LATER
#elif (__cplusplus >= 201100L)
# define ALG2_CXX11
# define ALG2_CXX11_OR_LATER
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
