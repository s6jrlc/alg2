#include"rational.hpp"
//#include"vector.hpp"
#include<iostream>

// for test
int main() {
  constexpr Alg::Rational<int> q(3, 5), r(6, 10);
  if (q == r) std::cout << "check" << std::endl;
  std::cout << q * r << std::endl;
  std::cout << __cpp_constexpr << std::endl;
  return 0;
}
