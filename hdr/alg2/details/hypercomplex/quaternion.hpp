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
  
  
  template <typename R> inline ALG2_CXX11_CONSTEXPR R quaternion<R>::norm2() const
  {
    return re()*re() + im1()*im1() + im2()*im2() + im3()*im3();
  }
  template <typename R> inline ALG2_CXX11_CONSTEXPR R quaternion<R>::norm() const
  {
    return Math::sqrt(norm2());
  }
  
  template <typename R> inline ALG2_CXX11_CONSTEXPR quaternion<R> quaternion<R>::conjugate() const
  {
    return { re(), -im1(), -im2(), -im3() };
  }
  template <typename R> inline ALG2_CXX11_CONSTEXPR quaternion<R> quaternion<R>::normalize() const
  {
    return *this / norm();
  }
  template <typename R> inline ALG2_CXX11_CONSTEXPR quaternion<R> quaternion<R>::inverse() const
  {
    return conjugate() / norm();
  }
  
  template <typename R> inline ALG2_CXX11_CONSTEXPR quaternion<R> quaternion<R>::operator +() const
  {
    return *this;
  }
  template <typename R> inline ALG2_CXX11_CONSTEXPR quaternion<R> quaternion<R>::operator -() const
  {
    return { -re(), -im1(), -im2(), -im3() };
  }

  template <typename R>
  inline ALG2_CXX11_CONSTEXPR quaternion<R> quaternion<R>::rotation(const R theta)
  {
    return { Math::cos(theta), Math::sin(theta), Math::sin(theta), Math::sin(theta) };
  }

  template <typename R>
  inline ALG2_CXX11_CONSTEXPR quaternion<R> operator +(const quaternion<R>& lhs, const quaternion<R>& rhs)
  {
    return {
      lhs.re() + rhs.re(), lhs.im1() + rhs.im1(), lhs.im2() + rhs.im2(), lhs.im3() + rhs.im3()
    };
  }
  template <typename R>
  inline ALG2_CXX11_CONSTEXPR quaternion<R> operator -(const quaternion<R>& lhs, const quaternion<R>& rhs)
  {
    return {
      lhs.re() - rhs.re(), lhs.im1() - rhs.im1(), lhs.im2() - rhs.im2(), lhs.im3() - rhs.im3()
    };
  }
  template <typename R>
  inline ALG2_CXX11_CONSTEXPR quaternion<R> operator *(const quaternion<R>& z, const R t)
  {
    return { z.re()*t, z.im1()*t, z.im2()*t, z.im3()*t };
  }
  template <typename R>
  inline ALG2_CXX11_CONSTEXPR quaternion<R> operator /(const quaternion<R>& z, const R t)
  {
    return { z.re()/t, z.im1()/t, z.im2()/t, z.im3()/t };
  }
  
  template <typename R>
  inline ALG2_CXX11_CONSTEXPR quaternion<R> operator *(const quaternion<R>& lhs, const quaternion<R>& rhs)
  {
    return {
      lhs.re()*rhs.re() - lhs.im1()*rhs.im1() - lhs.im2()*rhs.im2() - lhs.im3()*rhs.im3(),
      lhs.re()*rhs.im1() + lhs.im1()*rhs.re() + lhs.im2()*rhs.im3() - lhs.im3()*rhs.im2(),
      lhs.re()*rhs.im2() + lhs.im2()*rhs.re() - lhs.im1()*rhs.im3() + lhs.im3()*rhs.im1(),
      lhs.re()*rhs.im3() + lhs.im3()*rhs.re() + lhs.im1()*rhs.im2() - lhs.im2()*rhs.im1()
    };
  }
  template <typename R>
  inline ALG2_CXX11_CONSTEXPR quaternion<R> operator /(const quaternion<R>& lhs, const quaternion<R>& rhs)
  {
    return lhs * rhs.inverse();
  }
  
  
}
