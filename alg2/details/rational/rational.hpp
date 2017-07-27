//
// rational.hpp : definition
//


template <typename I> inline ALG2_CXX11_CONSTEXPR Rational<I>::Rational()
: num(0), den(1)
{
  static_assert(std::is_integral<I>::value, "Invalid type for Alg2::Rational");
}
template <typename I> inline ALG2_CXX11_CONSTEXPR Rational<I>::Rational(I n, I d)
: num(n), den((d == 0)? 1 : d)
{
  static_assert(std::is_integral<I>::value, "Invalid type for Alg2::Rational");
}
template <typename I> inline ALG2_CXX11_CONSTEXPR Rational<I>::Rational(I i)
: num(i), den(1)
{
  static_assert(std::is_integral<I>::value, "Invalid type for Alg2::Rational");
}


template <typename I> inline ALG2_CXX14_CONSTEXPR Rational<I> Rational<I>::operator =(const Rational& f)
{
  num = f.num; den = f.den; return *this;
}
template <typename I> inline ALG2_CXX14_CONSTEXPR Rational<I> Rational<I>::operator =(const I i)
{
  num = i; den = 1; return *this;
}

template <typename I> inline ALG2_CXX11_CONSTEXPR Rational<I>::operator float() const
{
  return static_cast<float>(num)/static_cast<float>(den);
}
template <typename I> inline ALG2_CXX11_CONSTEXPR Rational<I>::operator double() const
{
  return static_cast<double>(num)/static_cast<double>(den);
}
template <typename I> inline ALG2_CXX11_CONSTEXPR Rational<I>::operator long double() const
{
  return static_cast<long double>(num)/static_cast<long double>(den);
}
template <typename I> inline ALG2_CXX11_CONSTEXPR Rational<I>::operator bool() const
{
  return (num != 0);
}


template <typename I> inline ALG2_CXX11_CONSTEXPR I Rational<I>::numerator() const
{
  return num;
}
template <typename I> inline I& Rational<I>::numerator()
{
  return num;
}
template <typename I> inline ALG2_CXX11_CONSTEXPR I Rational<I>::denominator() const
{
  return den;
}
template <typename I> inline I& Rational<I>::denominator()
{
  return den;
}


template <typename I> inline ALG2_CXX11_CONSTEXPR Rational<I> Rational<I>::inverse() const
{
  return Rational<I>(den, (num == 0)? 1 : num);
}

template <typename I> inline ALG2_CXX11_CONSTEXPR Rational<I> Rational<I>::reduce() const
{
  return Rational<I>(num/Utility::gcd<I>(num, den), den/Utility::gcd<I>(num, den));
}
template <typename I> inline ALG2_CXX14_CONSTEXPR Rational<I> Rational<I>::reduced()
{
  I i = Utility::gcd<I>(num, den); return Rational(num /= i, den /= i);
}


template <typename I> inline ALG2_CXX11_CONSTEXPR Rational<I> Rational<I>::sum(const Rational<I>& f) const
{
  return Rational<I>(num*f.den + f.num*den, den*f.den);
}
template <typename I> inline ALG2_CXX11_CONSTEXPR Rational<I> Rational<I>::mul(const Rational<I>& f) const
{
  return Rational<I>(num*f.num, den*f.den);
}


template <typename I> inline ALG2_CXX11_CONSTEXPR Rational<I> Rational<I>::operator +() const
{
  return *this;
}
template <typename I> inline ALG2_CXX11_CONSTEXPR Rational<I> Rational<I>::operator -() const
{
  return Rational(-num, den);
}

template <typename I> inline ALG2_CXX14_CONSTEXPR Rational<I>& Rational<I>::operator ++()
{
  num += den; return *this;
}
template <typename I> inline ALG2_CXX14_CONSTEXPR Rational<I>& Rational<I>::operator --()
{
  num -= den; return *this;
}

template <typename I> inline ALG2_CXX14_CONSTEXPR Rational<I> Rational<I>::operator ++(int)
{
  const Rational f(num, den);
  num += den;
  return f;
}
template <typename I> inline ALG2_CXX14_CONSTEXPR Rational<I> Rational<I>::operator --(int)
{
  const Rational f(num, den);
  num -= den;
  return f;
}


