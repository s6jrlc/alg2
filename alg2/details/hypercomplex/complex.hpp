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
  inline ALG2_CXX11_CONSTEXPR complex<R> complex<R>::operator +(const complex& z) const
{
  return { re() + z.re(), im() + z.im() };
}
template <typename R>
  inline ALG2_CXX11_CONSTEXPR complex<R> complex<R>::operator -(const complex& z) const
{
  return { re() - z.re(), im() - z.im() };
}
template <typename R>
  inline ALG2_CXX11_CONSTEXPR complex<R> complex<R>::operator *(const complex& z) const
{
  return { re()*z.re() - im()*z.im(), re()*z.im() + im()*z.re() };
}
template <typename R>
  inline ALG2_CXX11_CONSTEXPR complex<R> complex<R>::operator /(const complex& z) const
{
  return { (re()*z.re()+im()*z.im())/z.norm2(), (im()*z.re() - re()*z.im())/norm2() };
}

template <typename R>
  inline ALG2_CXX14_CONSTEXPR complex<R> complex<R>::operator +=(const complex& z)
{
  return (*this = *this + z);
}
template <typename R>
  inline ALG2_CXX14_CONSTEXPR complex<R> complex<R>::operator -=(const complex& z)
{
  return (*this = *this - z);
}
template <typename R>
  inline ALG2_CXX14_CONSTEXPR complex<R> complex<R>::operator *=(const complex& z)
{
  return (*this = *this * z);
}
template <typename R>
  inline ALG2_CXX14_CONSTEXPR complex<R> complex<R>::operator /=(const complex& z)
{
  return (*this = *this / z);
}


}
