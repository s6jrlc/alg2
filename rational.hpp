//
// rational.hpp
//

#ifndef ALG_RATIONAL_HPP
#define ALG_RATIONAL_HPP

#include<istream>
#include<ostream>
#include<string>

namespace Alg {

template <typename I = int> void swap(I& m, I& n);
template <typename I = int> I gcd(I m, I n);

template <typename I = int> class Rational
{
  I num, den;

public:

  std::string to_string() const;

  constexpr I numerator() const;
  constexpr I denominator() const;

  constexpr Rational inverse() const;

  constexpr Rational reduce() const;
  constexpr Rational reduced();

private:

  constexpr Rational sum(const Rational&) const;
  constexpr Rational mul(const Rational&) const;

public:

  constexpr Rational();
  constexpr Rational(I n, I d);
  constexpr Rational(I i);

  constexpr Rational operator =(const Rational& f);
  constexpr Rational operator =(const I i);

  constexpr operator float() const;
  constexpr operator double() const;
  constexpr operator long double() const;
  constexpr operator bool() const;

  constexpr Rational operator +() const;
  constexpr Rational operator -() const;

  constexpr Rational& operator ++();
  constexpr Rational& operator --();

  constexpr Rational operator ++(int);
  constexpr Rational operator --(int);

  constexpr Rational operator +=(const Rational&);
  constexpr Rational operator -=(const Rational&);
  constexpr Rational operator *=(const Rational&);
  constexpr Rational operator /=(const Rational&);

  constexpr Rational operator +=(const I);
  constexpr Rational operator -=(const I);
  constexpr Rational operator *=(const I);
  constexpr Rational operator /=(const I);
  
  constexpr Rational operator +(const Rational&) const;
  constexpr Rational operator -(const Rational&) const;
  constexpr Rational operator *(const Rational&) const;
  constexpr Rational operator /(const Rational&) const;

  constexpr Rational operator +(const I) const;
  constexpr Rational operator -(const I) const;
  constexpr Rational operator *(const I) const;
  constexpr Rational operator /(const I) const;

  template <typename N> friend constexpr Rational operator +(const N, const Rational<N>&);
  template <typename N> friend constexpr Rational operator -(const N, const Rational<N>&);
  template <typename N> friend constexpr Rational operator *(const N, const Rational<N>&);
  template <typename N> friend constexpr Rational operator /(const N, const Rational<N>&);

  template <typename N> friend constexpr bool operator ==(const Rational<N>&, const Rational<N>&);
  template <typename N> friend constexpr bool operator !=(const Rational<N>&, const Rational<N>&);
  template <typename N> friend constexpr bool operator >=(const Rational<N>&, const Rational<N>&);
  template <typename N> friend constexpr bool operator <=(const Rational<N>&, const Rational<N>&);
  template <typename N> friend constexpr bool operator <(const Rational<N>&, const Rational<N>&);
  template <typename N> friend constexpr bool operator >(const Rational<N>&, const Rational<N>&);

  template <typename N> friend constexpr bool operator ==(const Rational<N>&, const N);
  template <typename N> friend constexpr bool operator !=(const Rational<N>&, const N);
  template <typename N> friend constexpr bool operator >=(const Rational<N>&, const N);
  template <typename N> friend constexpr bool operator <=(const Rational<N>&, const N);
  template <typename N> friend constexpr bool operator <(const Rational<N>&, const N);
  template <typename N> friend constexpr bool operator >(const Rational<N>&, const N);

  template <typename N> friend constexpr bool operator ==(const N, const Rational<N>&);
  template <typename N> friend constexpr bool operator !=(const N, const Rational<N>&);
  template <typename N> friend constexpr bool operator >=(const N, const Rational<N>&);
  template <typename N> friend constexpr bool operator <=(const N, const Rational<N>&);
  template <typename N> friend constexpr bool operator <(const N, const Rational<N>&);
  template <typename N> friend constexpr bool operator >(const N, const Rational<N>&);

  template <typename N> friend std::ostream& operator <<(std::ostream&, const Rational<N>&);
  template <typename N> friend std::istream& operator >>(std::istream&, Rational<N>&);
};

#include"details/rational.hpp"

} // end of namespace Alg

#endif // ALG_RATIONAL_HPP
