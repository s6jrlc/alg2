//
// utility: constant.hpp
//

#ifndef ALG2_UTILITY_CONSTANT_HPP
#define ALG2_UTILITY_CONSTANT_HPP

#include"enable_if.hpp"


namespace Alg2
{

  namespace Util
  {

    template <
      typename R,
      typename Util::enable_if<std::is_arithmetic<R>::value>::type = Util::enabler
    >
    inline ALG2_CXX11_CONSTEXPR R PI()
    {
      return static_cast<R>(3.14159265358979323846264338327950288419716939937510L);
    }

    template <
      typename R,
      typename Util::enable_if<std::is_arithmetic<R>::value>::type = Util::enabler
    >
    inline ALG2_CXX11_CONSTEXPR R E()
    {
      return static_cast<R>(2.71828182845904523536028747135266249775724709369995L);
    }
    
    template <
      typename R,
      typename Util::enable_if<std::is_same<R, float>::value>::type = Util::enabler
    >
    inline ALG2_CXX11_CONSTEXPR float Epsilon()
    {
      return 1.e-38f;
    }
    template <
      typename R,
      typename Util::enable_if<std::is_same<R, double>::value>::type = Util::enabler
    >
    inline ALG2_CXX11_CONSTEXPR double Epsilon()
    {
      return 1.e-308;
    }
    template <
      typename R,
      typename Util::enable_if<std::is_same<R, long double>::value>::type = Util::enabler
    >
    inline ALG2_CXX11_CONSTEXPR long double Epsilon()
    {
      return 1.e-4932L;
    }

  } // end of namespace Util

} // end of namespace Alg2


#endif // ALG2_UTILITY_CONSTANT_HPP
