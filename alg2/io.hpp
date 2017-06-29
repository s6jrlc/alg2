//
// io.hpp
//

#ifndef ALG2_IO_HPP
#define ALG2_IO_HPP


#include<iostream>
#include<iomanip>


namespace Alg2{


#ifdef ALG2_USE_RATIONAL
template <typename I>
  inline std::ostream& operator <<(std::ostream& os, const Rational<I>& f)
{
  return
  (
   (f.denominator() == 0)?
   (os << f.numerator())
   :
   (os << f.numerator() << "/" << f.denominator())
   );
}
template <typename I>
  inline std::istream& operator >>(std::istream& is, Rational<I>& f)
{
  return (is >> f.numerator() >> f.denominator());
}
#endif

#ifdef ALG2_USE_VECTOR
template <size_t N, typename R>
  inline std::ostream& operator <<(std::ostream& os, const vector<N, R>& v)
{
  size_t i = 0;
  os << "[";
  while (true)
  {
    os << std::setw(10) << v[i];
    if (++i >= N) break;
    os << ",";
  }
  return (os << "]");
}
#endif

#ifdef ALG2_USE_MATRIX
template <size_t M, size_t N, typename R>
  inline std::ostream& operator <<(std::ostream& os, const matrix<M, N, R>& m)
{
  size_t i=0, j=0;
  os << "[";
  while (true)
  {
    while (true)
    {
      os << std::setw(5) << m(i, j);
      if (++j >= N) break;
    }
    os << "]\n";
    if (++i >= M) break;
    j=0;
    os << "[";
  }
  return os;
}
#endif

#ifdef ALG2_USE_COMPLEX
template <typename R>
  inline std::ostream& operator <<(std::ostream& os, const complex<R>& z)
{
  if (z.re() != (R)0) os << z.re() << " " << std::showpos;
  if (z.im() != (R)0) os << z.im() << "i";
  if (z.re() == (R)0 && z.im() == (R)0) os << 0;
  return (os << std::noshowpos);
}
#endif

#ifdef ALG2_USE_QUATERNION
template <typename R>
  inline std::ostream& operator <<(std::ostream& os, const quaternion<R>& z)
{
  if (z.re() != (R)0) os << z.re() << " " << std::showpos;
  if (z.im1() != (R)0) os << z.im1() << "i " << std::showpos;
  if (z.im2() != (R)0) os << z.im2() << "j " << std::showpos;
  if (z.im3() != (R)0) os << z.im3() << "k";
  if (z.re() == (R)0 && z.im1() == (R)0 && z.im2() == (R)0 && z.im3() == (R)0) os << 0;
  return (os << std::noshowpos);
}
#endif


}


#endif
