//
// utility: matrix.hpp
//

#ifndef ALG2_UTILITY_MATRIX_HPP
#define ALG2_UTILITY_MATRIX_HPP


namespace Alg2
{


namespace Matrix
{


namespace Utility
{

using namespace ::Alg2;
using namespace Alg2::Utility;

template <size_t M, size_t N, typename R, size_t ... Idx>
  inline ALG2_CXX11_CONSTEXPR matrix<M, N, R> make_matrix(const matrix<M, N, R>& m, Utility::index_sequence<Idx...>)
  {
    return { m[Idx]... };
  }

template <size_t M, size_t N, typename R, size_t ... Idx>
  inline ALG2_CXX11_CONSTEXPR matrix<1, N, R> row(const matrix<M, N, R>& m, size_t idx, Utility::index_sequence<Idx...>)
  {
    return { m[idx*M + Idx]... };
  }
template <size_t M, size_t N, typename R, size_t ... Idx>
  inline ALG2_CXX11_CONSTEXPR matrix<M, 1, R> col(const matrix<M, N, R>& m, size_t idx, Utility::index_sequence<Idx...>)
  {
    return { m[idx + Idx]... };
  }

#ifdef ALG2_USE_VECTOR
template <size_t M, size_t N, typename R, size_t ... Idx>
  inline ALG2_CXX11_CONSTEXPR vector<N, R> row_block(const matrix<M, N, R>& m, size_t idx, Utility::index_sequence<Idx...>)
  {
    return { m[idx*M + Idx]... };
  }
  template <size_t M, size_t N, typename R, size_t ... Idx>
  inline ALG2_CXX11_CONSTEXPR vector<M, R> col_block(const matrix<M, N, R>& m, size_t idx, Utility::index_sequence<Idx...>)
  {
    return { m[idx + Idx]... };
  }

template <size_t M, size_t N, typename R, size_t ... Idx>
  inline ALG2_CXX11_CONSTEXPR vector<N, R> multiply(const matrix<M, N, R>& m, const vector<N, R>& v, Utility::index_sequence<Idx...>)
  {
    return { (row_block(m, Idx, Utility::make_index_sequence<N>()), v)... };
  }
#endif

} // end of namespace Utility


template <size_t M, size_t N, typename R>
  inline ALG2_CXX11_CONSTEXPR matrix<1, N, R> row(const matrix<M, N, R>& m, size_t idx)
{
  return Utility::row(m, idx, Utility::make_index_sequence<N>());
}
template <size_t M, size_t N, typename R>
  inline ALG2_CXX11_CONSTEXPR matrix<M, 1, R> col(const matrix<M, N, R>& m, size_t idx)
{
  return Utility::col(m, idx, Utility::make_partial_index_sequence<0, (M-1)*N, N>());
}

namespace Utility
{

template <size_t N, typename R>
  inline ALG2_CXX11_CONSTEXPR R pseudo_inner_prod(const matrix<1, N, R>& lhs, const matrix<N, 1, R>& rhs, size_t i = 0)
  {
    return (i < N)? pseudo_inner_prod(lhs, rhs) + lhs[i]*rhs[i] : 0;
  }
template <size_t M, size_t N, typename R, size_t ... Idx>
  inline ALG2_CXX11_CONSTEXPR matrix<1, N, R> partial_multiply(const matrix<1, M, R>& lhs, const matrix<M, N, R>& rhs, Utility::index_sequence<Idx...>)
  {
    return { pseudo_inner_prod(lhs, Matrix::col(rhs, Idx))... };
  }
template <size_t M, size_t N, typename R, typename ... Rs, size_t ... Idx>
  inline ALG2_CXX11_CONSTEXPR std::tuple<Rs...> partial_multiply2(const matrix<1, M, R>& lhs, const matrix<M, N, R>& rhs, Utility::index_sequence<Idx...>)
  {
    return std::forward_as_tuple(pseudo_inner_prod(lhs, Matrix::col(rhs, Idx))...);
  }
template <size_t L, size_t M, size_t N, typename R, size_t ... Idx>
  inline ALG2_CXX11_CONSTEXPR matrix<L, N, R> multiply(const matrix<L, M, R>& lhs, const matrix<M, N, R>& rhs, Utility::index_sequence<Idx...>)
  {
    return { Utility::partial_multiply(Matrix::row(lhs, Idx), rhs, Utility::make_index_sequence<N>())... };
  }
template <size_t L, size_t M, size_t N, typename R, typename ... Rs, size_t ... Idx>
  inline ALG2_CXX11_CONSTEXPR std::tuple<Rs...> multiply2(const matrix<L, M, R>& lhs, const matrix<M, N, R>& rhs, Utility::index_sequence<Idx...>)
  {
    return std::forward_as_tuple(Utility::partial_multiply2(Matrix::row(lhs, Idx), rhs, Utility::make_index_sequence<N>())...);
  }
template <size_t L, size_t M, size_t N, typename R, size_t ... Idx>
  inline ALG2_CXX11_CONSTEXPR matrix<L, N, R> multiple_as_matrix(const matrix<L, M, R>& lhs, const matrix<M, N, R>& rhs)
  {
    return {};
  }
/*
 現在のエラーは1行の行列を集めてM行の行列を作るコンストラクタが存在しないことによるもの
 1行または1列の行列を複数集めて行列を作る方法としてパラメータパック2つの多重展開(現時点で不可能)しか浮かんできていないため、
 現在行列同士の積を求めるオペレータはC++14にのみ対応
*/
}

template <size_t M, size_t N, typename R>
  inline ALG2_CXX11_CONSTEXPR matrix<N, M, R> transpose(const matrix<M, N, R>& m)
{
  return Utility::make_matrix(m, Utility::make_row2col_sequence<M, N>());
}

#ifdef ALG2_USE_VECTOR
template <size_t M, size_t N, typename R>
  inline ALG2_CXX11_CONSTEXPR vector<N, R> row_vector(const matrix<M, N, R>& m, size_t idx)
{
  return Utility::row_block(m, idx, Utility::make_index_sequence<N>());
}
template <size_t M, size_t N, typename R>
  inline ALG2_CXX11_CONSTEXPR vector<M, R> col_vector(const matrix<M, N, R>& m, size_t idx)
{
  return Utility::col_block(m, idx, Utility::make_partial_index_sequence<0, (M-1)*N, N>());
}
#endif


} // end of namespace Matrix

#ifdef ALG2_USE_VECTOR
template <size_t M, size_t N, typename R>
  inline ALG2_CXX11_CONSTEXPR vector<N, R> operator *(const matrix<M, N, R>& m, const vector<N, R>& v)
{
  return Matrix::Utility::multiply(m, v, Utility::make_row2col_sequence<M, 1>());
}
#endif

#ifdef ALG2_CXX11
template <size_t L, size_t M, size_t N, typename R>
  inline ALG2_CXX11_CONSTEXPR matrix<L, N, R> operator *(const matrix<L, M, R>& lhs, const matrix<M, N, R>& rhs)
  {
    return Matrix::Utility::multiply(lhs, rhs, Utility::make_index_sequence<L>());
  }
#else
template <size_t L, size_t M, size_t N, typename R>
  inline ALG2_CXX14_CONSTEXPR matrix<L, N, R> operator *(const matrix<L, M, R>& lhs, const matrix<M, N, R>& rhs)
  {
    matrix<L, N, R> res;
    for (size_t i=0; i<L; ++i)
    {
      for (size_t j=0; j<M; ++j)
      {
        for (size_t k=0; k<N; ++k)
        {
          res.at(i, k) += lhs(i, j)*rhs(j, k);
        }
      }
    }
    return res;
  }
#endif


} // end of namespace Alg2


#endif // ALG2_UTILITY_MATRIX_HPP

