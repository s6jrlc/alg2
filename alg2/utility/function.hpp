//
// utility: function.hpp
//

#ifndef ALG2_UTILITY_FUNCTION_HPP
#define ALG2_UTILITY_FUNCTION_HPP

#include<type_traits>


namespace Alg2
{


namespace Utility
{


namespace details
{

  template <typename I> inline ALG2_CXX11_CONSTEXPR I gcd(I m, I n)
  {
#ifdef ALG2_CXX11
    return (n != 0)? details::gcd(n, m % n) : m;
#else
    I k;
    while (n)
    {
      k = m % n; m = n; n = k;
    }
    return m;
#endif
  }
  
  template <typename I> inline ALG2_CXX11_CONSTEXPR I factorial(I i)
  {
#ifdef ALG2_CXX11
    return (i > (I)1)? i * details::factorial(i - 1) : 1;
#else
    I n = (I)1;
    while (i > (I)1)
    {
      n *= i;
      --i;
    }
    return n;
#endif
  }

  template <typename R, typename I> inline ALG2_CXX11_CONSTEXPR I integer_power(R x, I i)
  {
#ifdef ALG2_CXX11
    return (i > (I)0)? x * details::integer_power(x, i - 1) : 1;
#else
    R y = (R)1;
    while (i >(I)0) {
      y *= x;
      --i;
    }
    return y;
#endif
  }

}

template <typename I> inline ALG2_CXX11_CONSTEXPR I gcd(I m, I n)
{
  static_assert(std::is_integral<I>::value, "invalid type for Alg2::Utility::gcd");
  return ((m >= n)? details::gcd(m, n) : details::gcd(n, m));
}
template <typename I> inline ALG2_CXX11_CONSTEXPR I gcm(I m, I n)
{
  static_assert(std::is_integral<I>::value, "invalid type for Alg2::Utility::gcm");
  return m * n / gcd(m, n);
}

template <typename I> inline ALG2_CXX11_CONSTEXPR I factorial(I i)
{
  static_assert(std::is_integral<I>::value, "invalid type for Alg2::Utility::factorial");
  return details::factorial(i);
}

template <typename R> inline ALG2_CXX11_CONSTEXPR R square(R x)
{
  static_assert(std::is_arithmetic<R>::value, "invalid type for Alg2::");
  return x*x;
}
template <typename R> inline ALG2_CXX11_CONSTEXPR R cube(R x)
{
  static_assert(std::is_arithmetic<R>::value, "invalid type for Alg2::Utility::cube");
  return x*x*x;
}

template <typename R, typename I> inline ALG2_CXX11_CONSTEXPR R int_power(R x, I i)
{
  static_assert(std::is_arithmetic<R>::value, "invalid type for base of Alg2::Utility::integer_power");
  static_assert(std::is_integral<I>::value, "invalid type for exponent of Alg2::Utility::integer_power");
  return details::integer_power(x, i);
}

template <typename R> inline ALG2_CXX11_CONSTEXPR R fmod(R x, R y)
{
  return x - static_cast<int>(x/y)*y;
}

template <typename R> inline ALG2_CXX11_CONSTEXPR bool is_nan(R x)
{
  return x != x;
}


} // end of namespace Utility


} // end of namespace Alg2


#endif // ALG2_UTILITY_FUNCTION_HPP
