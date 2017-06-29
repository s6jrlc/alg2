//
// details: matrix.hpp
//


namespace Alg2
{


template <size_t M, size_t N, typename R>
inline ALG2_CXX11_CONSTEXPR matrix<M, N, R>::matrix()
: linear_double_container<M, N, R, self_type>{}
{
}
template <size_t M, size_t N, typename R>
template <typename ... Rs>
inline ALG2_CXX11_CONSTEXPR matrix<M, N, R>::matrix(Rs... xs)
: linear_double_container<M, N, R, self_type>{ xs... }
{
}


}
