//
// alg2: test.cpp
//

#include<iostream>
#include<alg2/vector.hpp>
#include<alg2/io.hpp>
#include<alg2/utility.hpp>

// --------------------------------------------------------------------------------------------
// test: utility implement
// --------------------------------------------------------------------------------------------

namespace
{
  using namespace Alg2::Util;

  template <size_t ... Idx> ALG2_CXX11_CONSTEXPR Alg2::vector<sizeof...(Idx), size_t> make_array(index_sequence<Idx...>) {
    return { Idx... };
  }
  void check_array() {
    for (auto a : make_array(make_index_sequence<15>())) {
      std::cout << a << ", " << a/3 << ", " << a%5 << std::endl;
    }
  }
}

// --------------------------------------------------------------------------------------------
// test: expression implement
// --------------------------------------------------------------------------------------------

namespace Alg2
{

  template <typename R, size_t N, class T, class index_sequence = Util::make_index_sequence<N> >
  struct Gcontainer;
  template <typename R, size_t N, class T, size_t ... Idx>
  struct Gcontainer<R, N, T, Util::index_sequence<Idx...> >
  : public Util::Expr::expression< Gcontainer<R, N, T> >
  {
    typedef Gcontainer<R, N, T> self_type;
    typedef Util::Expr::expression_reference<const self_type> const_closure_type;
    typedef Util::Expr::expression_reference<self_type> closure_type;
    typedef R value_type;
    typedef std::size_t size_type;
    typedef const R* const_pointer;
    typedef R* pointer;
    typedef const R* const_iterator;
    typedef R* iterator;
    typedef const R& const_reference;
    typedef R& reference;
    typedef value_type array_type[N];

  private:
    array_type data_;

  public:
    /*
     1. サンプル通りの実装にトライ
     template <class E> reference operator =(const expression<E>& expr);
     ↑
     template <class E> Gcontainer(const expression<R>& expr);
     ↑
     template <template <class, class> F, class E> reference assign(const expression<E>& expr);
     この方法でassignはすぐ上のコンストラクタの内部文として使われるのでアウト

     2. class templateの一部として宣言しておいたシーケンサを用いてコピーコンストラクタ、 コピー代入演算子を実装する(以下のLinear::containerも参考のこと)
     template <typename R, size_t N, size_t ... Idx struct container<R, N, index_sequence<Idx...> >::container(const container& c) : data_{ c[Idx]... } {}
     */
    ALG2_CXX11_CONSTEXPR Gcontainer()
    : data_{}
    {
    }
    template <
      typename ... Rs,
      typename Util::enabler_if<sizeof...(Rs) == N>::type = Util::enabler
    >
    ALG2_CXX11_CONSTEXPR Gcontainer(Rs... x_s)
    : data_{ x_s... }
    {
    }
    template <class E>
    ALG2_CXX11_CONSTEXPR Gcontainer(const Util::Expr::expression<E>& expr)
    : data_{ expr()[Idx]... }
    {
    }

    static ALG2_CXX11_CONSTEXPR size_t size()
    {
      return N;
    }
    static ALG2_CXX11_CONSTEXPR size_t data_size()
    {
      return sizeof(R)*N;
    }
    
    ALG2_CXX11_CONSTEXPR const_pointer data() const
    {
      return this->data_;
    }
    ALG2_CXX14_CONSTEXPR pointer data()
    {
      return this->data_;
    }
    
    ALG2_CXX11_CONSTEXPR const_iterator begin() const
    {
      return this->data_;
    }
    ALG2_CXX14_CONSTEXPR iterator begin()
    {
      return this->data_;
    }
    ALG2_CXX11_CONSTEXPR const_iterator end() const
    {
      return this->data_ + N;
    }
    ALG2_CXX14_CONSTEXPR iterator end()
    {
      return this->data_ + N;
    }
    
    ALG2_CXX11_CONSTEXPR value_type operator[](size_t idx) const
    {
      return this->data_[idx];
    }
    ALG2_CXX14_CONSTEXPR reference operator[](size_t idx)
    {
      return this->data_[idx];
    }

  private:
    template <template <class, class> class F, class AE>
    ALG2_CXX14_CONSTEXPR Gcontainer
    assign_helper(const Alg2::Util::Expr::expression<AE>& ae)
    {
      return { F<reference, typename AE::value_type>::apply(data_[Idx], ae()[Idx])... };
    }
  };
}


///// 代入演算(あるいは関数への引数化？)の際に主に使われてコピーによるコストを抑えるのがExpression Template

namespace Linear
{
  template <size_t V, size_t ... Vs> struct inf_prod
  {
    enum { value = V*inf_prod<Vs...>::value };
  };
  template <size_t V> struct inf_prod<V>
  {
    enum { value = V };
  };

  template <template <typename, size_t ...> class A, typename R, size_t ... Dims> struct Tensor_base
  : Alg2::container<inf_prod<Dims...>::value, R>
  {
    enum
    {
      rank = sizeof...(Dims),
      data_size = inf_prod<Dims...>::value * sizeof(R)
    };

    const size_t size_[rank] = { Dims... };

    ALG2_CXX11_CONSTEXPR size_t size_at(const size_t idx) const
    {
      return size_[idx];
    }
  };
  template <typename R, size_t ... Dims> struct Tensor
  : Tensor_base<Tensor, R, Dims...>
  {
    
  };
  template <typename R, size_t N> struct Vector
  : Tensor_base<Vector, R, N>
  {
    enum { size = N };
  };
  template <typename R, size_t M, size_t N> struct Matrix
  : Tensor_base<Matrix, R, M, N>
  {
    enum { row_size = M, col_size = N };
  };
  
}

// --------------------------------------------------------------------------------------------
// test: main
// --------------------------------------------------------------------------------------------

int main() {
  using Alg2::Util::PI;
  constexpr Alg2::Gcontainer<int, 2, int> ext(1, 3);
  constexpr Alg2::container<2, Alg2::container<2, int> > m{{
    {{3, 2}},
    {{4, 5}}
  }};
  constexpr Alg2::vector<2, Alg2::vector<2, int>> e{Alg2::vector<2, int>{}, Alg2::vector<2, int>{}};

  std::cout << __cplusplus << std::endl;
  std::cout << Linear::Tensor<int, 3, 2, 4>::rank << std::endl;
  std::cout << Linear::Matrix<int, 5, 3>::data_size << std::endl;
  std::cout << sizeof(m) << std::endl;
#if 1
  check_array();
#endif
#if 0
  for (long double theta = 0.; theta < 2*PI<long double>(); theta += PI<long double>()/6.) {
    std::cout
    << std::setw(15) << std::setprecision(10) << theta
    << std::setw(15) << Alg2::Math::sin(theta)
    << std::endl;
  }
#endif
  return 0;
}
