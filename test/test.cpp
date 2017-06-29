//
// alg2: test.cpp
//

#include<iostream>
#include<alg2/vector.hpp>
#include<alg2/matrix.hpp>
#include<alg2/rational.hpp>
#include<alg2/complex.hpp>
#include<alg2/quaternion.hpp>
#include<alg2/io.hpp>
#include<cmath>

template <size_t ... Idx> ALG2_CXX11_CONSTEXPR Alg2::vector<sizeof...(Idx), size_t> make_array(Alg2::Utility::index_sequence<Idx...>) {
  return { Idx... };
}

int main() {
  using Alg2::Utility::PI;
  constexpr Alg2::vector<3, float> v(1.f, 1.f, 0.f), u(1.f, 0.f, 1.f);
  constexpr Alg2::vector<5, float> x(1.f, 0.f, 0.f, 0.f, 1.f), y(0.f, 1.f, 0.f, 0.f, 1.f);
  constexpr auto z = Alg2::Vector::extend(-Alg2::Vector::truncate(x)-Alg2::Vector::truncate(y));
  constexpr Alg2::Rational<> f(3, 5);
  constexpr Alg2::complex<float> c(0, 1);
  constexpr Alg2::quaternion<float> q(0, 0, 1, 1);
  constexpr Alg2::matrix<3, 3, float> t = {
    1.f, 0.f, 3.f,
    0.f, 1.f, 5.f,
    0.f, 0.f, 1.f,
  };
  constexpr Alg2::matrix<3, 5, float> m = {
    0.f, 1.f, 0.f, 0.f, 0.f,
    1.f, 0.f, 0.f, 0.f, 0.f,
    0.f, 0.f, 1.f, 0.f, 0.f,
  };
  std::cout << "Hello test world!" << std::endl;
  std::cout << t*(u*v) << std::endl;
  std::cout << m*z << std::endl;
  std::cout << f << std::endl;
  std::cout << c << std::endl;
  std::cout << q << std::endl;
  std::cout << t*m << std::endl;
  std::cout << Alg2::Matrix::col_vector(t, 2) << std::endl;
#if 0
  for (auto a : make_array(Alg2::Utility::make_partial_index_sequence<0, 6, 3>())) {
    std::cout << a << std::endl;
  }
  for (long double theta = 0.; theta < 2*PI<long double>(); theta += PI<long double>()/6.) {
    std::cout << theta << ", " << std::setprecision(10) << Alg2::Math::sin(theta) << std::endl;
  }
#endif
  return 0;
}
