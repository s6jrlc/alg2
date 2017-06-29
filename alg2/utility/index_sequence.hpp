//
// utility: index_sequence.hpp
//

#ifndef ALG2_UTILITY_INDEX_SEQUENCE_HPP
#define ALG2_UTILITY_INDEX_SEQUENCE_HPP

#include<type_traits>


namespace Alg2
{


namespace Utility
{


namespace details
{

template <size_t ... i> struct index_sequence{};

template <size_t MIN, size_t MAX, size_t STRIDE> class make_partial_index_sequence
{
  static_assert((MAX-MIN) % STRIDE == 0, "invalid argument: recursion of index_sequence never stops");

  template <size_t I, size_t ... i> struct make_partial_index_sequence_impl
  : public make_partial_index_sequence_impl<I - STRIDE, i... , MAX + MIN + (STRIDE - I)>
  {
  };

  template <size_t ... i> struct make_partial_index_sequence_impl<MIN, i...>
  {
    typedef index_sequence<i...> type;
  };

public:
  typedef typename make_partial_index_sequence_impl<MAX + STRIDE>::type type;
};

template <size_t M, size_t N> class make_col2row_sequence
{
  template <size_t I, size_t J, size_t ... i> struct make_col2row_sequence_impl
  : make_col2row_sequence_impl<I, J - 1, i..., M*(N - J + 1) - I>
  {
  };
  template <size_t I, size_t ... i> struct make_col2row_sequence_impl<I, 0, i...>
  : make_col2row_sequence_impl<I - 1, N, i...>
  {
  };
  template <size_t J, size_t ... i> struct make_col2row_sequence_impl<0, J, i...>
  {
    typedef index_sequence<i...> type;
  };

public:
  typedef typename make_col2row_sequence_impl<M, N>::type type;
};

}


template <size_t ... Idx>
using index_sequence = details::index_sequence<Idx...>;
template <size_t N>
using make_index_sequence = typename details::make_partial_index_sequence<0, N - 1, 1>::type;
template <size_t MIN, size_t MAX, size_t STRIDE = 1>
using make_partial_index_sequence = typename details::make_partial_index_sequence<MIN, MAX, STRIDE>::type;
template <size_t M, size_t N>
using make_col2row_sequence = typename details::make_col2row_sequence<M, N>::type;
template <size_t M, size_t N>
using make_row2col_sequence = typename details::make_col2row_sequence<N, M>::type;


} // end of namespace Utility


} // end of namespace Alg2


#endif
