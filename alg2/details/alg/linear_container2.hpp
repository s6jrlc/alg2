//
// details: linear_container2.hpp
//


namespace Alg2
{


template <typename R, class A> struct linear_container<2, R, A>
  : public container<2, R>
{
public:
  ALG2_CXX11_CONSTEXPR linear_container() :
  container<2, R>{}
  {
  }
  ALG2_CXX11_CONSTEXPR linear_container(const R x, const R y) :
  container<2, R>{x, y}
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
    return (x() != v.x() || y() != v.y());
  }

  ALG2_CXX11_CONSTEXPR A operator =(const A& v) const
  {
    return A(this->m_data[0] = v.x(), this->m_data[1] = v.y());
  }

  ALG2_CXX11_CONSTEXPR A operator +() const
  {
    return *this;
  }
  ALG2_CXX11_CONSTEXPR A operator -() const
  {
    return A(-x(), -y());
  }

  ALG2_CXX11_CONSTEXPR A operator +(const A& v) const
  {
    return A(x()+v.x(), y()+v.y());
  }
  ALG2_CXX11_CONSTEXPR A operator -(const A& v) const
  {
    return *this + (-v);
  }
  ALG2_CXX11_CONSTEXPR A operator *(const R t) const
  {
    return A(t*x(), t*y());
  }
  ALG2_CXX11_CONSTEXPR A operator /(const R t) const
  {
    return *this * ((R)1/t);
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
