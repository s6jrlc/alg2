//
// details: sqrt.hpp
//


namespace Alg2
{
  
  
  namespace Math
  {
    
    
    namespace details
    {
      
      
      template <typename R> inline ALG2_CXX11_CONSTEXPR R sqrt(const R s, R x, R last)
      {
#ifdef ALG2_CXX11
        return (x != last)? sqrt(s, (x + s/x)/(R)2, x) : x;
#else
        while (x != last)
        {
          last = x;
          x = (x + s/x)/(R)2;
        }
        return x;
#endif
      }
      
    }
    
    
    template <
      typename R,
      typename Util::enabler_if<std::is_arithmetic<R>::value>::type = Util::enabler
    >
    inline ALG2_CXX11_CONSTEXPR R sqrt(const R x)
    {
      return Math::details::sqrt(x, x/(R)2, (R)0);
    }
    
    
  } // end of namespace Math
  
  
} // end of namespace Alg2
