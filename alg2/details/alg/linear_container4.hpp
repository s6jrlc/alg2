//
// details: linear_container4.hpp
//


namespace Alg2
{


template <typename R, class A> struct linear_container<4, R, A>
  : public container<4, R>
{
  ALG2_CXX11_CONSTEXPR linear_container() :
  container<4, R>{}
  {
  }
  ALG2_CXX11_CONSTEXPR linear_container(const R x, const R y, const R z, const R w) :
  container<4, R>{x, y, z, w}
  {
  }

  ALG2_CXX11_CONSTEXPR R x() const
  {
    return this->m_data[0];
  }
  ALG2_CXX11_CONSTEXPR R y() const
  {
    return this->m_data[1];
  }
  ALG2_CXX11_CONSTEXPR R z() const
  {
    return this->m_data[2];
  }
  ALG2_CXX11_CONSTEXPR R w() const
  {
    return this->m_data[3];
  }

  ALG2_CXX11_CONSTEXPR operator bool() const
  {
    return (*this != A());
  }
  ALG2_CXX11_CONSTEXPR bool operator ==(const A& v) const
  {
    return !(*this != v);
  }
  ALG2_CXX11_CONSTEXPR bool operator !=(const A& v) const
  {
    return (x() != v.x() || y() != v.y() || z() != v.z() || w() != v.w());
  }

  ALG2_CXX11_CONSTEXPR A operator =(const A& v) const
  {
    return A(this->m_data[0] = v.x(), this->m_data[1] = v.y(), this->m_data[2] = v.z(), this->m_data[3]);
  }

  ALG2_CXX11_CONSTEXPR A operator +() const
  {
    return *this;
  }
  ALG2_CXX11_CONSTEXPR A operator -() const
  {
    return A(-x(), -y(), -z(), -w());
  }

  ALG2_CXX11_CONSTEXPR A operator +(const A& v) const
  {
    return A(x()+v.x(), y()+v.y(), z()+v.z(), w()+v.w());
  }
  ALG2_CXX11_CONSTEXPR A operator -(const A& v) const
  {
    return *this + (-v);
  }
  ALG2_CXX11_CONSTEXPR A operator *(const R t) const
  {
    return A(t*x(), t*y(), t*z(), t*w());
  }
  ALG2_CXX11_CONSTEXPR A operator /(const R t) const
  {
    return *this * ((R)1/t);
  }
  ALG2_CXX11_CONSTEXPR R operator ,(const A& v) const
  {
    return x()*v.x() + y()*v.y() + z()*v.z() + w()*v.w();
  }

  ALG2_CXX11_CONSTEXPR A operator +=(const A& v) const
  {
    return (*this = static_cast<linear_container>(*this + v));
  }
  ALG2_CXX11_CONSTEXPR A operator -=(const A& v) const
  {
    return (*this = static_cast<linear_container>(*this + (-v)));
  }
  ALG2_CXX11_CONSTEXPR A operator *=(const R t) const
  {
    return (*this = static_cast<linear_container>(*this * t));
  }
  ALG2_CXX11_CONSTEXPR A operator /=(const R t) const
  {
    return (*this = static_cast<linear_container>(*this * ((R)1/t)));
  }
};


} // end of namespace Alg2
