//
// utility: expression.hpp
//

#ifndef ALG2_UTILITY_EXPRESSION_HPP
#define ALG2_UTILITY_EXPRESSION_HPP

namespace Alg2
{

  namespace Util
  {

    namespace Expr
    {
      
      template <class E> struct expression
      {
        typedef E expr_type;
        
        ALG2_CXX11_CONSTEXPR const expr_type& operator()() const
        {
          return *static_cast<const expr_type*>(this);
        }
        ALG2_CXX14_CONSTEXPR expr_type& operator()()
        {
          return *static_cast<expr_type*>(this);
        }
      };
      
      template <class T> struct scalar_identity;
      
      template <class T, class F> class unary_expression
      : public expression<unary_expression<T, F> >
      {
      public:
        typedef F func_type;
        typedef typename F::result_type value_type;
        typedef value_type const_reference;
        typedef typename Util::conditional<
        std::is_same<F, scalar_identity<typename T::value_type> >::value,
        typename T::reference,
        value_type
        >::type reference;
        typedef typename T::size_type size_type;
        typedef T expr_type;
        typedef typename T::const_closure_type expr_closure_type;
        typedef unary_expression<T, F> self_type;
        typedef const self_type const_closure_type;
        typedef self_type closure_type;
        
      private:
        expr_closure_type expr_;
        
      public:
        explicit ALG2_CXX11_CONSTEXPR unary_expression(expr_type& expr)
        : expr_(expr)
        {
        }
        
        ALG2_CXX11_CONSTEXPR const_reference operator[](size_t i) const
        {
          return func_type::apply(expr_[i]);
        }
        ALG2_CXX14_CONSTEXPR reference operator[](size_t i)
        {
          return func_type::apply(expr_[i]);
        }
      };
      
      template <class L, class F, class R> class binary_expression
      : public expression<binary_expression<L, F, R> >
      {
      public:
        typedef F func_type;
        typedef typename F::result_type value_type;
        typedef value_type const_reference;
        typedef decltype(std::declval<typename L::size_type>() + std::declval<typename R::size_type>()) size_type;
        typedef L expr_lhtype;
        typedef R expr_rhtype;
        typedef typename L::closure_type closure_lhtype;
        typedef typename R::closure_type closure_rhtype;
        typedef binary_expression<L, F, R> self_type;
        typedef const self_type const_closure_type;
        
      private:
        closure_lhtype lhexpr_;
        closure_rhtype rhexpr_;
        
      public:
        ALG2_CXX11_CONSTEXPR binary_expression(const expr_lhtype& lhexpr, const expr_rhtype& rhexpr)
        : lhexpr_(lhexpr), rhexpr_(rhexpr)
        {
        }
        
        ALG2_CXX11_CONSTEXPR const_reference operator[](size_type i) const
        {
          return func_type::apply(lhexpr_[i], rhexpr_[i]);
        }
      };
      
      template <class E> class expression_reference
      : public expression<E>
      {
      public:
        typedef expression_reference<E> self_type;
        typedef typename E::size_type size_type;
        typedef typename E::value_type value_type;
        typedef typename E::const_reference const_reference;
        typedef typename Util::conditional<
        std::is_const<E>::value,
        const typename E::const_reference,
        typename E::reference
        >::type reference;
        typedef E referred_type;
        typedef self_type closure_type;
        
      private:
        referred_type expr_;
        
      public:
        explicit ALG2_CXX11_CONSTEXPR expression_reference(expression_reference& expr)
        : expr_(expr)
        {
        }
        
        ALG2_CXX11_CONSTEXPR const_reference operator[](size_type i) const
        {
          return expr_[i];
        }
        ALG2_CXX14_CONSTEXPR reference operator[](size_type i)
        {
          return expr_[i];
        }
      };
      
      template <class T> struct scalar_unary_function
      {
        typedef T value_type;
        typedef const T& arg_type;
        typedef value_type result_type;
      };
      
      template <class T> struct scalar_identity
      : public scalar_unary_function<T>
      {
        typedef typename scalar_unary_function<T>::arg_type arg_type;
        typedef typename scalar_unary_function<T>::result_type result_type;
        
        static ALG2_CXX11_CONSTEXPR result_type apply(arg_type v)
        {
          return v;
        }
      };
      
      template <class T> struct scalar_negate
      : public scalar_unary_function<T>
      {
        typedef typename scalar_unary_function<T>::arg_type arg_type;
        typedef typename scalar_unary_function<T>::result_type result_type;
        
        static ALG2_CXX11_CONSTEXPR result_type apply(arg_type v)
        {
          return -v;
        }
      };
      
      template <class L, class R> struct scalar_binary_function
      {
        typedef const L& arg_lhtype;
        typedef const R& arg_rhtype;
        typedef decltype(std::declval<arg_lhtype>() + std::declval<arg_rhtype>()) result_type;
      };
      
