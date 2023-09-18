//
// details: trig.hpp
//

namespace Alg2
{
  
  
  namespace Math
  {
    
    
    namespace details
    {

      template <typename R> inline ALG2_CXX11_CONSTEXPR R sin_f(R x)
      {
        return 3*x - 4*Util::cube(x);
      }
      template <typename R> inline ALG2_CXX11_CONSTEXPR R sin3(R x)
      {
        return (abs(x) < Util::Epsilon<R>())? x : sin_f(sin3(x/(R)3));
      }
      template <typename R> inline ALG2_CXX11_CONSTEXPR R sin_helper(R x)
      {
        return
        (
          (x < (R)0)?
          -sin_helper(-x)
          :
          (
            (x > Util::PI<R>())?
            -sin_helper(x - Util::PI<R>())
            :
            (
              (x < Util::PI<R>()*(R)0.5)?
              sin3(x)
              :
              sin3(Util::PI<R>() - x)
            )
          )
        );
      }

      template <typename R> inline ALG2_CXX11_CONSTEXPR R tan_f(R x)
      {
        return (3*x - Util::cube(x))/(1 - 3*Util::square(x));
      }
      template <typename R> inline ALG2_CXX11_CONSTEXPR R tan3(R x)
      {
        return ( (abs(x) < Util::Epsilon<R>())? x : tan_f(tan3(x/(R)3)) );
      }
      
    } // end of namespace details
    
    template <
      typename R,
      typename Util::enabler_if<std::is_arithmetic<R>::value>::type = Util::enabler
    >
    inline ALG2_CXX11_CONSTEXPR R sin(const R x)
    {
      return details::sin_helper(Util::fmod(x, 2*Util::PI<R>()));
    }
    
    template <
      typename R,
      typename Util::enabler_if<std::is_arithmetic<R>::value>::type = Util::enabler
    >
    inline ALG2_CXX11_CONSTEXPR R cos(const R x)
    {
      return sin(x + Util::PI<R>()/(R)2);
    }
    
    template <
      typename R,
      typename Util::enabler_if<std::is_arithmetic<R>::value>::type = Util::enabler
    >
    inline ALG2_CXX11_CONSTEXPR R tan(const R x)
    {
      return details::tan3(Util::fmod(x, Util::PI<R>()));
    }
    
    
  } // end of namespace Math
  
  
} // end of namespace Alg2
