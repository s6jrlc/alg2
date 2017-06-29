//
// details: quaternion.hpp
//

namespace Alg2
{


template <typename R> inline ALG2_CXX11_CONSTEXPR quaternion<R>::quaternion()
: container<4, R>{}
{
}
template <typename R> inline ALG2_CXX11_CONSTEXPR quaternion<R>::quaternion(R a, R b, R c, R d)
: container<4, R>{{a, b, c, d}}
{
}
template <typename R> inline ALG2_CXX11_CONSTEXPR quaternion<R>::quaternion(R x)
: container<4, R>{{x}}
{
}


template <typename R> inline ALG2_CXX11_CONSTEXPR R quaternion<R>::re() const
{
  return this->m_data[0];
}
template <typename R> inline ALG2_CXX11_CONSTEXPR R quaternion<R>::im1() const
{
  return this->m_data[1];
}
template <typename R> inline ALG2_CXX11_CONSTEXPR R quaternion<R>::im2() const
{
  return this->m_data[2];
}
template <typename R> inline ALG2_CXX11_CONSTEXPR R quaternion<R>::im3() const
{
  return this->m_data[3];
}


template <typename R> inline ALG2_CXX11_CONSTEXPR R quaternion<R>::norm() const
{
  return Math::sqrt(re()*re() + im1()*im1() + im2()*im2() + im3()*im3());
}

template <typename R> inline ALG2_CXX11_CONSTEXPR quaternion<R> quaternion<R>::conjugate(const quaternion& z) const
{
  return { re(), -im1(), -im2(), -im3() };
}


template <typename R> inline ALG2_CXX11_CONSTEXPR quaternion<R> quaternion<R>::operator +() const
{
  return *this;
}
template <typename R> inline ALG2_CXX11_CONSTEXPR quaternion<R> quaternion<R>::operator -() const
{
  return { -re(), -im1(), -im2(), -im3() };
}

template <typename R> inline ALG2_CXX11_CONSTEXPR quaternion<R> quaternion<R>::operator *(const quaternion& z) const
{
  return {
    re()*z.re() - im1()*z.im1() - im2()*z.im2() - im3()*z.im3(),
    re()*z.im1() + im1()*z.re() + im2()*z.im3() - im3()*z.im2(),
    re()*z.im2() + im2()*z.re() - im1()*z.im3() + im3()*z.im1(),
    re()*z.im3() + im3()*z.re() + im1()*z.im2() - im2()*z.im1(),
  };
}


}
