//
// utility: enable_if.hpp
//

#ifndef ALG2_UTILITY_ENABLE_IF_HPP
#define ALG2_UTILITY_ENABLE_IF_HPP

#include"types.hpp"
#ifdef ALG2_CXX11_OR_LATER
# include<type_traits>
#endif


namespace Alg2
{

  namespace Util
  {
#ifdef ALG2_CXX11_OR_LATER
    using std::enable_if;
    template <bool Cond, typename T = void*> using enabler_if = enable_if<Cond, T>;
#else
    template <bool Cond, typename T = void> struct enable_if {};
    template <typename T> struct enable_if<true, T> { typedef T type; };

    template <bool Cond, typename T = void*> struct enabler_if {};
    template <typename T> struct enabler_if<true, T> { typedef T type; };
#endif

#ifdef ALG2_CXX14_OR_LATER
    using std::enable_if_t;
#else
    template <bool Cond, typename T = void>
    using enable_if_t = typename enable_if<Cond, T>::type;
#endif

    ALG2_CXX11_CONSTEXPR nullptr_t enabler = 0;
    
  } // end of namespace Util

} // end of namespace Alg2


#endif
