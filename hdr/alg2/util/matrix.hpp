//
// utility: matrix.hpp
//

#ifndef ALG2_UTILITY_MATRIX_HPP
#define ALG2_UTILITY_MATRIX_HPP


namespace Alg2
{


  namespace Util
  {

    namespace Extract
    {

      template <size_t M, size_t N, typename R, size_t ... Idx>
      inline ALG2_CXX11_CONSTEXPR matrix<N, M, R> transpose(const matrix<M, N, R>& m, Util::index_sequence<Idx...>)
      {
        return { m[(Idx%M)*N + (Idx/M)]... };
      }
      template <size_t M, size_t N, typename R, size_t ... J>
      inline ALG2_CXX11_CONSTEXPR matrix<1, N, R> row(const matrix<M, N, R>& m, size_t i, Util::index_sequence<J...>)
      {
        return { m[i*N + J]... };
      }
      template <size_t M, size_t N, typename R, size_t ... I>
      inline ALG2_CXX11_CONSTEXPR matrix<M, 1, R> col(const matrix<M, N, R>& m, size_t j, Util::index_sequence<I...>)
      {
        return { m[I*N + j]... };
      }

      template <size_t M, size_t N, typename R, size_t ... Idx>
      inline ALG2_CXX11_CONSTEXPR matrix<M-1, N, R> truncate_btm_row(const matrix<M, N, R>& m, Util::index_sequence<Idx...>)
      {
        return { m[Idx]... };
      }
      template <size_t M, size_t N, typename R, size_t ... Idx>
      inline ALG2_CXX11_CONSTEXPR matrix<M-1, N, R> truncate_top_row(const matrix<M, N, R>& m, Util::index_sequence<Idx...>)
      {
        return { m[Idx + N]... };
      }
      template <size_t M, size_t N, typename R, size_t ... Idx>
      inline ALG2_CXX11_CONSTEXPR matrix<M, N-1, R> truncate_right_col(const matrix<M, N, R>& m, Util::index_sequence<Idx...>)
      {
        return { m[Idx + Idx/(N-1)]... };
      }
      template <size_t M, size_t N, typename R, size_t ... Idx>
      inline ALG2_CXX11_CONSTEXPR matrix<M, N-1, R> truncate_left_col(const matrix<M, N, R>& m, Util::index_sequence<Idx...>)
      {
        return { m[(Idx + 1) + (Idx)/(N-1)]... };
      }

      template <size_t M, size_t N, typename R, size_t ... Idx>
      inline ALG2_CXX11_CONSTEXPR matrix<M+1, N, R> extend_btm_row(const matrix<M, N, R>& m, Util::index_sequence<Idx...>)
      {
        return { (Idx < M*N? m[Idx] : (R)0)... };
      }
      template <size_t M, size_t N, typename R, size_t ... Idx>
      inline ALG2_CXX11_CONSTEXPR matrix<M+1, N, R> extend_top_row(const matrix<M, N, R>& m, Util::index_sequence<Idx...>)
      {
        return { (Idx >= N? m[Idx - N] : (R)0)... };
      }
      template <size_t M, size_t N, typename R, size_t ... Idx>
      inline ALG2_CXX11_CONSTEXPR matrix<M, N+1, R> extend_right_col(const matrix<M, N, R>& m, Util::index_sequence<Idx...>)
      {
        return { (Idx % (N+1) < N? m[Idx - Idx/(N+1)] : (R)0)... };
      }
      template <size_t M, size_t N, typename R, size_t ... Idx>
      inline ALG2_CXX11_CONSTEXPR matrix<M, N+1, R> extend_left_col(const matrix<M, N, R>& m, Util::index_sequence<Idx...>)
      {
        return { (Idx % (N+1) != 0? m[Idx - Idx/(N+1) - 1] : (R)0)... };
      }

    } // end of namespace Extract

    template <size_t M, size_t N, typename R>
    inline ALG2_CXX11_CONSTEXPR matrix<N, M, R> transpose(const matrix<M, N, R>& m)
    {
      return Extract::transpose(m, Util::make_index_sequence<M*N>());
    }
    template <size_t M, size_t N, typename R>
    inline ALG2_CXX11_CONSTEXPR matrix<1, N, R> single_row(const matrix<M, N, R>& m, size_t i)
    {
      return Extract::row(m, i, Util::make_index_sequence<N>());
    }
    template <size_t M, size_t N, typename R>
    inline ALG2_CXX11_CONSTEXPR matrix<M, 1, R> single_col(const matrix<M, N, R>& m, size_t j)
    {
      return Extract::col(m, j, Util::make_index_sequence<M>());
    }

