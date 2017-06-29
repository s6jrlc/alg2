//
// utility: constant.hpp
//

#ifndef ALG2_UTILITY_CONSTANT_HPP
#define ALG2_UTILITY_CONSTANT_HPP

#include<type_traits>


namespace Alg2
{


namespace Utility
{


template <typename R> inline ALG2_CXX11_CONSTEXPR R PI()
{
  return static_cast<R>(3.14159265358979323846264338327950288419716939937510);
}
template <typename R> inline ALG2_CXX11_CONSTEXPR R E()
{
  return static_cast<R>(2.71828182845904523536028747135266249775724709369995);
}

template <typename R> inline ALG2_CXX11_CONSTEXPR R Epsilon();
template <> inline ALG2_CXX11_CONSTEXPR float Epsilon<float>()
{
  return 1.e-38f;
}
template <> inline ALG2_CXX11_CONSTEXPR double Epsilon<double>()
{
  return 1.e-308;
}
template <> inline ALG2_CXX11_CONSTEXPR long double Epsilon<long double>()
{
  return 1.e-4932L;
}


} // end of namespace Utility


} // end of namespace Alg2


#endif
