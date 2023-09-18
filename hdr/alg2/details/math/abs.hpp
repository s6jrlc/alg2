//
// details: abs.hpp
//

namespace Alg2
{
  
  
  namespace Math
  {
    
    
    template <
      typename R,
      typename Util::enabler_if<std::is_arithmetic<R>::value>::type = Util::enabler
    >
    inline ALG2_CXX11_CONSTEXPR R abs(const R x)
    {
      return (x >= (R)0)? x : -x;
    }
    
    
  } // end of namespace Math
  
  
} // end of namespace Alg2
