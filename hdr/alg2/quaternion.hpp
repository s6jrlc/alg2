//
// quartenion.hpp
//

#ifndef ALG2_QUATERNION_HPP
#define ALG2_QUATERNION_HPP


#ifndef ALG2_USE_QUATERNION
#define ALG2_USE_QUATERNION
#endif


#include"config/config.hpp"
#include"config/exception.hpp"

#include"math.hpp"
#include"details/alg/container.hpp"


/* The classes below are exported */
#pragma GCC visibility push(default)


namespace Alg2
{
  
  
template <typename R> class quaternion : container<4, R>
{
  typedef R value_type;
  typedef quaternion<R> self_type;

public:
  ALG2_CXX11_CONSTEXPR value_type re() const;
  ALG2_CXX11_CONSTEXPR value_type im1() const;
  ALG2_CXX11_CONSTEXPR value_type im2() const;
  ALG2_CXX11_CONSTEXPR value_type im3() const;

  ALG2_CXX11_CONSTEXPR R norm2() const;
  ALG2_CXX11_CONSTEXPR R norm() const;
  ALG2_CXX11_CONSTEXPR quaternion conjugate() const;
  ALG2_CXX11_CONSTEXPR quaternion normalize() const;
  ALG2_CXX11_CONSTEXPR quaternion inverse() const;

  ALG2_CXX11_CONSTEXPR quaternion();
  ALG2_CXX11_CONSTEXPR quaternion(value_type a, value_type b, value_type c, value_type d);
  
  explicit ALG2_CXX11_CONSTEXPR quaternion(value_type x);

  ALG2_CXX11_CONSTEXPR quaternion operator +() const;
  ALG2_CXX11_CONSTEXPR quaternion operator -() const;

  static ALG2_CXX11_CONSTEXPR quaternion rotation(const R theta);
};
  
  
} // end of namespace Alg2


#pragma GCC visibility pop


#include"details/hypercomplex/quaternion.hpp"


#endif
