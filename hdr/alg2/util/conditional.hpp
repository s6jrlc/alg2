//
// utility: conditional.hpp
//

#ifndef ALG2_UTILITY_CONDITIONAL_HPP
#define ALG2_UTILITY_CONDITIONAL_HPP

#ifdef ALG2_CXX11_OR_LATER
# include<type_traits>
#endif


namespace Alg2
{
  
  namespace Util
  {
#ifdef ALG2_CXX11_OR_LATER
    using std::conditional;
#else
    template <bool Cond, typename TT, typename FT> struct conditional
    {
      typedef FT type;
    };
    template <typename TT, typename FT> struct conditional<true, TT, FT>
    {
      typedef TT type;
    };
#endif

#ifdef ALG2_CXX14_OR_LATER
    using std::conditional_t;
#else
    template <bool Cond, typename TT, typename FT>
    using conditional_t = typename conditional<Cond, TT, FT>::type;
#endif
  } // end of namespace Util

} // end of namespace Alg2


#endif
