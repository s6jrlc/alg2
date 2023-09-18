//
// alg2: test.cpp
//

#include<iostream>
#include<alg2/rational.hpp>
#include<alg2/complex.hpp>
#include<alg2/quaternion.hpp>
#include<alg2/io.hpp>

// --------------------------------------------------------------------------------------------
// test: main
// --------------------------------------------------------------------------------------------

int main() {
  using Alg2::Util::PI;
  constexpr Alg2::Rational<> f(3, 5), g(1, 2), h(2, 1);
  constexpr Alg2::complex<float> c(0, 1);
  constexpr Alg2::quaternion<float> q(0, 0, 1, 1);

  std::cout << "Hello test world!" << std::endl;
  if (h >= 2) {
    std::cout << f << std::endl;
    std::cout << c*c << std::endl;
    std::cout << q << std::endl;
  }
  return 0;
}
