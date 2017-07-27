//
// details: complex.hpp
//

namespace Alg2
{


template <typename R>
  inline ALG2_CXX11_CONSTEXPR complex<R>::complex()
: container<2, R>{}
{
}
template <typename R>
  inline ALG2_CXX11_CONSTEXPR complex<R>::complex(R a, R b)
: container<2, R>{{a, b}}
{
}
template <typename R>
  inline ALG2_CXX11_CONSTEXPR complex<R>::complex(R x)
: container<2, R>{{x}}
{
}


template <typename R>
  inline ALG2_CXX11_CONSTEXPR R complex<R>::re() const
{
  return this->m_data[0];
}
template <typename R>
  inline ALG2_CXX11_CONSTEXPR R complex<R>::im() const
{
  return this->m_data[1];
}


template <typename R>
  inline ALG2_CXX11_CONSTEXPR R complex<R>::norm2() const
{
  return re()*re() + im()*im();
}
template <typename R>
  inline ALG2_CXX11_CONSTEXPR R complex<R>::norm() const
{
  return Math::sqrt(norm2());
}

template <typename R>
  inline ALG2_CXX11_CONSTEXPR complex<R> complex<R>::normalize(const complex& z) const
{
  return { re()/norm(), im()/norm() };
}

template <typename R>
  inline ALG2_CXX11_CONSTEXPR complex<R> complex<R>::conjugate(const complex& z) const
{
  return { re(), -im() };
}


template <typename R>
inline ALG2_CXX11_CONSTEXPR complex<R> operator +(const complex<R>& lhs, const complex<R>& rhs)
{
  return { lhs.re() + rhs.re(), lhs.im() + rhs.im() };
}
template <typename R>
inline ALG2_CXX11_CONSTEXPR complex<R> operator -(const complex<R>& lhs, const complex<R>& rhs)
{
  return { lhs.re() - rhs.re(), lhs.im() - rhs.im() };
}
template <typename R>
inline ALG2_CXX11_CONSTEXPR complex<R> operator *(const complex<R>& z, const R t)
{
  return { z.re() * t, z.im() * t };
}
template <typename R>
inline ALG2_CXX11_CONSTEXPR complex<R> operator /(const complex<R>& z, const R t)
{
  return { z.re() / t, z.im() / t };
}

template <typename R>
inline ALG2_CXX11_CONSTEXPR complex<R> operator *(const complex<R>& lhs, const complex<R>& rhs)
{
  return { lhs.re()*rhs.re() - lhs.im()*rhs.im(), lhs.re()*rhs.im() + lhs.im()*rhs.re() };
}
template <typename R>
inline ALG2_CXX11_CONSTEXPR complex<R> operator /(const complex<R>& lhs, const complex<R>& rhs)
{
  return {
    (lhs.re()*rhs.re() + lhs.im()*rhs.im())/lhs.norm2(),
    (lhs.im()*rhs.re() - lhs.re()*rhs.im())/lhs.norm2()
  };
}


}
