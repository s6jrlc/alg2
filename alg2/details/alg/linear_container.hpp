//
// details: linear_container.hpp
//


#ifndef ALG2_LINEAR_CONTAINER_HPP
#define ALG2_LINEAR_CONTAINER_HPP


#include"container.hpp"


namespace Alg2
{


template <size_t N, typename R, class A> struct linear_container
  : public container<N, R>
{
  typedef R value_type;
  typedef R* iterator;
  typedef R& value_reference;

  template <typename ... Rs> ALG2_CXX11_CONSTEXPR linear_container(Rs... xs)
  : container<N, R>{{ xs... }}
  {
  }
  template <size_t ... Idx> ALG2_CXX11_CONSTEXPR linear_container(const A& v, Utility::index_sequence<Idx...>)
  : container<N, R>{ v[Idx]... }
  {
  }

#ifndef ALG2_CXX11_OR_LATER
  ALG2_CXX11_CONSTEXPR operator bool() const
  {
    for (R datum : this->m_data)
    {
      if (datum != 0)
      {
        return true;
      }
    }
    return false;
  }
  ALG2_CXX11_CONSTEXPR bool operator !=(const A& v) const
  {
    for (size_t i=0; i<N; ++i)
    {
      if (this->m_data[i] != v.m_data[i])
      {
        return true;
      }
    }
    return false;
  }
  ALG2_CXX11_CONSTEXPR bool operator ==(const A& v) const
  {
    return !(*this != v);
  }

  ALG2_CXX11_CONSTEXPR A operator =(A& v)
  {
    for (size_t i=0; i<N; ++i)
    {
      this->m_data[i] = v.m_data[i];
    }
    return *this;
  }

  ALG2_CXX11_CONSTEXPR R norm2() const
  {
    return (*this, *this);
  }

  ALG2_CXX11_CONSTEXPR A operator +() const
  {
    return *this;
  }
  ALG2_CXX11_CONSTEXPR A operator -() const
  {
    A v;
    for (size_t i=0; i<N; ++i)
    {
      v.m_data[i] = -this->m_data[i];
    }
    return v;
  }

  ALG2_CXX11_CONSTEXPR A operator +(const A& v) const
  {
    A sum;
    for (size_t i=0; i<N; ++i)
    {
      sum.m_data[i] = this->m_data[i];
      sum.m_data[i] += v.m_data[i];
    }
    return sum;
  }
  ALG2_CXX11_CONSTEXPR A operator -(const A& v) const
  {
    A sub;
    for (size_t i=0; i<N; ++i)
    {
      sub.m_data[i] = this->m_data[i];
      sub.m_data[i] -= v.m_data[i];
    }
    return sub;
  }
  ALG2_CXX11_CONSTEXPR A operator *(const R t) const
  {
    A mul;
    for (size_t i=0; i<N; ++i)
    {
      mul.m_data[i] = this->m_data[i];
      mul.m_data[i] *= t;
    }
    return mul;
  }
  ALG2_CXX11_CONSTEXPR A operator /(const R t) const
  {
    return *this * ((R)1/t);
  }
  ALG2_CXX11_CONSTEXPR R operator ,(const A& v) const
  {
    R inner_production = 0;
    for (size_t i=0; i<N; ++i)
    {
      inner_production += this->m_data[i] * v.m_data[i];
    }
    return inner_production;
  }

  ALG2_CXX11_CONSTEXPR A operator +=(const A& v) const
  {
    for (size_t i=0; i<N; ++i)
    {
      this->m_data[i] += v.m_data[i];
    }
    return *this;
  }
  ALG2_CXX11_CONSTEXPR A operator -=(const A& v) const
  {
    for (size_t i=0; i<N; ++i)
    {
      this->m_data[i] -= v.m_data[i];
    }
    return *this;
  }
  ALG2_CXX11_CONSTEXPR A operator *=(const R t) const
  {
    for (size_t i=0; i<N; ++i)
    {
      this->m_data[i] *= t;
    }
    return *this;
  }
  ALG2_CXX11_CONSTEXPR A operator /=(const R t) const
  {
    return (*this *= (1./t));
  }
#else
  ALG2_CXX11_CONSTEXPR value_type operator ()(size_t idx) const
  {
    return this->m_data[idx];
  }
  ALG2_CXX11_CONSTEXPR value_reference at(size_t idx) const
  {
    return this->m_data[idx];
  }
  ALG2_CXX14_CONSTEXPR value_reference at(size_t idx)
  {
    return this->m_data[idx];
  }

  ALG2_CXX11_CONSTEXPR A operator =(const A& v) const
  {
    return assign(v, Utility::make_index_sequence<N>::type());
  }

  ALG2_CXX11_CONSTEXPR A operator +() const
  {
    return *this;
  }
  ALG2_CXX11_CONSTEXPR A operator -() const
  {
    return negate(Utility::make_index_sequence<N>());
  }
  ALG2_CXX11_CONSTEXPR A operator +(const A& v) const
  {
    return add(v, Utility::make_index_sequence<N>());
  }
  ALG2_CXX11_CONSTEXPR A operator -(const A& v) const
  {
    return add(-v, Utility::make_index_sequence<N>());
  }
  ALG2_CXX11_CONSTEXPR A operator *(const R t) const
  {
    return multiply(t, Utility::make_index_sequence<N>());
  }
  ALG2_CXX11_CONSTEXPR A operator /(const R t) const
  {
    return multiply((R)1/t, Utility::make_index_sequence<N>());
  }
  ALG2_CXX11_CONSTEXPR R operator ,(const A& v) const
  {
    return partial_inner_production(v);
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
  ALG2_CXX11_CONSTEXPR R partial_inner_production(const A& v, size_t i = 0) const
  {
    return (i < N)? partial_inner_production(v, i + 1) + this->m_data[i] * v[i] : 0;
  }
#endif
};


} // end of namespace Alg2


#endif // ALG2_LINEAR_CONTAINER_HPP
