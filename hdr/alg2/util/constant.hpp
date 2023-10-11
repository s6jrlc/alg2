//
// utility: constant.hpp
//

#ifndef ALG2_UTILITY_CONSTANT_HPP
#define ALG2_UTILITY_CONSTANT_HPP

#include"traits.hpp"
#if defined(ALG2_CXX20_OR_LATER)
# include<numbers>
#elif defined(ALG2_CXX11_OR_LATER)
# include"enable_if.hpp"
#endif
#if defined(ALG2_USE_UNIQUE_LIMITS)
# include<cfloat>
#else
# include<limits>
#endif

#if !defined(ALG2_CXX20_OR_LATER)
# define ALG2_CONSTANT_MACRO_PI 3.14159265358979323846264338327950288419716939937510L
# define ALG2_CONSTANT_MACRO_E  2.71828182845904523536028747135266249775724709369995L
#endif

namespace Alg2
{

  namespace Util
  {
#if defined(ALG2_CXX20_OR_LATER)
    template <floating_point R> inline ALG2_CXX20_CONSTEXPR R PI()
    {
      return std::numbers::pi_v<R>;
    }
    template <floating_point R> inline ALG2_CXX20_CONSTEXPR R Pi = std::numbers::pi_v<R>;
#else
    template <
      typename R,
      typename Util::enable_if<Util::is_floating_point<R>::value>::type = Util::enabler
    >
    inline ALG2_CXX11_CONSTEXPR R PI()
    {
      return static_cast<R>(ALG2_CONSTANT_MACRO_PI);
    }
# if defined(ALG2_CXX17)
    template <typename R> inline ALG2_CXX17_CONSTEXPR R Pi = PI<R>();
# endif
#endif
#if defined(ALG2_CXX20_OR_LATER)
    template <floating_point R> inline ALG2_CXX20_CONSTEXPR R E()
    {
      return std::numbers::e_v<R>;
    }
#else
    template <
      typename R,
      typename Util::enable_if<Util::is_floating_point<R>::value>::type = Util::enabler
    >
    inline ALG2_CXX11_CONSTEXPR R E()
    {
      return static_cast<R>(ALG2_CONSTANT_MACRO_E);
    }
# if defined(ALG2_CXX17)
    template <typename R> inline ALG2_CXX17_CONSTEXPR R e = E<R>();
# endif
#endif
  
#if defined(ALG2_USE_STD_MACHINE_EPSILON)

# if defined(ALG2_CXX11_OR_LATER)
    template <typename R> using Epsilon = std::numeric_limits<R>::epsilon();
# else
    template <typename R> inline R Epsilon()
    {
      return std::numeric_limits<R>::epsilon();
    }
# endif

#elif defined(ALG2_USE_UNIQUE_EPSILON)
    template <
      typename R,
      typename Util::enable_if<Util::is_same<R, float>::value>::type = Util::enabler
    >
    inline ALG2_CXX11_CONSTEXPR float Epsilon()
    {
      return 1.e-38f;
    }
    template <
      typename R,
      typename Util::enable_if<Util::is_same<R, double>::value>::type = Util::enabler
    >
    inline ALG2_CXX11_CONSTEXPR double Epsilon()
    {
      return 1.e-308;
    }
    template <
      typename R,
      typename Util::enable_if<Util::is_same<R, long double>::value>::type = Util::enabler
    >
    inline ALG2_CXX11_CONSTEXPR long double Epsilon()
    {
      return 1.e-4932L;
    }
#else
    template <typename R> inline ALG2_CXX11_CONSTEXPR R Epsilon()
    {
      return std::numeric_limits<R>::min() * 1.0e8;
    }
#endif
  } // end of namespace Util

} // end of namespace Alg2

#ifdef ALG2_CONSTANT_MACRO_PI
# undef ALG2_CONSTANT_MACRO_PI
#endif
#ifdef ALG2_CONSTANT_MACRO_E
# undef ALG2_CONSTANT_MACRO_E
#endif

#endif // ALG2_UTILITY_CONSTANT_HPP
