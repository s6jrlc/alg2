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
    using std::is_integral;
    using std::is_floating_point;
    using std::is_arithmetic;

# if defined(ALG2_CXX14)
    template <typename I> ALG2_CXX11_CONSTEXPR bool is_integral_v = is_integral<I>::value;
    template <typename R> ALG2_CXX11_CONSTEXPR bool is_floating_point_v = is_floating_point<R>::value;
    template <typename R> ALG2_CXX11_CONSTEXPR bool is_arithmetic_v = is_arithmetic<R>::value;
# elif defined(ALG2_CXX17_OR_LATER)
    using std::is_integral_v;
    using std::is_floating_point_v;
    using std::is_arithmetic_v;
# endif

# if defined(ALG2_CXX20_OR_LATER)
    using std::integral;
    using std::floating_point;

    template <typename R> concept ArithType = is_arithmetic<R>::value;
 #endif

#endif


	} // end of namespace Util

} // end of namespace Alg2

#endif // ALG2_UTILITY_TRAITS_HPP
