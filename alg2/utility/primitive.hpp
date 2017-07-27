//
// utility: primitive.hpp
//

#ifndef ALG2_UTILITY_PRIMITIVE_HPP
#define ALG2_UTILITY_PRIMITIVE_HPP

#include<type_traits>


namespace Alg2
{
  
  
  namespace Utility
  {


    namespace Primitive
    {

      template <class T> struct Base {};

    }

    
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
      
    }
    
    
    template <size_t ... Idx>
    using index_sequence = details::index_sequence<Idx...>;
    template <size_t N>
    using make_index_sequence = typename details::make_partial_index_sequence<0, N - 1, 1>::type;
    
    
  } // end of namespace Utility
  
  
} // end of namespace Alg2


#endif
