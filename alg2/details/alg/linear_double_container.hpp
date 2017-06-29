//
// linear_double_container.hpp
//



#ifndef ALG2_LINEAR_DOUBLE_CONTAINER_HPP
#define ALG2_LINEAR_DOUBLE_CONTAINER_HPP


#include"container.hpp"


namespace Alg2
{


template <size_t M, size_t N, typename R, class A> struct linear_double_container
  : public container<M*N, R>
{
  typedef R value_type;
  typedef R* iterator;
  typedef R& value_reference;

  ALG2_CXX11_CONSTEXPR linear_double_container()
  : container<M*N, R>{}
  {
  }
  template <typename ... Rs> ALG2_CXX11_CONSTEXPR linear_double_container(Rs... xs)
  : container<M*N, R>{ xs... }
  {
  }

  ALG2_CXX11_CONSTEXPR size_t row_size() const
  {
    return M;
  }
  ALG2_CXX11_CONSTEXPR size_t col_size() const
  {
    return N;
  }
  ALG2_CXX11_CONSTEXPR value_type operator ()(size_t i, size_t j) const
  {
    return this->m_data[i*N+j];
  }
  ALG2_CXX11_CONSTEXPR value_reference at(size_t i, size_t j) const
  {
    return this->m_data[i*N+j];
  }
  ALG2_CXX14_CONSTEXPR value_reference at(size_t i, size_t j)
  {
    return this->m_data[i*N+j];
  }

  ALG2_CXX11_CONSTEXPR A operator =(const A& m) const
  {
    return assign(m, Utility::make_index_sequence<M*N>());
  }
  
  ALG2_CXX11_CONSTEXPR A operator +() const
  {
    return *this;
  }
  ALG2_CXX11_CONSTEXPR A operator -() const
  {
    return negate(Utility::make_index_sequence<M*N>());
  }
  ALG2_CXX11_CONSTEXPR A operator +(const A& m) const
  {
    return add(m, Utility::make_index_sequence<M*N>());
  }
  ALG2_CXX11_CONSTEXPR A operator -(const A& m) const
  {
    return add(-m, Utility::make_index_sequence<M*N>());
  }
  ALG2_CXX11_CONSTEXPR A operator *(const R t) const
  {
    return multiply(t, Utility::make_index_sequence<M*N>());
  }
  ALG2_CXX11_CONSTEXPR A operator /(const R t) const
  {
    return multiply((R)1/t, Utility::make_index_sequence<M*N>());
  }

private:
  template <size_t ... Idx>
  ALG2_CXX11_CONSTEXPR A assign(const A& v, Utility::index_sequence<Idx...>) const
  {
    return { this->m_data[Idx] = v[Idx] ... };
  }
  template <size_t ... Idx>
  ALG2_CXX11_CONSTEXPR A negate(Utility::index_sequence<Idx...>) const
  {
    return { -this->m_data[Idx] ... };
  }
  template <size_t ... Idx>
  ALG2_CXX11_CONSTEXPR A add(const A& v, Utility::index_sequence<Idx...>) const
  {
    return { this->m_data[Idx] + v[Idx] ... };
  }
  template <size_t ... Idx>
  ALG2_CXX11_CONSTEXPR A multiply(const R t, Utility::index_sequence<Idx...>) const
  {
    return { this->m_data[Idx] * t ... };
  }
  template <size_t ... Idx>
  ALG2_CXX11_CONSTEXPR A transpose(Utility::index_sequence<Idx...>) const
  {
    return { this->m_data[Idx]... };
  }
};


}


#endif // ALG2_LINEAR_DOUBLE_CONTAINER_HPP
