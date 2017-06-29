//
// details: euclidean_container.hpp
//

#ifndef ALG2_EUCLIDEAN_CONTAINER_HPP
#define ALG2_EUCLIDEAN_CONTAINER_HPP

#include"linear_container.hpp"


namespace Alg2
{


template <size_t N, typename R, typename A> struct Euclidean_container
  : public linear_container<N, R, A>
{
  ALG2_CXX11_CONSTEXPR Euclidean_container()
  : linear_container<N, R, A>{}
  {
  }
  template <typename ... Rs> ALG2_CXX11_CONSTEXPR Euclidean_container(Rs... xs)
  : linear_container<N, R, A>{ xs... }
  {
  }
  template <size_t ... Idx> ALG2_CXX11_CONSTEXPR Euclidean_container(const A& v, Utility::make_index_sequence<N>)
  : linear_container<N, R, A>{ v[Idx]... }
  {
  }
};
template <typename R, typename A> struct Euclidean_container<2, R, A>
  : public linear_container<2, R, A>
{
  ALG2_CXX11_CONSTEXPR Euclidean_container()
  : linear_container<2, R, A>{}
  {
  }
  template <typename ... Rs> ALG2_CXX11_CONSTEXPR Euclidean_container(Rs... xs)
  : linear_container<2, R, A>{ xs... }
  {
  }
  ALG2_CXX11_CONSTEXPR Euclidean_container(const R x, const R y)
  : linear_container<2, R, A>{x, y}
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
};
template <typename R, typename A> struct Euclidean_container<3, R, A>
  : public linear_container<3, R, A>
{
  ALG2_CXX11_CONSTEXPR Euclidean_container()
  : linear_container<3, R, A>{}
  {
  }
  template <typename ... Rs> ALG2_CXX11_CONSTEXPR Euclidean_container(Rs... xs)
  : linear_container<3, R, A>{ xs... }
  {
  }
  ALG2_CXX11_CONSTEXPR Euclidean_container(const R x, const R y, const R z)
  : linear_container<3, R, A>{x, y, z}
  {
  }

  ALG2_CXX11_CONSTEXPR A operator *(const A& v) const
  {
    return { y()*v.z() - z()*v.y(), z()*v.x() - x()*v.z(), x()*v.y() - y()*v.x() };
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
};
template <typename R, typename A> struct Euclidean_container<4, R, A>
  : public linear_container<4, R, A>
{
  ALG2_CXX11_CONSTEXPR Euclidean_container()
  : linear_container<4, R, A>{}
  {
  }
  template <typename ... Rs> ALG2_CXX11_CONSTEXPR Euclidean_container(Rs... xs)
  : linear_container<4, R, A>{ xs... }
  {
  }
  ALG2_CXX11_CONSTEXPR Euclidean_container(const R x, const R y, const R z, const R w)
  : linear_container<4, R, A>{x, y, z, w}
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
};
template <typename R, typename A> struct Euclidean_container<7, R, A>
  : public linear_container<7, R, A>
{
  ALG2_CXX11_CONSTEXPR Euclidean_container()
  : linear_container<7, R, A>{}
  {
  }
  template <typename ... Rs> ALG2_CXX11_CONSTEXPR Euclidean_container(Rs... xs)
  : linear_container<7, R, A>{xs...}
  {
  }

  ALG2_CXX11_CONSTEXPR A operator *(const A& v) const
  {
    return {
      (*this)[2]*v[3]-(*this)[3]*v[2]-(*this)[4]*v[5]+(*this)[5]*v[4]-(*this)[6]*v[7]+(*this)[7]*v[6],
      (*this)[3]*v[1]-(*this)[1]*v[3]-(*this)[4]*v[6]+(*this)[5]*v[7]-(*this)[7]*v[5]+(*this)[6]*v[4],
      (*this)[1]*v[2]-(*this)[2]*v[1]-(*this)[4]*v[7]+(*this)[7]*v[4]-(*this)[5]*v[6]+(*this)[6]*v[5],
      (*this)[1]*v[5]-(*this)[5]*v[1]-(*this)[6]*v[2]+(*this)[2]*v[6]-(*this)[7]*v[3]+(*this)[3]*v[7],
      (*this)[4]*v[1]-(*this)[1]*v[4]-(*this)[6]*v[3]+(*this)[3]*v[6]-(*this)[2]*v[7]+(*this)[7]*v[2],
      (*this)[1]*v[7]-(*this)[7]*v[1]-(*this)[2]*v[4]+(*this)[4]*v[2]-(*this)[3]*v[5]+(*this)[5]*v[3],
      (*this)[6]*v[1]-(*this)[1]*v[6]-(*this)[5]*v[2]+(*this)[2]*v[5]-(*this)[3]*v[4]+(*this)[4]*v[3],
    };
  }
};


template <size_t N, typename R> class Hoge
  : public Euclidean_container<N, R, Hoge<N, R> >
  {
  public:
    template <typename ... Rs> ALG2_CXX11_CONSTEXPR Hoge(Rs... xs)
    : Euclidean_container<N, R, Hoge<N, R> >{xs...}
    {
    }
  };
} // end of namespace Alg2


#endif // ALG2_EUCLIDEAN_CONTAINER_HPP