    template <size_t M, size_t N, typename R>
    inline ALG2_CXX11_CONSTEXPR matrix<M-1, N, R> truncate_btm_row(const matrix<M, N, R>& m)
    {
      return Extract::truncate_btm_row(m, Util::make_index_sequence<(M-1)*N>());
    }
    template <size_t M, size_t N, typename R>
    inline ALG2_CXX11_CONSTEXPR matrix<M-1, N, R> truncate_top_row(const matrix<M, N, R>& m)
    {
      return Extract::truncate_top_row(m, Util::make_index_sequence<(M-1)*N>());
    }
    template <size_t M, size_t N, typename R>
    inline ALG2_CXX11_CONSTEXPR matrix<M, N-1, R> truncate_right_col(const matrix<M, N, R>& m)
    {
      return Extract::truncate_right_col(m, Util::make_index_sequence<M*(N-1)>());
    }
    template <size_t M, size_t N, typename R>
    inline ALG2_CXX11_CONSTEXPR matrix<M, N-1, R> truncate_left_col(const matrix<M, N, R>& m)
    {
      return Extract::truncate_left_col(m, Util::make_index_sequence<M*(N-1)>());
    }

    template <size_t M, size_t N, typename R>
    inline ALG2_CXX11_CONSTEXPR matrix<M+1, N, R> extend_btm_row(const matrix<M, N, R>& m)
    {
      return Extract::extend_btm_row(m, Util::make_index_sequence<(M+1)*N>());
    }
    template <size_t M, size_t N, typename R>
    inline ALG2_CXX11_CONSTEXPR matrix<M+1, N, R> extend_top_row(const matrix<M, N, R>& m)
    {
      return Extract::extend_top_row(m, Util::make_index_sequence<(M+1)*N>());
    }
    template <size_t M, size_t N, typename R>
    inline ALG2_CXX11_CONSTEXPR matrix<M, N+1, R> extend_right_col(const matrix<M, N, R>& m)
    {
      return Extract::extend_right_col(m, Util::make_index_sequence<M*(N+1)>());
    }
    template <size_t M, size_t N, typename R>
    inline ALG2_CXX11_CONSTEXPR matrix<M, N+1, R> extend_left_col(const matrix<M, N, R>& m)
    {
      return Extract::extend_left_col(m, Util::make_index_sequence<M*(N+1)>());
    }

    namespace Multiply
    {

