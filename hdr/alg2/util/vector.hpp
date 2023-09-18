//
// utility: vector.hpp
//

#ifndef ALG2_UTILITY_VECTOR_HPP
#define ALG2_UTILITY_VECTOR_HPP


namespace Alg2
{


namespace Vector
{


namespace Util
{

using namespace ::Alg2;
using namespace Alg2::Util;

template <size_t N, typename R, size_t ... Idx>
  inline ALG2_CXX11_CONSTEXPR vector<N - 1, R> truncate(const vector<N, R>& v, Util::index_sequence<Idx...>)
{
  return { v[Idx]/v[N - 1]... };
}

template <size_t N, typename R, size_t ... Idx>
  inline ALG2_CXX11_CONSTEXPR vector<N + 1, R> extend(const vector<N, R>& v, R x, Util::index_sequence<Idx...>)
{
  return { v[Idx]..., x };
}

} // end of namespace Util


template <size_t N, typename R>
  inline ALG2_CXX11_CONSTEXPR vector<N - 1, R> truncate(const vector<N, R>& v)
{
  return v[N-1] != (R)0? Util::truncate(v, Util::make_index_sequence<N-1>()) : vector<N-1, R>();
}
template <size_t N, typename R>
  inline ALG2_CXX11_CONSTEXPR vector<N + 1, R> extend(const vector<N, R>& v, R x)
{
  return Util::extend(v, x, Util::make_index_sequence<N>());
}
template <size_t N, typename R>
  inline ALG2_CXX11_CONSTEXPR vector<N + 1, R> extend(const vector<N, R>& v)
{
  return Util::extend(v, (R)1, Util::make_index_sequence<N>());
}

template <size_t N, typename R>
  inline ALG2_CXX11_CONSTEXPR vector<N - 1, R> diversify(const vector<N, R>& v)
{
  return v[N-1] != (R)0? Util::truncate(v, Util::make_index_sequence<N-1>()) : vector<N-1, R>();
}
template <size_t N, typename R>
  inline ALG2_CXX11_CONSTEXPR vector<N + 1, R> homogenize(const vector<N, R>& v, R x)
{
  return Util::extend(v, x, Util::make_index_sequence<N>());
}
template <size_t N, typename R>
  inline ALG2_CXX11_CONSTEXPR vector<N + 1, R> homogenize(const vector<N, R>& v)
{
  return Util::extend(v, (R)1, Util::make_index_sequence<N>());
}


} // end of namespace Vector


} // end of namespace Alg2


#endif // ALG2_UTILITY_VECTOR_HPP

