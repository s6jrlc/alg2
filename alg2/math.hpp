//
//  math.hpp
//

#ifndef ALG2_MATH_HPP
#define ALG2_MATH_HPP


#include"config/config.hpp"
#include"config/exception.hpp"
#include"utility/constant.hpp"
#include"utility/function.hpp"


/* The classes below are exported */
#pragma GCC visibility push(default)


namespace Alg2
{


namespace Math
{


template <typename R> inline ALG2_CXX11_CONSTEXPR R abs(const R x);
template <typename R> inline ALG2_CXX11_CONSTEXPR R ln(const R x); // 誤差あり
template <typename R> inline ALG2_CXX11_CONSTEXPR R log2(const R x);
template <typename R> inline ALG2_CXX11_CONSTEXPR R log10(const R x);
template <typename R> inline ALG2_CXX11_CONSTEXPR R log(const R a, const R x);
template <typename R> inline ALG2_CXX11_CONSTEXPR R sqrt(const R x);


} // end of namespace Math


} // end of namespace Alg2


#pragma GCC visibility pop


#include"details/math/abs.hpp"
#include"details/math/log.hpp"
#include"details/math/sqrt.hpp"
#include"details/math/trig.hpp"


#endif // ALG2_MATH_HPP
