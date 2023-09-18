//
// details: vector.hpp
//



namespace Alg2 {


template <size_t N, typename R>
inline ALG2_CXX11_CONSTEXPR vector<N, R>::vector()
: Euclidean_container<N, R, self_type>{}
{
}
template <size_t N, typename R>
template <typename ... Rs>
inline ALG2_CXX11_CONSTEXPR vector<N, R>::vector(Rs... xs)
: Euclidean_container<N, R, self_type>{xs...}
{
}

template <size_t N, typename R>
inline ALG2_CXX11_CONSTEXPR bool vector<N, R>::isParallelTo(const vector& v) const
{
  return Math::abs((this->normalize(), v.normalize()) == (R)1);
}

template <size_t N, typename R>
  inline ALG2_CXX11_CONSTEXPR R vector<N, R>::norm2() const
{
  return (*this, *this);
}
template <size_t N, typename R>
inline ALG2_CXX11_CONSTEXPR vector<N, R> vector<N, R>::normalize() const
{
  return (norm2() > Util::Epsilon<R>())? *this / Math::sqrt(norm2()) : vector();
}
template <size_t N, typename R> inline vector<N, R> vector<N, R>::normalized()
{
  double t = norm2();
  if (t < Util::Epsilon<R>())
  {
    throw dynamic_error();
  }
  return *this /= Math::sqrt(t);
}


} // end of namespace Alg2
