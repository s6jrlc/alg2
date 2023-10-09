//
// alg2 config: type.hpp
//

#ifndef ALG2_CONFIG_TYPE_HPP
#define ALG2_CONFIG_TYPE_HPP

#ifdef ALG2_CXX11_OR_LATER
# include<cstddef>
#endif

namespace Alg2
{

  namespace Util
  {

    typedef std::size_t size_t;
    typedef std::nullptr_t nullptr_t;

  } // end of namespace Util

  using Util::size_t;
  using Util::nullptr_t;

} // end of namespace Alg2

#endif // ALG2_CONFIG_TYPE_HPP
