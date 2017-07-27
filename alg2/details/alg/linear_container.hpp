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
  typedef R& reference;

  template <typename ... Rs> ALG2_CXX11_CONSTEXPR linear_container(Rs... xs)
  : container<N, R>{ xs... }
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
  ALG2_CXX11_CONSTEXPR reference at(size_t idx) const
  {
    return this->m_data[idx];
  }
  ALG2_CXX14_CONSTEXPR reference at(size_t idx)
  {
    return this->m_data[idx];
  }

  ALG2_CXX11_CONSTEXPR bool operator ==(const A& v) const
  {
    return partial_equality(v);
  }
  ALG2_CXX11_CONSTEXPR bool operator !=(const A& v) const
  {
    return !partial_equality(v);
  }

  ALG2_CXX14_CONSTEXPR A operator =(const A& v)
  {
    return assign(v, Utility::make_index_sequence<N>());
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

  ALG2_CXX14_CONSTEXPR A operator +=(const A& v)
  {
    return (*this = static_cast<linear_container>(*this + v));
  }
  ALG2_CXX14_CONSTEXPR A operator -=(const A& v)
  {
    return (*this = static_cast<linear_container>(*this + (-v)));
  }
  ALG2_CXX14_CONSTEXPR A operator *=(const R t)
  {
    return (*this = static_cast<linear_container>(*this * t));
  }
  ALG2_CXX14_CONSTEXPR A operator /=(const R t)
  {
    return (*this = static_cast<linear_container>(*this * ((R)1/t)));
  }

private:
  ALG2_CXX11_CONSTEXPR bool partial_equality(const A& v, size_t i = 0) const
  {
    return
    (
      (i < N)
      ?
      (
        (this->m_data[i] == v[i])
        ?
        partial_equality(v, i+1)
        :
        false
      )
      :
      true
     );
  }

  template <size_t ... Idx>
  ALG2_CXX14_CONSTEXPR A assign(const A& v, Utility::index_sequence<Idx...>)
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

/*
#ifndef LINEAR_CONTAINER
#define LINEAR_CONTAINER
#endif
  namespace Linear
  {
    template <size_t M, size_t N, typename R, class A> struct container : Alg2::container<M*N, R>
    {
      typedef R value_type;
      typedef R* iterator;
      typedef R& value_reference;
      typedef A Matrix;
      
      ALG2_CXX11_CONSTEXPR container()
      : Alg2::container<M*N, value_type>{}
      {
      }
      template <typename ... Rs> ALG2_CXX11_CONSTEXPR container(Rs... xs)
      : Alg2::container<M*N, value_type>{ xs... }
      {
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
    };

    template <size_t M, size_t N, typename R> class double_variable_map
    : public Linear::container<M, N, R, double_variable_map<M, N, R> >
    {
      typedef double_variable_map<M, N, R> self_type;
      typedef R value_type;

    public:
      ALG2_CXX11_CONSTEXPR double_variable_map()
      : Linear::container<M, N, R, self_type>{}
      {
      }
      template <typename ... Rs>
      ALG2_CXX11_CONSTEXPR double_variable_map<M, N, R>(Rs... xs)
      : Linear::container<M, N, R, self_type>{ xs... }
      {
      }
    };

    template <size_t N, typename R> class single_variable_map
    : public double_variable_map<N, 1, R>
    {
      typedef single_variable_map<N, R> self_type;
      typedef R value_type;

    public:
      ALG2_CXX11_CONSTEXPR single_variable_map()
      : double_variable_map<N, 1, R>{}
      {
      }
      template <typename ... Rs>
      ALG2_CXX11_CONSTEXPR single_variable_map(Rs... xs)
      : double_variable_map<N, 1, R>{ xs... }
      {
      }
    };

    namespace Trans
    {

      template <size_t M, size_t N, typename R, size_t ... Idx>
      inline ALG2_CXX11_CONSTEXPR double_variable_map<1, N, R> row(const double_variable_map<M, N, R>& m, size_t idx, Utility::index_sequence<Idx...>)
      {
        return { m[idx*M + Idx]... };
      }
      template <size_t M, size_t N, typename R, size_t ... Idx>
      inline ALG2_CXX11_CONSTEXPR double_variable_map<M, 1, R> col(const double_variable_map<M, N, R>& m, size_t idx, Utility::index_sequence<Idx...>)
      {
        return { m[idx + Idx*N]... };
      }

      template <size_t M, size_t N, typename R, size_t ... Idx>
      inline ALG2_CXX11_CONSTEXPR
      double_variable_map<N, M, R>
      transpose(const double_variable_map<M, N, R>& m, Utility::index_sequence<Idx...>)
      {
        return { m[(Idx%M)*N + (Idx/M)]... };
      }

    }

    template <size_t M, size_t N, typename R>
    inline ALG2_CXX11_CONSTEXPR double_variable_map<1, N, R> row(const double_variable_map<M, N, R> m, size_t idx)
    {
      return Trans::row(m, idx, Utility::make_index_sequence<N>());
    }
    template <size_t M, size_t N, typename R>
    inline ALG2_CXX11_CONSTEXPR double_variable_map<M, 1, R> col(const double_variable_map<M, N, R> m, size_t idx)
    {
      return Trans::col(m, idx, Utility::make_index_sequence<M>());
    }

    template <size_t M, size_t N, typename R>
    inline ALG2_CXX11_CONSTEXPR double_variable_map<N, M, R> transpose(const double_variable_map<M, N, R>& m)
    {
      return Trans::transpose(m, Utility::make_index_sequence<M*N>());
    }

    template <size_t N, typename R>
    inline ALG2_CXX11_CONSTEXPR
    R
    pseudo_inner_prod(const double_variable_map<1, N, R>& lhs, const double_variable_map<N, 1, R>& rhs, size_t i = 0)
    {
      return (i < N)? pseudo_inner_prod(lhs, rhs, i+1) + lhs[i]*rhs[i] : 0;
    }

    template <size_t M, size_t N, typename R, class A, size_t ... Idx>
    inline ALG2_CXX11_CONSTEXPR
    double_variable_map<M, N, R>
    add(const double_variable_map<M, N, R>& lhs, const double_variable_map<M, N, R>& rhs, Utility::index_sequence<Idx...> = Utility::make_index_sequence<M*N>())
    {
      return { lhs[Idx] + rhs[Idx]... };
    }
    template <size_t L, size_t M, size_t N, typename R, size_t ... Idx>
    inline ALG2_CXX11_CONSTEXPR
    double_variable_map<L, N, R>
    multiply(const double_variable_map<L, M, R>& lhs, const double_variable_map<M, N, R>& rhs, Utility::index_sequence<Idx...>)
    {
      return { pseudo_inner_prod(row(lhs, Idx/N), col(rhs, Idx%N))... };
    }
    template <size_t M, size_t N, typename R, class A, size_t ... Idx>
    inline ALG2_CXX11_CONSTEXPR
    container<M, N, R, A>
    multiply(const R t, const container<M, N, R, A>& m, Utility::index_sequence<Idx...> = Utility::make_index_sequence<M*N>())
    {
      return A{ t*m[Idx]... };
    }

    template <size_t M, size_t N, typename R, class A>
    inline ALG2_CXX11_CONSTEXPR A operator +(const container<M, N, R, A>& lhs, const container<M, N, R, A>& rhs)
    {
      return add(lhs, rhs);
    }
    template <size_t L, size_t M, size_t N, typename R, size_t ... Idx>
    inline ALG2_CXX11_CONSTEXPR double_variable_map<L, N, R> operator *(const double_variable_map<L, M, R>& lhs, const double_variable_map<M, N, R>& rhs)
    {
      return multiply(lhs, rhs, Utility::make_index_sequence<L*N>());
    }
    template <size_t M, size_t N, typename R, class A>
    inline ALG2_CXX11_CONSTEXPR A operator *(const R t, const A& m)
    {
      return multiply(t, m);
    }
  }
  using Linear::operator +;
  //using Linear::operator *;
*/
} // end of namespace Alg2


#endif // ALG2_LINEAR_CONTAINER_HPP
