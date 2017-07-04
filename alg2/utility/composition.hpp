//
// utility: composition.hpp
//


#if defined(ALG2_USE_VECTOR) && defined(ALG2_USE_MATRIX)


#ifndef ALG2_UTILITY_COMPOSITION_HPP
#define ALG2_UTILITY_COMPOSITION_HPP


namespace Alg2
{


  namespace Utility
  {

    namespace cast
    {

      template <size_t N, typename R, size_t ... Idx>
      inline ALG2_CXX11_CONSTEXPR matrix<1, N, R> single_row(const vector<N, R>& v, Utility::index_sequence<Idx...>)
      {
        return { v[Idx]... };
      }
      template <size_t N, typename R, size_t ... Idx>
      inline ALG2_CXX11_CONSTEXPR matrix<N, 1, R> single_col(const vector<N, R>& v, Utility::index_sequence<Idx...>)
      {
        return { v[Idx]... };
      }

      template <size_t N, typename R, size_t ... Idx>
      inline ALG2_CXX11_CONSTEXPR vector<N, R> row_vector(const matrix<1, N, R>& m, Utility::index_sequence<Idx...>)
      {
        return { m[Idx]... };
      }
      template <size_t N, typename R, size_t ... Idx>
      inline ALG2_CXX11_CONSTEXPR vector<N, R> col_vector(const matrix<N, 1, R>& m, Utility::index_sequence<Idx...>)
      {
        return { m[Idx]... };
      }

    }

    template <size_t N, typename R>
    inline ALG2_CXX11_CONSTEXPR matrix<1, N, R> single_row(const vector<N, R>& v)
    {
      return cast::single_row(v, Utility::make_index_sequence<N>());
    }
    template <size_t N, typename R>
    inline ALG2_CXX11_CONSTEXPR matrix<N, 1, R> single_col(const vector<N, R>& v)
    {
      return cast::single_col(v, Utility::make_index_sequence<N>());
    }

    template <size_t N, typename R>
    inline ALG2_CXX11_CONSTEXPR vector<N, R> row_vector(const matrix<1, N, R>& m)
    {
      return cast::row_vector(m, Utility::make_index_sequence<N>());
    }
    template <size_t N, typename R>
    inline ALG2_CXX11_CONSTEXPR vector<N, R> col_vector(const matrix<N, 1, R>& m)
    {
      return cast::col_vector(m, Utility::make_index_sequence<N>());
    }

    template <size_t M, size_t N, typename R>
    inline ALG2_CXX11_CONSTEXPR vector<N, R> row_vector(const matrix<M, N, R>& m, size_t i)
    {
      return row_vector(single_row(m, i));
    }
    template <size_t M, size_t N, typename R>
    inline ALG2_CXX11_CONSTEXPR vector<M, R> col_vector(const matrix<M, N, R>& m, size_t j)
    {
      return col_vector(single_col(m, j));
    }
  }

template <size_t M, size_t N, typename R>
  inline ALG2_CXX11_CONSTEXPR vector<M, R> operator *(const matrix<M, N, R>& m, const vector<N, R>& v)
  {
    //return Utility::col_vector(Utility::Composite::multiply(m, Utility::single_col(v), Utility::index_sequence<M>()));
    return operator* (m, Utility::single_col(v));

  }
template <size_t M, size_t N, typename R>
  inline ALG2_CXX11_CONSTEXPR vector<N, R> operator *(const vector<M, R>& v, const matrix<M, N, R>& m)
  {
    return operator* (Utility::single_row(v), m);
  }


}


#endif // ALG2_UTILITY_COMPOSITION_HPP


#endif // included only ALG2_USE_VECTOR and _MATRIX