template <typename I> inline ALG2_CXX14_CONSTEXPR Rational<I> Rational<I>::operator +=(const Rational& f)
{
  return (*this = sum(f));
}
template <typename I> inline ALG2_CXX14_CONSTEXPR Rational<I> Rational<I>::operator -=(const Rational& f)
{
  return (*this = sum(-f));
}
template <typename I> inline ALG2_CXX14_CONSTEXPR Rational<I> Rational<I>::operator *=(const Rational& f)
{
  return (*this = mul(f));
}
template <typename I> inline ALG2_CXX14_CONSTEXPR Rational<I> Rational<I>::operator /=(const Rational& f)
{
  return (*this = mul(f.inverse()));
}

template <typename I> inline ALG2_CXX14_CONSTEXPR Rational<I> Rational<I>::operator +=(const I i)
{
  return (*this = sum(Rational<I>(i, 1)));
}
template <typename I> inline ALG2_CXX14_CONSTEXPR Rational<I> Rational<I>::operator -=(const I i)
{
  return (*this = sum(Rational<I>(-i, 1)));
}
template <typename I> inline ALG2_CXX14_CONSTEXPR Rational<I> Rational<I>::operator *=(const I i)
{
  return (*this = mul(Rational<I>(i, 1)));
}
template <typename I> inline ALG2_CXX14_CONSTEXPR Rational<I> Rational<I>::operator /=(const I i)
{
  return (*this = mul(Rational<I>(1, i)));
}


template <typename I> inline ALG2_CXX11_CONSTEXPR Rational<I> Rational<I>::operator +(const Rational& f) const
{
  return sum(f);
}
template <typename I> inline ALG2_CXX11_CONSTEXPR Rational<I> Rational<I>::operator -(const Rational& f) const
{
  return sum(-f);
}
template <typename I> inline ALG2_CXX11_CONSTEXPR Rational<I> Rational<I>::operator *(const Rational& f) const
{
  return mul(f);
}
template <typename I> inline ALG2_CXX11_CONSTEXPR Rational<I> Rational<I>::operator /(const Rational& f) const
{
  return mul(f.inverse());
}

template <typename I> inline ALG2_CXX11_CONSTEXPR Rational<I> Rational<I>::operator +(const I i) const
{
  return sum(Rational<I>(i, 1));
}
template <typename I> inline ALG2_CXX11_CONSTEXPR Rational<I> Rational<I>::operator -(const I i) const
{
  return sum(Rational<I>(-i, 1));
}
template <typename I> inline ALG2_CXX11_CONSTEXPR Rational<I> Rational<I>::operator *(const I i) const
{
  return mul(Rational<I>(i, 1));
}
template <typename I> inline ALG2_CXX11_CONSTEXPR Rational<I> Rational<I>::operator /(const I i) const
{
  return mul(Rational<I>(1, i));
}

template <typename I> inline ALG2_CXX11_CONSTEXPR Rational<I> operator +(const I i, const Rational<I> f)
{
  return f.sum(Rational<I>(i, 1));
}
template <typename I> inline ALG2_CXX11_CONSTEXPR Rational<I> operator -(const I i, const Rational<I> f)
{
  return (-f).sum(Rational<I>(i, 1));
}
template <typename I> inline ALG2_CXX11_CONSTEXPR Rational<I> operator *(const I i, const Rational<I> f)
{
  return f.mul(Rational<I>(i, 1));
}
template <typename I> inline ALG2_CXX11_CONSTEXPR Rational<I> operator /(const I i, const Rational<I> f)
{
  return f.inverse().mul(Rational<I>(i, 1));
}

template <typename I> inline ALG2_CXX11_CONSTEXPR bool operator ==(const Rational<I>& lf, const Rational<I>& rf)
{
  return (lf.num*rf.den == rf.num*lf.den);
}
template <typename I> inline ALG2_CXX11_CONSTEXPR bool operator <(const Rational<I>& lf, const Rational<I>& rf)
{
  return (lf.num*rf.den < rf.num*lf.den);
}

template <typename I> inline ALG2_CXX11_CONSTEXPR bool operator ==(const Rational<I>& f, const I i)
{
  return (f.num == i*f.den);
}
template <typename I> inline ALG2_CXX11_CONSTEXPR bool operator >(const Rational<I>& f, const I i)
{
  return (f.num > i*f.den);
}
template <typename I> inline ALG2_CXX11_CONSTEXPR bool operator <(const Rational<I>& f, const I i)
{
  return (f.num < i*f.den);
}
