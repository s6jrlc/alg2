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
        return 3*x - 4*Utility::cube(x);
      }
      template <typename R> inline ALG2_CXX11_CONSTEXPR R sin3(R x)
      {
        return (abs(x) < Utility::Epsilon<R>())? x : sin_f(sin3(x/(R)3));
      }

      template <typename R> inline ALG2_CXX11_CONSTEXPR R tan_f(R x)
      {
        return (3*x - Utility::cube(x))/(1 - 3*Utility::square(x));
      }
      template <typename R> inline ALG2_CXX11_CONSTEXPR R tan3(R x)
      {
        return ( (abs(x) < Utility::Epsilon<R>())? x : tan_f(tan3(x/(R)3)) );
      }
      
    } // end of namespace details
    
    template <typename R> inline ALG2_CXX11_CONSTEXPR R sin(const R x)
    {
      return
      (
        Utility::fmod(x, Utility::PI<R>()) >= (R)1.e-10
       &&
        Utility::PI<long double>() - Utility::fmod(x, Utility::PI<R>()) >= (R)1.e-10
       ?
        details::sin3(Utility::fmod(x, Utility::PI<R>()))
       :
        (R)0
      );
    }
    
    template <typename R> inline ALG2_CXX11_CONSTEXPR R cos(const R x)
    {
      return sin(x + Utility::PI<R>()/(R)2);
    }
    
    template <typename R> inline ALG2_CXX11_CONSTEXPR R tan(const R x)
    {
      return details::tan3(Utility::fmod(x, Utility::PI<R>()));
    }
    
    
  } // end of namespace Math
  
  
} // end of namespace Alg2
