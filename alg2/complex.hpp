//
// complex.hpp
//

#ifndef ALG2_COMPLEX_HPP
#define ALG2_COMPLEX_HPP


#ifndef ALG2_USE_COMPLEX
#define ALG2_USE_COMPLEX
#endif


#include"config/config.hpp"
#include"config/exception.hpp"

#include"math.hpp"
#include"details/alg/container.hpp"


/* The classes below are exported */
#pragma GCC visibility push(default)


namespace Alg2
{


template <typename R> class complex : container<2, R>
{
  typedef R value_type;
  typedef complex<R> self_type;

public:
  ALG2_CXX11_CONSTEXPR value_type re() const;
  ALG2_CXX11_CONSTEXPR value_type im() const;

  ALG2_CXX11_CONSTEXPR R norm2() const;
  ALG2_CXX11_CONSTEXPR R norm() const;
  ALG2_CXX11_CONSTEXPR complex normalize(const complex& z) const;
  ALG2_CXX11_CONSTEXPR complex conjugate(const complex& z) const;

  ALG2_CXX11_CONSTEXPR complex();
  ALG2_CXX11_CONSTEXPR complex(value_type a, value_type b);
  explicit ALG2_CXX11_CONSTEXPR complex(value_type x);

  ALG2_CXX11_CONSTEXPR complex operator +(const complex& z) const;
  ALG2_CXX11_CONSTEXPR complex operator -(const complex& z) const;
  ALG2_CXX11_CONSTEXPR complex operator *(const complex& z) const;
  ALG2_CXX11_CONSTEXPR complex operator /(const complex& z) const;

  ALG2_CXX14_CONSTEXPR complex operator +=(const complex& z);
  ALG2_CXX14_CONSTEXPR complex operator -=(const complex& z);
  ALG2_CXX14_CONSTEXPR complex operator *=(const complex& z);
  ALG2_CXX14_CONSTEXPR complex operator /=(const complex& z);
};


} // end of namespace Alg2


#pragma GCC visibility pop


#include"details/hypercomplex/complex.hpp"


#endif