      template <size_t N, typename R>
      inline ALG2_CXX11_CONSTEXPR R scalar_pseudo_prod(const matrix<1, N, R>& lhs, const matrix<N, 1, R>& rhs, size_t idx = 0)
      {
        return (idx < N)? scalar_pseudo_prod(lhs, rhs, idx+1) + lhs[idx]*rhs[idx] : 0;
      }
      template <size_t L, size_t M, size_t N, typename R, size_t ... Idx>
      inline ALG2_CXX11_CONSTEXPR matrix<L, N, R> multiply(const matrix<L, M, R>& lhs, const matrix<M, N, R>& rhs, Util::index_sequence<Idx...>)
      {
        return { scalar_pseudo_prod(single_row(lhs, Idx/N), single_col(rhs, Idx%N))... };
      }

    } // end of namespace Multiply

#ifdef ALG2_CXX11_OR_LATER
template <size_t L, size_t M, size_t N, typename R>
  inline ALG2_CXX11_CONSTEXPR matrix<L, N, R> operator *(const matrix<L, M, R>& lhs, const matrix<M, N, R>& rhs)
  {
    return Util::Multiply::multiply(lhs, rhs, Util::make_index_sequence<L*N>());
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


    namespace GJE
    {

      namespace helper
      {

        template <size_t M, size_t N, typename R, size_t ... Idx>
        inline ALG2_CXX11_CONSTEXPR matrix<M, N, R> sweep(const matrix<M, N, R>& m, size_t i, Util::index_sequence<Idx...>)
        {
          return {
            ((Idx/N != i)?
              ((Math::abs(m[i + i*N]) != (R)0)?
                m[Idx] - m[Idx%N + i*N]/m[i + i*N]*m[i + (Idx/N)*N]
                :
                (R)0)
              :
              m[Idx]
            )...
          };
        }
        template <size_t M, size_t N, typename R>
        inline ALG2_CXX11_CONSTEXPR matrix<M, N, R> recurse(const matrix<M, N, R>& m, size_t idx)
        {
          return
          (
            (idx < M)?
            recurse(sweep(m, idx, Util::make_index_sequence<M*N>()), idx+1)
            :
            m
          );
        }
        template <size_t M, size_t N, typename R, size_t ... Idx>
        inline ALG2_CXX11_CONSTEXPR matrix<M, N, R> swap_row(const matrix<M, N, R>& m, size_t i1, size_t i2, Util::index_sequence<Idx...>)
        {
          return {
            ((Idx/N == i1)? m[i2*N + Idx%N] : ((Idx/N == i2)? m[i1*N + Idx%N] : m[Idx]))...
          };
        }
        template <size_t M, size_t N, typename R, size_t ... Idx>
        inline ALG2_CXX11_CONSTEXPR matrix<M, N, R> divide(const matrix<M, N, R>& m, Util::index_sequence<Idx...>)
        {
          return {
            ((Math::abs(m[Idx]) >= 0 && Math::abs(m[(Idx/N)*(N+1)]) >= 0)?
              m[Idx]/m[(Idx/N)*(N+1)]
              :
              m[Idx]
            )...
          };
        }

      }

      template <size_t M, size_t N, typename R>
      inline ALG2_CXX11_CONSTEXPR matrix<M, N, R> elimination(const matrix<M, N, R>& m)
      {
        return helper::divide(helper::recurse(m, 0), Util::make_index_sequence<M*N>());
      }

    }


    namespace Sq
    {


      namespace helper
      {

        template <size_t N, typename R, size_t ... Idx>
        inline ALG2_CXX11_CONSTEXPR matrix<N, N, R> identity(Util::index_sequence<Idx...>) {
          return { (Idx/N == Idx%N? (R)1 : (R)0)... };
        }

      }

      template <size_t N, typename R>
      inline ALG2_CXX11_CONSTEXPR matrix<N, N, R> identity_matrix()
      {
        return helper::identity<N, R>(Util::make_index_sequence<N*N>());
      }

      namespace Decomp
      {

        namespace Extract
        {

          template <size_t N, typename R, size_t ... Idx>
          inline ALG2_CXX11_CONSTEXPR matrix<1, N-1, R> tr_elements1xN_1(const matrix<N, N, R>& m, Util::index_sequence<Idx...>)
          {
            return { m[1 + Idx]... };
          }
          template <size_t N, typename R, size_t ... Idx>
          inline ALG2_CXX11_CONSTEXPR matrix<N-1, 1, R> bl_elementsN_1x1(const matrix<N, N, R>& m, Util::index_sequence<Idx...>)
          {
            return { m[(1 + Idx) * N]... };
          }
          /*
           N = 4 :
           i = Idx/N, j = Idx%N
           1   2   3
           1: 5,  6,  7,
           2: 9,  10, 11,
           3: 13, 14, 15
           i' = (Idx/(N-1) + 1), j' = (Idx%(N-1) + 1)
           Idx' = i' * N + j'
           */
          template <size_t N, typename R, size_t ... Idx>
          inline ALG2_CXX11_CONSTEXPR matrix<N-1, N-1, R> br_elementsN_1xN_1(const matrix<N, N, R>& m, Util::index_sequence<Idx...>)
          {
            return { m[(Idx/(N-1) + 1)*N + (Idx%(N-1) + 1)]... };
          }

          template <size_t N, typename R, size_t ... Idx>
          inline ALG2_CXX11_CONSTEXPR matrix<N, N, R> lower_triangulate(const matrix<N, N, R>& m, Util::index_sequence<Idx...>)
          {
            return { (Idx/N >= Idx%N ? m[Idx] : (R)0)... };
          }
          template <size_t N, typename R, size_t ... Idx>
          inline ALG2_CXX11_CONSTEXPR matrix<N, N, R> upper_triangulate(const matrix<N, N, R>& m, Util::index_sequence<Idx...>)
          {
            return { (((Idx/N < Idx%N)? m[Idx] : ((Idx/N > Idx%N)? (R)0 : (R)1)))... };
          }

          template <size_t N, typename R, size_t ... Idx>
          inline ALG2_CXX11_CONSTEXPR matrix<N, N, R> LUhelper2(const matrix<1, 1, R>& tl, const matrix<1, N-1, R>& tr, const matrix<N-1, 1, R>& bl, const matrix<N-1, N-1, R>& br, Util::index_sequence<Idx...>)
          {
            return
            {
              ( (Idx == 0)?
                tl[0]
                :
                ( (Idx < N)?
                  tr[Idx - 1]
                  :
                  ( (Idx % N == 0)?
                    bl[Idx/N - 1]
                    :
                    br[(Idx/N - 1)*(N-1) + (Idx%N) - 1]
                  )
                )
              )...
            };
          }

        } // end of namespace Decomp::Extract

        template <size_t N, typename R>
        inline ALG2_CXX11_CONSTEXPR matrix<1, 1, R> submatrix_tl1x1(const matrix<N, N, R>& m)
        {
          return { m[0] };
        }
        template <size_t N, typename R>
        inline ALG2_CXX11_CONSTEXPR matrix<1, N-1, R> submatrix_tr1xN_1(const matrix<N, N, R>& m)
        {
          return (Math::abs(m[0] >= 0)? Extract::tr_elements1xN_1(m, Util::make_index_sequence<N - 1>())/m[0] : matrix<1, N-1, R>());
        }
        template <size_t N, typename R>
        inline ALG2_CXX11_CONSTEXPR matrix<N-1, 1, R> submatrix_blN_1x1(const matrix<N, N, R>& m)
        {
          return Extract::bl_elementsN_1x1(m, Util::make_index_sequence<N - 1>());
        }
        template <size_t N, typename R>
        inline ALG2_CXX11_CONSTEXPR matrix<N-1, N-1, R> submatrix_brN_1xN_1(const matrix<N, N, R>& m)
        {
          return Extract::br_elementsN_1xN_1(m, Util::make_index_sequence<(N - 1) * (N - 1)>());
        }

        template <size_t N, typename R>
        inline ALG2_CXX11_CONSTEXPR matrix<N, N, R> lower_triangulate(const matrix<N, N, R>& m)
        {
          return Extract::lower_triangulate(m, Util::make_index_sequence<N*N>());
        }
        template <size_t N, typename R>
        inline ALG2_CXX11_CONSTEXPR matrix<N, N, R> upper_triangulate(const matrix<N, N, R>& m)
        {
          return Extract::upper_triangulate(m, Util::make_index_sequence<N*N>());
        }

        template <size_t N, typename R>
        inline ALG2_CXX11_CONSTEXPR matrix<N-1, N-1, R> LUhelper1(const matrix<N, N, R>& m)
        {
          return submatrix_brN_1xN_1(m) - submatrix_blN_1x1(m)*(submatrix_tr1xN_1(m));
        }

        template <size_t N, typename R>
        inline ALG2_CXX11_CONSTEXPR matrix<N, N, R>
        LUhelper2(const matrix<1, 1, R>& tl, const matrix<1, N-1, R>& tr, const matrix<N-1, 1, R>& bl, const matrix<N-1, N-1, R>& br)
        {
          return Extract::LUhelper2<N, R>(tl, tr, bl, br, Util::make_index_sequence<N*N>());
        }

        template <size_t N, typename R> struct LU
        {
          static ALG2_CXX11_CONSTEXPR matrix<N, N, R> decomp(const matrix<N, N, R>& m)
          {
            return LUhelper2<N, R>(submatrix_tl1x1(m), submatrix_tr1xN_1(m), submatrix_blN_1x1(m), LU<N-1, R>::decomp(LUhelper1(m)));
          }
          
        private:
#ifdef ALG2_CXX11_OR_LATER
          LU() = delete;
#else
          LU();
#endif
        };
        template <typename R> struct LU<1, R>
        {
          static inline ALG2_CXX11_CONSTEXPR matrix<1, 1, R> decomp(const matrix<1, 1, R>& m)
          {
            return { m[0] };
          }
          
        private:
#ifdef ALG2_CXX11_OR_LATER
          LU() = delete;
#else
          LU();
#endif
        };

      } // end of namespace Decomp


      namespace LU
      {
        template <size_t N, typename R> inline ALG2_CXX11_CONSTEXPR matrix<N, N, R> decomposition(const matrix<N, N, R>& m)
        {
          return Sq::Decomp::LU<N, R>::decomp(m);
        }
      }

      using Decomp::lower_triangulate;
      using Decomp::upper_triangulate;
      
    } // end of namespace Sq


  } // end of namespace Util


  using Util::operator*;


} // end of namespace Alg2


#endif // ALG2_UTILITY_MATRIX_HPP

