//
// utility: function.hpp
//

#ifndef ALG2_UTILITY_FUNCTION_HPP
#define ALG2_UTILITY_FUNCTION_HPP

#include"enable_if.hpp"


namespace Alg2
{

  namespace Util
  {

    template <typename R> inline ALG2_CXX11_CONSTEXPR R square(R x)
    {
      return x*x;
    }
    template <typename R> inline ALG2_CXX11_CONSTEXPR R cube(R x)
    {
      return x*x*x;
    }

    namespace details
    {

      template <typename R> inline ALG2_CXX11_CONSTEXPR R int_power_helper(R x, R t)
      {
        return x * x * t;
      }

#ifdef ALG2_CXX11
      template <typename I> inline ALG2_CXX11_CONSTEXPR I gcd(I m, I n)
      {
        return (n != 0)? details::gcd(n, m % n) : m;
      }
      
      template <typename I> inline ALG2_CXX11_CONSTEXPR I factorial(I i)
      {
        return (i > (I)1)? i * details::factorial(i - 1) : 1;
      }
      
      template <typename R, typename I> inline ALG2_CXX11_CONSTEXPR R int_power(R x, I i)
      {
        return
        (
          (i < 1)?
          1
          :
          (
            (i == 1)?
            x
            :
            (
              (i % 2 == 0)?
              square(int_power(x, i/2))
              :
              details::int_power_helper(int_power(x, i/2), x)
            )
          )
        );
      }
#else
      template <typename I> inline ALG2_CXX11_CONSTEXPR I gcd(I m, I n)
      {
        I k;
        while (n)
        {
          k = m % n; m = n; n = k;
        }
        return m;
      }
      
      template <typename I> inline ALG2_CXX11_CONSTEXPR I factorial(I i)
      {
        I n = (I)1;
        while (i > (I)1)
        {
          n *= i;
          --i;
        }
        return n;
      }
      
      template <typename R, typename I> inline ALG2_CXX11_CONSTEXPR R int_power(R x, I i)
      {
        R y = (i <(I)1)? 1 : x;
        while (i >(I)1) {
          y *= x;
          --i;
        }
        return y;
      }
#endif
    }
    
    template <
      typename I,
      typename Util::enable_if<std::is_integral<I>::value>::type = Util::enabler
    >
    inline ALG2_CXX11_CONSTEXPR I gcd(I m, I n)
    {
      return ((m >= n)? details::gcd(m, n) : details::gcd(n, m));
    }

    template <
      typename I,
      typename Util::enable_if<std::is_integral<I>::value>::type = Util::enabler
    >
    inline ALG2_CXX11_CONSTEXPR I gcm(I m, I n)
    {
      return m * n / gcd(m, n);
    }
    
    template <typename I> inline ALG2_CXX11_CONSTEXPR I factorial(I i)
    {
      return details::factorial(i);
    }
    
    template <typename R, typename I> inline ALG2_CXX11_CONSTEXPR R int_power(R x, I i)
    {
      return details::int_power(x, i);
    }
    
    template <typename R> inline ALG2_CXX11_CONSTEXPR R fmod(R x, R y)
    {
      return x - static_cast<int>(x/y)*y;
    }
    
    template <typename R> inline ALG2_CXX11_CONSTEXPR bool is_nan(R x)
    {
      return x != x;
    }
    
    
  } // end of namespace Util
  
  
} // end of namespace Alg2


#endif // ALG2_UTILITY_FUNCTION_HPP
