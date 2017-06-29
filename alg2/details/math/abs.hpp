//
// details: abs.hpp
//

namespace Alg2
{


namespace Math
{


template <typename R> inline ALG2_CXX11_CONSTEXPR R abs(const R x)
{
  static_assert(std::is_arithmetic<R>::value, "invalid type for Alg2::Math::abs");
  return (x >= (R)0)? x : -x;
}


} // end of namespace Math


} // end of namespace Alg2
