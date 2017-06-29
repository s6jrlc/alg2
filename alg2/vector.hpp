//
// vector.hpp
//

#ifndef ALG2_VECTOR_HPP
#define ALG2_VECTOR_HPP


#ifndef ALG2_USE_VECTOR
#define ALG2_USE_VECTOR
#endif


#include"config/config.hpp"
#include"config/exception.hpp"
#include"utility/index_sequence.hpp"
#include"math.hpp"
#include"details/alg/euclidean_container.hpp"


/* The classes below are exported */
#pragma GCC visibility push(default)


namespace Alg2
{


template <size_t N, typename R> class vector
  : public Euclidean_container<N, R, vector<N, R> >
{
  typedef vector<N, R> self_type;

public:
  ALG2_CXX11_CONSTEXPR vector();
  template <typename ... Rs>
  ALG2_CXX11_CONSTEXPR vector(Rs... xs);

  ALG2_CXX11_CONSTEXPR bool isParallelTo(const vector& v) const;

  ALG2_CXX11_CONSTEXPR R norm2() const;
  ALG2_CXX11_CONSTEXPR vector normalize() const;
  vector normalized();
};


#ifdef ALG2_CXX11_OR_LATER

template <size_t N> using Vectorf = vector<N, float>;
template <size_t N> using Vectord = vector<N, double>;
template <size_t N> using Vectorld = vector<N, long double>;

#endif

typedef vector<2, float> Vector2f;
typedef vector<3, float> Vector3f;
typedef vector<4, float> Vector4f;
typedef vector<2, double> Vector2d;
typedef vector<3, double> Vector3d;
typedef vector<4, double> Vector4d;
typedef vector<2, long double> Vector2ld;
typedef vector<3, long double> Vector3ld;
typedef vector<4, long double> Vector4ld;


} // end of namespace Alg2



#pragma GCC visibility pop


#include"details/alg/vector.hpp"
#include"utility/vector.hpp"


#endif // ALG2_VECTOR_HPP
