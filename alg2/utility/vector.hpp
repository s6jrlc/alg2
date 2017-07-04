//
// utility: vector.hpp
//

#ifndef ALG2_UTILITY_VECTOR_HPP
#define ALG2_UTILITY_VECTOR_HPP


namespace Alg2
{


namespace Vector
{


namespace Utility
{

using namespace ::Alg2;
using namespace Alg2::Utility;

template <size_t N, typename R, size_t ... Idx>
  inline ALG2_CXX11_CONSTEXPR vector<N - 1, R> truncate(const vector<N, R>& v, Utility::index_sequence<Idx...>)
{
  return { v[Idx]/v[N - 1]... };
}

template <size_t N, typename R, size_t ... Idx>
  inline ALG2_CXX11_CONSTEXPR vector<N + 1, R> extend(const vector<N, R>& v, R x, Utility::index_sequence<Idx...>)
{
  return { v[Idx]..., x };
}

} // end of namespace Utility


template <size_t N, typename R>
  inline ALG2_CXX11_CONSTEXPR vector<N - 1, R> truncate(const vector<N, R>& v)
{
  return v[N-1] != (R)0? Utility::truncate(v, Utility::make_index_sequence<N-1>()) : vector<N-1, R>();
}
template <size_t N, typename R>
  inline ALG2_CXX11_CONSTEXPR vector<N + 1, R> extend(const vector<N, R>& v, R x)
{
  return Utility::extend(v, x, Utility::make_index_sequence<N>());
}
template <size_t N, typename R>
  inline ALG2_CXX11_CONSTEXPR vector<N + 1, R> extend(const vector<N, R>& v)
{
  return Utility::extend(v, (R)1, Utility::make_index_sequence<N>());
}

template <size_t N, typename R>
  inline ALG2_CXX11_CONSTEXPR vector<N - 1, R> diversify(const vector<N, R>& v)
{
  return v[N-1] != (R)0? Utility::truncate(v, Utility::make_index_sequence<N-1>()) : vector<N-1, R>();
}
template <size_t N, typename R>
  inline ALG2_CXX11_CONSTEXPR vector<N + 1, R> homogenize(const vector<N, R>& v, R x)
{
  return Utility::extend(v, x, Utility::make_index_sequence<N>());
}
template <size_t N, typename R>
  inline ALG2_CXX11_CONSTEXPR vector<N + 1, R> homogenize(const vector<N, R>& v)
{
  return Utility::extend(v, (R)1, Utility::make_index_sequence<N>());
}


} // end of namespace Vector


} // end of namespace Alg2


#endif // ALG2_UTILITY_VECTOR_HPP

