//
// utility: traits.hpp
//

#ifndef ALG2_UTILITY_TRAITS_HPP
#define ALG2_UTILITY_TRAITS_HPP

#if defined(ALG2_CXX11_OR_LATER)
# include<type_traits>
#endif

namespace Alg2
{

  namespace Util
  {
#if defined(ALG2_CXX11_OR_LATER)
    using std::is_same;
    using std::is_const;

    using std::is_integral;
    using std::is_floating_point;
    using std::is_arithmetic;

# if defined(ALG2_CXX17_OR_LATER)
    using std::is_integral_v;
    using std::is_floating_point_v;
    using std::is_arithmetic_v;
# endif

# if defined(ALG2_CXX20_OR_LATER)
    using std::integral;
    using std::floating_point;

    template <typename R> concept arithmetic = is_arithmetic<R>::value;

    template <typename I> concept IntType = integral<I>;
    template <typename R> concept FloatType = floating_point<R>;
    template <typename R> concept ArithType = arithmetic<R>;
# endif
  
    using std::remove_const;
    using std::remove_reference;
#endif
  } // end of namespace Util

} // end of namespace Alg2

#endif // ALG2_UTILITY_TRAITS_HPP
