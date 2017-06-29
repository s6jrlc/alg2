//
// details: trig.hpp
//

namespace Alg2
{


namespace Math
{


namespace details
{

template <typename R> inline ALG2_CXX11_CONSTEXPR R sin3(R x)
{
  return (abs(x) < (R)1.e-8)? x : 3*sin3(x/3) - 4*Utility::cube(sin3(x/3));
}

} // end of namespace details

template <typename R> inline ALG2_CXX11_CONSTEXPR R sin(const R x)
{
  return
  (
    Utility::fmod(x, Utility::PI<R>()) >= (R)1.e-8
   &&
    Utility::PI<long double>() - Utility::fmod(x, Utility::PI<R>()) >= (R)1.e-8
   ?
   details::sin3(Utility::fmod(x, 2*Utility::PI<R>()))
   :
    (R)0
  );
}

template <typename R> inline ALG2_CXX11_CONSTEXPR R cos(const R x)
{
  return sin(x + Utility::PI<R>()/(R)2);
}

template <typename R> inline ALG2_CXX11_CONSTEXPR R tan(const R x)
{
  return sin(x) / cos(x);
}


} // end of namespace Math


} // end of namespace Alg2
