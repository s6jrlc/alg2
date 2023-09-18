//
// utility: index_sequence.hpp
//

#ifndef ALG2_UTILITY_INDEX_SEQUENCE_HPP
#define ALG2_UTILITY_INDEX_SEQUENCE_HPP

#ifdef ALG2_CXX14_OR_LATER
# include<utility>
#endif
#include"enable_if.hpp"

namespace Alg2
{
  
  namespace Util
  {

#ifdef ALG2_CXX14_OR_LATER
    using std::integer_sequence;
    using std::make_integer_sequence;
    using std::index_sequence;
    using std::make_index_sequence;
#else
    template <class I, I ... Idx> struct integer_sequence {};
    
    template <class I, typename Seq, I Next> struct make_integer_sequence_next_even;
    template <class I, typename Seq, I Next, I Last> struct make_integer_sequence_next_odd;
    
    template <class I, I ... Idx, I Next>
    struct make_integer_sequence_next_even<I, integer_sequence<I, Idx...>, Next>
    {
      typedef integer_sequence<I, Idx..., (Idx + Next)...> type;
    };
    template <class I, I ... Idx, I Next, I Last>
    struct make_integer_sequence_next_odd<I, integer_sequence<I, Idx...>, Next, Last>
    {
      typedef integer_sequence<I, Idx..., (Idx + Next)..., Last> type;
    };
    
    template <class I, I N, class Enable = void> struct make_integer_sequence_impl;
    template <class I, I N>
    struct make_integer_sequence_impl<I, N, typename enable_if<N == 0>::type>
    {
      typedef integer_sequence<I> type;
    };
    template <class I, I N>
    struct make_integer_sequence_impl<I, N, typename enable_if<N == 1>::type>
    {
      typedef integer_sequence<I, 0> type;
    };
    template <class I, I N>
    struct make_integer_sequence_impl<I, N, typename enable_if<(N > 1 && N%2 == 0)>::type>
    : make_integer_sequence_next_even<I, typename make_integer_sequence_impl<I, N/2>::type, N/2>
    {
    };
    template <class I, I N>
    struct make_integer_sequence_impl<I, N, typename enable_if<(N > 1 && N%2 != 0)>::type>
    : make_integer_sequence_next_odd<I, typename make_integer_sequence_impl<I, N/2>::type, N/2, N-1>
    {
    };
    
    template <class T, T N>
    using make_integer_sequence = typename make_integer_sequence_impl<T, N>::type;
    
    template <size_t ... Idx> using index_sequence = integer_sequence<size_t, Idx...>;
    template <size_t N> using make_index_sequence = make_integer_sequence<size_t, N>;
#endif

  } // end of namespace Util
  
} // end of namespace Alg2


#endif
