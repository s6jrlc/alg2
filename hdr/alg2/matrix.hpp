//
//  matrix.hpp
//

#ifndef ALG2_MATRIX_HPP
#define ALG2_MATRIX_HPP


#ifndef ALG2_USE_MATRIX
#define ALG2_USE_MATRIX
#endif


#include"config/config.hpp"
#include"config/exception.hpp"

#include"details/alg/linear_double_container.hpp"


/* The classes below are exported */
#pragma GCC visibility push(default)


namespace Alg2
{


template <size_t M, size_t N, typename R> class matrix
  : public linear_double_container<M, N, R, matrix<M, N, R> >
{
  typedef matrix<M, N, R> self_type;
  typedef R value_type;
  typedef R* iterator;
  typedef R& value_reference;

public:
  ALG2_CXX11_CONSTEXPR matrix();
  template <typename ... Rs>
  ALG2_CXX11_CONSTEXPR matrix(Rs... vs);
};


}


#pragma GCC visibility pop


#include"details/alg/matrix.hpp"
#include"util/matrix.hpp"
#include"util/constant.hpp"
#include"util/composition.hpp"


#endif // ALG2_MATRIX_HPP