      template <class L, class R> struct scalar_plus
      : public scalar_binary_function<L, R>
      {
        typedef typename scalar_binary_function<L, R>::arg_lhtype arg_lhtype;
        typedef typename scalar_binary_function<L, R>::arg_rhtype arg_rhtype;
        typedef typename scalar_binary_function<L, R>::result_type result_type;
        
        static ALG2_CXX11_CONSTEXPR result_type apply(arg_lhtype l, arg_rhtype r)
        {
          return l + r;
        }
      };
      template <class L, class R> struct scalar_minus
      : public scalar_binary_function<L, R>
      {
        typedef typename scalar_binary_function<L, R>::arg_lhtype arg_lhtype;
        typedef typename scalar_binary_function<L, R>::arg_rhtype arg_rhtype;
        typedef typename scalar_binary_function<L, R>::result_type result_type;
        
        static ALG2_CXX11_CONSTEXPR result_type apply(arg_lhtype l, arg_rhtype r)
        {
          return l - r;
        }
      };
      template <class L, class R> struct scalar_multiply
      : public scalar_binary_function<L, R>
      {
        typedef typename scalar_binary_function<L, R>::arg_lhtype arg_lhtype;
        typedef typename scalar_binary_function<L, R>::arg_rhtype arg_rhtype;
        typedef typename scalar_binary_function<L, R>::result_type result_type;
        
        static ALG2_CXX11_CONSTEXPR result_type apply(arg_lhtype l, arg_rhtype r)
        {
          return l * r;
        }
      };
      template <class L, class R> struct scalar_divide
      : public scalar_binary_function<L, R>
      {
        typedef typename scalar_binary_function<L, R>::arg_lhtype arg_lhtype;
        typedef typename scalar_binary_function<L, R>::arg_rhtype arg_rhtype;
        typedef typename scalar_binary_function<L, R>::result_type result_type;
        
        static ALG2_CXX11_CONSTEXPR result_type apply(arg_lhtype l, arg_rhtype r)
        {
          return l / r;
        }
      };
      
      template <class L, class R> struct scalar_binary_assign
      {
        typedef typename std::remove_reference<typename std::remove_const<L>::type>::type& arg_lhtype;
        typedef const R& arg_rhtype;
        typedef L& result_type;
      };
      
      template <class L, class R> struct scalar_assign
      : public scalar_binary_assign<L, R>
      {
        typedef typename scalar_binary_assign<L, R>::arg_lhtype arg_lhtype;
        typedef typename scalar_binary_assign<L, R>::arg_rhtype arg_rhtype;
        typedef typename scalar_binary_assign<L, R>::result_type result_type;
        
        static ALG2_CXX14_CONSTEXPR result_type apply(arg_lhtype l, arg_rhtype r)
        {
          return (l = r);
        }
      };
      
      template <class L, class R> struct scalar_plus_assign
      : public scalar_binary_assign<L, R>
      {
        typedef typename scalar_binary_assign<L, R>::arg_lhtype arg_lhtype;
        typedef typename scalar_binary_assign<L, R>::arg_rhtype arg_rhtype;
        typedef typename scalar_binary_assign<L, R>::result_type result_type;
        
        static ALG2_CXX11_CONSTEXPR result_type apply(arg_lhtype l, arg_rhtype r)
        {
          return l += r;
        }
      };
      template <class L, class R> struct scalar_minus_assign
      : public scalar_binary_assign<L, R>
      {
        typedef typename scalar_binary_assign<L, R>::arg_lhtype arg_lhtype;
        typedef typename scalar_binary_assign<L, R>::arg_rhtype arg_rhtype;
        typedef typename scalar_binary_assign<L, R>::result_type result_type;
        
        static ALG2_CXX11_CONSTEXPR result_type apply(arg_lhtype l, arg_rhtype r)
        {
          return l -= r;
        }
      };
      template <class L, class R> struct scalar_multiply_assign
      : public scalar_binary_assign<L, R>
      {
        typedef typename scalar_binary_assign<L, R>::arg_lhtype arg_lhtype;
        typedef typename scalar_binary_assign<L, R>::arg_rhtype arg_rhtype;
        typedef typename scalar_binary_assign<L, R>::result_type result_type;
        
        static ALG2_CXX11_CONSTEXPR result_type apply(arg_lhtype l, arg_rhtype r)
        {
          return l *= r;
        }
      };
      template <class L, class R> struct scalar_divide_assign
      : public scalar_binary_assign<L, R>
      {
        typedef typename scalar_binary_assign<L, R>::arg_lhtype arg_lhtype;
        typedef typename scalar_binary_assign<L, R>::arg_rhtype arg_rhtype;
        typedef typename scalar_binary_assign<L, R>::result_type result_type;
        
        static ALG2_CXX11_CONSTEXPR result_type apply(arg_lhtype l, arg_rhtype r)
        {
          return l /= r;
        }
      };
      
      namespace Operator
      {
        template <class L, class R>
        ALG2_CXX11_CONSTEXPR
        binary_expression<L, scalar_plus<typename L::value_type, typename R::value_type>, R>
        operator +(const expression<L>& lhs, const expression<R>& rhs)
        {
          return binary_expression<L, scalar_plus<typename L::value_type, typename R::value_type>, R>(lhs(), rhs());
        }
        template <class L, class R>
        ALG2_CXX11_CONSTEXPR
        binary_expression<L, scalar_plus<typename L::value_type, typename R::value_type>, R>
        operator -(const expression<L>& lhs, const expression<R>& rhs)
        {
          return binary_expression<L, scalar_minus<typename L::value_type, typename R::value_type>, R>(lhs(), rhs());
        }
        template <class L, class R>
        ALG2_CXX11_CONSTEXPR
        binary_expression<L, scalar_plus<typename L::value_type, typename R::value_type>, R>
        operator *(const expression<L>& lhs, const expression<R>& rhs)
        {
          return binary_expression<L, scalar_multiply<typename L::value_type, typename R::value_type>, R>(lhs(), rhs());
        }
        template <class L, class R>
        ALG2_CXX11_CONSTEXPR
        binary_expression<L, scalar_plus<typename L::value_type, typename R::value_type>, R>
        operator /(const expression<L>& lhs, const expression<R>& rhs)
        {
          return binary_expression<L, scalar_divide<typename L::value_type, typename R::value_type>, R>(lhs(), rhs());
        }
      } // end of namespace Operator
      
    } // end of namespace Expr
    
    using Expr::Operator::operator +;
    using Expr::Operator::operator -;
    using Expr::Operator::operator *;
    using Expr::Operator::operator /;

  } // end of namespace Util

} // end of namespace Alg2

#endif 
