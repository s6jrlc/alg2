//
// utility: matrix.hpp
//

#ifndef ALG2_UTILITY_MATRIX_HPP
#define ALG2_UTILITY_MATRIX_HPP


namespace Alg2
{


  namespace Utility
  {

    namespace Extract
    {
 
      template <size_t M, size_t N, typename R, size_t ... Idx>
      inline ALG2_CXX11_CONSTEXPR matrix<N, M, R> transpose(const matrix<M, N, R>& m, Utility::index_sequence<Idx...>)
      {
        return { m[(Idx%M)*N + (Idx/M)]... };
      }
      template <size_t M, size_t N, typename R, size_t ... J>
      inline ALG2_CXX11_CONSTEXPR matrix<1, N, R> row(const matrix<M, N, R>& m, size_t i, Utility::index_sequence<J...>)
      {
        return { m[i*N + J]... };
      }
      template <size_t M, size_t N, typename R, size_t ... I>
      inline ALG2_CXX11_CONSTEXPR matrix<M, 1, R> col(const matrix<M, N, R>& m, size_t j, Utility::index_sequence<I...>)
      {
        return { m[I*N + j]... };
      }

      template <size_t M, size_t N, typename R, size_t ... Idx>
      inline ALG2_CXX11_CONSTEXPR matrix<M-1, N, R> truncate_btm_row(const matrix<M, N, R>& m, Utility::index_sequence<Idx...>)
      {
        return { m[Idx]... };
      }
      template <size_t M, size_t N, typename R, size_t ... Idx>
      inline ALG2_CXX11_CONSTEXPR matrix<M-1, N, R> truncate_top_row(const matrix<M, N, R>& m, Utility::index_sequence<Idx...>)
      {
        return { m[Idx + N]... };
      }
      template <size_t M, size_t N, typename R, size_t ... Idx>
      inline ALG2_CXX11_CONSTEXPR matrix<M, N-1, R> truncate_right_col(const matrix<M, N, R>& m, Utility::index_sequence<Idx...>)
      {
        return { m[Idx + Idx/(N-1)]... };
      }
      template <size_t M, size_t N, typename R, size_t ... Idx>
      inline ALG2_CXX11_CONSTEXPR matrix<M, N-1, R> truncate_left_col(const matrix<M, N, R>& m, Utility::index_sequence<Idx...>)
      {
        return { m[(Idx + 1) + (Idx)/(N-1)]... };
      }

      template <size_t M, size_t N, typename R, size_t ... Idx>
      inline ALG2_CXX11_CONSTEXPR matrix<M+1, N, R> extend_btm_row(const matrix<M, N, R>& m, Utility::index_sequence<Idx...>)
      {
        return { (Idx < M*N? m[Idx] : (R)0)... };
      }
      template <size_t M, size_t N, typename R, size_t ... Idx>
      inline ALG2_CXX11_CONSTEXPR matrix<M, N+1, R> extend_right_col(const matrix<M, N, R>& m, Utility::index_sequence<Idx...>)
      {
        return { (Idx % (N+1) < N? m[Idx - Idx/(N+1)] : (R)0)... };
      }

    } // end of namespace Extract

    template <size_t M, size_t N, typename R>
    inline ALG2_CXX11_CONSTEXPR matrix<N, M, R> transpose(const matrix<M, N, R>& m)
    {
      return Extract::transpose(m, Utility::make_index_sequence<M*N>());
    }
    template <size_t M, size_t N, typename R>
    inline ALG2_CXX11_CONSTEXPR matrix<1, N, R> single_row(const matrix<M, N, R>& m, size_t i)
    {
      return Extract::row(m, i, Utility::make_index_sequence<N>());
    }
    template <size_t M, size_t N, typename R>
    inline ALG2_CXX11_CONSTEXPR matrix<M, 1, R> single_col(const matrix<M, N, R>& m, size_t j)
    {
      return Extract::col(m, j, Utility::make_index_sequence<M>());
    }

    template <size_t M, size_t N, typename R>
    inline ALG2_CXX11_CONSTEXPR matrix<M-1, N, R> truncate_btm_row(const matrix<M, N, R>& m)
    {
      return Extract::truncate_btm_row(m, Utility::make_index_sequence<(M-1)*N>());
    }
    template <size_t M, size_t N, typename R>
    inline ALG2_CXX11_CONSTEXPR matrix<M-1, N, R> truncate_top_row(const matrix<M, N, R>& m)
    {
      return Extract::truncate_top_row(m, Utility::make_index_sequence<(M-1)*N>());
    }
    template <size_t M, size_t N, typename R>
    inline ALG2_CXX11_CONSTEXPR matrix<M, N-1, R> truncate_right_col(const matrix<M, N, R>& m)
    {
      return Extract::truncate_right_col(m, Utility::make_index_sequence<M*(N-1)>());
    }
    template <size_t M, size_t N, typename R>
    inline ALG2_CXX11_CONSTEXPR matrix<M, N-1, R> truncate_left_col(const matrix<M, N, R>& m)
    {
      return Extract::truncate_left_col(m, Utility::make_index_sequence<M*(N-1)>());
    }

    template <size_t M, size_t N, typename R>
    inline ALG2_CXX11_CONSTEXPR matrix<M+1, N, R> extend_btm_row(const matrix<M, N, R>& m)
    {
      return Extract::extend_btm_row(m, Utility::make_index_sequence<(M+1)*N>());
    }
    template <size_t M, size_t N, typename R>
    inline ALG2_CXX11_CONSTEXPR matrix<M, N+1, R> extend_right_col(const matrix<M, N, R>& m)
    {
      return Extract::extend_right_col(m, Utility::make_index_sequence<M*(N+1)>());
    }

    namespace Composite
    {

      template <size_t N, typename R>
      inline ALG2_CXX11_CONSTEXPR R pseudo_scalar_prod(const matrix<1, N, R>& lhs, const matrix<N, 1, R>& rhs, size_t idx = 0)
      {
        return (idx < N)? pseudo_scalar_prod(lhs, rhs, idx+1) + lhs[idx]*rhs[idx] : 0;
      }
      template <size_t L, size_t M, size_t N, typename R, size_t ... Idx>
      inline ALG2_CXX11_CONSTEXPR matrix<L, N, R> multiply(const matrix<L, M, R>& lhs, const matrix<M, N, R>& rhs, Utility::index_sequence<Idx...>)
      {
        return { pseudo_scalar_prod(single_row(lhs, Idx/N), single_col(rhs, Idx%N))... };
      }

    } // end of namespace Composite

  } // end of namespace Utility

#ifdef ALG2_CXX11_OR_LATER
template <size_t L, size_t M, size_t N, typename R>
  inline ALG2_CXX11_CONSTEXPR matrix<L, N, R> operator *(const matrix<L, M, R>& lhs, const matrix<M, N, R>& rhs)
  {
    return Utility::Composite::multiply(lhs, rhs, Utility::make_index_sequence<L*N>());
  }
#else
template <size_t L, size_t M, size_t N, typename R>
  inline matrix<L, N, R> operator *(const matrix<L, M, R>& lhs, const matrix<M, N, R>& rhs)
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

