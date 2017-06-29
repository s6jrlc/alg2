//
// details: ln.hpp
//

namespace Alg2
{
  
  
namespace Math
{
    
    
#ifdef ALG2_CXX14
template <typename R>
inline ALG2_CXX14_CONSTEXPR R ln_1_plus(const R x, R xs, size_t i, const size_t n)
{
  R ln_x_1__n = 0;
  while (true)
  {
    ln_x_1__n += ((i%2 == 0)? 1. : -1.)*xs/static_cast<R>(i);
    if (i >= n)
    {
      break;
    }
    xs *= x;
    ++i;
  }
  return ln_x_1__n;
}
#else
template <typename R>
inline ALG2_CXX11_CONSTEXPR R ln_1_plus(const R x, R xs, size_t i, const size_t n)
{
  return ((i < n)? ln_1_plus(x, xs*x, i+1, n) : 0) + ((i%2 == 0)? 1. : -1.)*xs/static_cast<R>(i);
}
#endif


template <typename R> inline ALG2_CXX11_CONSTEXPR R ln(const R x)
{
  static_assert(std::is_arithmetic<R>::value, "invalid type for Alg::Math::logarithm_function");
  return (x < 1.)? ln_1_plus(x - 1., x - 1., 1, 250) : ln_1_plus(1./x - 1., 1./x - 1., 1, 250);
}

template <typename R> inline ALG2_CXX11_CONSTEXPR R log2(const R x)
{
  return ln(x)/ln((R)2);
}

template <typename R> inline ALG2_CXX11_CONSTEXPR R log10(const R x)
{
  return ln(x)/ln((R)10);
}

template <typename R> inline ALG2_CXX11_CONSTEXPR R log(const R a, const R x)
{
  return ln(x)/ln(a);
}

} // end of namespace Math


} // end of namespace Alg2
