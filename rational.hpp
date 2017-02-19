//
// rational.hpp
//

#ifndef ALG_RATIONAL_HPP
#define ALG_RATIONAL_HPP

#include"config/config.hpp"
#include<istream>
#include<ostream>
#include<string>

namespace Alg2 {

template <typename I = int> void swap(I& m, I& n);
template <typename I = int> ALG2_CXX11_CONSTEXPR I gcd(I m, I n);

template <typename I = int> class Rational
{
  I num, den;

public:

  std::string to_string() const;

  ALG2_CXX11_CONSTEXPR I numerator() const;
  ALG2_CXX11_CONSTEXPR I denominator() const;

  ALG2_CXX11_CONSTEXPR Rational inverse() const;

  ALG2_CXX11_CONSTEXPR Rational reduce() const;
  ALG2_CXX14_CONSTEXPR Rational reduced();

private:

  ALG2_CXX11_CONSTEXPR Rational sum(const Rational&) const;
  ALG2_CXX11_CONSTEXPR Rational mul(const Rational&) const;

public:

  ALG2_CXX11_CONSTEXPR Rational();
  ALG2_CXX11_CONSTEXPR Rational(I n, I d);
  ALG2_CXX11_CONSTEXPR Rational(I i);

  ALG2_CXX14_CONSTEXPR Rational operator =(const Rational& f);
  ALG2_CXX14_CONSTEXPR Rational operator =(const I i);

  ALG2_CXX11_CONSTEXPR operator float() const;
  ALG2_CXX11_CONSTEXPR operator double() const;
  ALG2_CXX11_CONSTEXPR operator long double() const;
  ALG2_CXX11_CONSTEXPR operator bool() const;

  ALG2_CXX11_CONSTEXPR Rational operator +() const;
  ALG2_CXX11_CONSTEXPR Rational operator -() const;

  ALG2_CXX14_CONSTEXPR Rational& operator ++();
  ALG2_CXX14_CONSTEXPR Rational& operator --();

  ALG2_CXX14_CONSTEXPR Rational operator ++(int);
  ALG2_CXX14_CONSTEXPR Rational operator --(int);

  ALG2_CXX14_CONSTEXPR Rational operator +=(const Rational&);
  ALG2_CXX14_CONSTEXPR Rational operator -=(const Rational&);
  ALG2_CXX14_CONSTEXPR Rational operator *=(const Rational&);
  ALG2_CXX14_CONSTEXPR Rational operator /=(const Rational&);

  ALG2_CXX14_CONSTEXPR Rational operator +=(const I);
  ALG2_CXX14_CONSTEXPR Rational operator -=(const I);
  ALG2_CXX14_CONSTEXPR Rational operator *=(const I);
  ALG2_CXX14_CONSTEXPR Rational operator /=(const I);
  
  ALG2_CXX11_CONSTEXPR Rational operator +(const Rational&) const;
  ALG2_CXX11_CONSTEXPR Rational operator -(const Rational&) const;
  ALG2_CXX11_CONSTEXPR Rational operator *(const Rational&) const;
  ALG2_CXX11_CONSTEXPR Rational operator /(const Rational&) const;

  ALG2_CXX11_CONSTEXPR Rational operator +(const I) const;
  ALG2_CXX11_CONSTEXPR Rational operator -(const I) const;
  ALG2_CXX11_CONSTEXPR Rational operator *(const I) const;
  ALG2_CXX11_CONSTEXPR Rational operator /(const I) const;

  template <typename N> friend ALG2_CXX11_CONSTEXPR Rational operator +(const N, const Rational<N>&);
  template <typename N> friend ALG2_CXX11_CONSTEXPR Rational operator -(const N, const Rational<N>&);
  template <typename N> friend ALG2_CXX11_CONSTEXPR Rational operator *(const N, const Rational<N>&);
  template <typename N> friend ALG2_CXX11_CONSTEXPR Rational operator /(const N, const Rational<N>&);

  template <typename N> friend ALG2_CXX11_CONSTEXPR bool operator ==(const Rational<N>&, const Rational<N>&);
  template <typename N> friend ALG2_CXX11_CONSTEXPR bool operator !=(const Rational<N>&, const Rational<N>&);
  template <typename N> friend ALG2_CXX11_CONSTEXPR bool operator >=(const Rational<N>&, const Rational<N>&);
  template <typename N> friend ALG2_CXX11_CONSTEXPR bool operator <=(const Rational<N>&, const Rational<N>&);
  template <typename N> friend ALG2_CXX11_CONSTEXPR bool operator <(const Rational<N>&, const Rational<N>&);
  template <typename N> friend ALG2_CXX11_CONSTEXPR bool operator >(const Rational<N>&, const Rational<N>&);

  template <typename N> friend ALG2_CXX11_CONSTEXPR bool operator ==(const Rational<N>&, const N);
  template <typename N> friend ALG2_CXX11_CONSTEXPR bool operator !=(const Rational<N>&, const N);
  template <typename N> friend ALG2_CXX11_CONSTEXPR bool operator >=(const Rational<N>&, const N);
  template <typename N> friend ALG2_CXX11_CONSTEXPR bool operator <=(const Rational<N>&, const N);
  template <typename N> friend ALG2_CXX11_CONSTEXPR bool operator <(const Rational<N>&, const N);
  template <typename N> friend ALG2_CXX11_CONSTEXPR bool operator >(const Rational<N>&, const N);

  template <typename N> friend ALG2_CXX11_CONSTEXPR bool operator ==(const N, const Rational<N>&);
  template <typename N> friend ALG2_CXX11_CONSTEXPR bool operator !=(const N, const Rational<N>&);
  template <typename N> friend ALG2_CXX11_CONSTEXPR bool operator >=(const N, const Rational<N>&);
  template <typename N> friend ALG2_CXX11_CONSTEXPR bool operator <=(const N, const Rational<N>&);
  template <typename N> friend ALG2_CXX11_CONSTEXPR bool operator <(const N, const Rational<N>&);
  template <typename N> friend ALG2_CXX11_CONSTEXPR bool operator >(const N, const Rational<N>&);

  template <typename N> friend std::ostream& operator <<(std::ostream&, const Rational<N>&);
  template <typename N> friend std::istream& operator >>(std::istream&, Rational<N>&);
};

#include"details/rational.hpp"

} // end of namespace Alg

#endif // ALG_RATIONAL_HPP
