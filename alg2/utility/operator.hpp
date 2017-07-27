//
// utility: operator.hpp
//

#ifndef ALG2_UTILITY_OPERATOR_HPP
#define ALG2_UTILITY_OPERATOR_HPP


#include"primitive.hpp"


namespace Alg2
{

  namespace Utility
  {

    namespace Operator
    {

      template <class T, class B = Primitive::Base<T> >
      struct comparison1 : B
      {
        friend ALG2_CXX11_CONSTEXPR bool operator >(const T& lhs, const T& rhs)
        {
          return (rhs < lhs);
        }
        friend ALG2_CXX11_CONSTEXPR bool operator <=(const T& lhs, const T& rhs)
        {
          return !(rhs < lhs);
        }
        friend ALG2_CXX11_CONSTEXPR bool operator >=(const T& lhs, const T& rhs)
        {
          return !(lhs < rhs);
        }
      };
      template <class T, class U, class B = Primitive::Base<T> >
      struct comparison2 : B
      {
        friend ALG2_CXX11_CONSTEXPR bool operator <(const U& lhs, const T& rhs)
        {
          return (rhs > lhs);
        }
        friend ALG2_CXX11_CONSTEXPR bool operator >(const U& lhs, const T& rhs)
        {
          return (rhs < lhs);
        }
        friend ALG2_CXX11_CONSTEXPR bool operator <=(const T& lhs, const U& rhs)
        {
          return !(lhs > rhs);
        }
        friend ALG2_CXX11_CONSTEXPR bool operator >=(const T& lhs, const U& rhs)
        {
          return !(lhs < rhs);
        }
        friend ALG2_CXX11_CONSTEXPR bool operator <=(const U& lhs, const T& rhs)
        {
          return !(rhs < lhs);
        }
        friend ALG2_CXX11_CONSTEXPR bool operator >=(const U& lhs, const T& rhs)
        {
          return !(rhs > lhs);
        }
      };
      template <class T, class B = Primitive::Base<T> >
      struct equality1 : B
      {
        friend ALG2_CXX11_CONSTEXPR bool operator !=(const T& lhs, const T& rhs)
        {
          return !(lhs == rhs);
        }
      };
      template <class T, class U, class B = Primitive::Base<T> >
      struct equality2 : B
      {
        friend ALG2_CXX11_CONSTEXPR bool operator !=(const T& lhs, const U& rhs)
        {
          return !(lhs == rhs);
        }
        friend ALG2_CXX11_CONSTEXPR bool operator ==(const U& lhs, const T& rhs)
        {
          return (rhs == lhs);
        }
        friend ALG2_CXX11_CONSTEXPR bool operator !=(const U& lhs, const T& rhs)
        {
          return !(rhs == lhs);
        }
      };

      template <class T, class U, class B = Primitive::Base<T> >
      struct addition : B
      {
        friend ALG2_CXX11_CONSTEXPR T operator +(const U& lhs, const T& rhs)
        {
          return rhs + lhs;
        }
        friend ALG2_CXX11_CONSTEXPR T operator +=(T& lhs, const U& rhs)
        {
          return (lhs = lhs + rhs);
        }
      };
      template <class T, class U, class B = Primitive::Base<T> >
      struct subtraction : B
      {
        friend ALG2_CXX11_CONSTEXPR T operator -=(T& lhs, const U& rhs)
        {
          return (lhs = lhs - rhs);
        }
      };
      template <class T, class U, class B = Primitive::Base<T> >
      struct multiply : B
      {
        friend ALG2_CXX11_CONSTEXPR T operator *(const U& lhs, const T& rhs)
        {
          return rhs * lhs;
        }
        friend ALG2_CXX11_CONSTEXPR T operator *=(T& lhs, const U& rhs)
        {
          return (lhs = lhs * rhs);
        }
      };
      template <class T, class U, class B = Primitive::Base<T> >
      struct division : B
      {
        friend ALG2_CXX11_CONSTEXPR T operator /=(T& lhs, const U& rhs)
        {
          return (lhs = lhs / rhs);
        }
      };
      template <class T, class U, class B = Primitive::Base<T> >
      struct modulas : B
      {
        friend ALG2_CXX11_CONSTEXPR T operator %=(T& lhs, const U& rhs)
        {
          return (lhs = lhs % rhs);
        }
      };

    }

  }

}


#endif
