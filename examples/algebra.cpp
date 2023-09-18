//
// alg2: test.cpp
//

#include<iostream>
#include<alg2/vector.hpp>
#include<alg2/matrix.hpp>
#include<alg2/io.hpp>

// --------------------------------------------------------------------------------------------
// test: main
// --------------------------------------------------------------------------------------------

int main() {
  using Alg2::Util::PI;
  constexpr Alg2::vector<3, float> v(1.f, 1.f, 0.f), u(1.f, 0.f, 1.f);
  constexpr Alg2::vector<5, float> x(1.f, 0.f, 0.f, 0.f, 1.f), y(0.f, 1.f, 0.f, 0.f, 1.f);
  constexpr Alg2::matrix<3, 3, float> t = {
    1.f, 0.f, 3.f,
    0.f, 1.f, 5.f,
    0.f, 0.f, 1.f,
  };
  constexpr Alg2::matrix<4, 3, float> s = {
    1.f, 0.f, 3.f,
    0.f, 1.f, 5.f,
    0.f, 0.f, 1.f,
    1.f, 1.f, 1.f,
  };
  constexpr Alg2::matrix<3, 5, float> m = {
    0.f, 1.f, 0.f, 0.f, 0.f,
    1.f, 0.f, 0.f, 0.f, 0.f,
    0.f, 0.f, 1.f, 0.f, 0.f,
  };
  constexpr Alg2::matrix<4, 4, float> luee = {
    8.f, 16.f, 24.f, 32.f,
    2.f, 7.f, 12.f, 17.f,
    6.f, 17.f, 32.f, 59.f,
    7.f, 22.f, 46.f, 105.f,
  };
  constexpr Alg2::matrix<4, 5, float> et = {
    8.f, 16.f, 24.f, 32.f, 160.f,
    2.f, 7.f, 12.f, 17.f, 70.f,
    6.f, 17.f, 32.f, 59.f, 198.f,
    7.f, 22.f, 46.f, 105.f, 291.f
  };
  constexpr auto z = Alg2::Vector::extend(-Alg2::Vector::truncate(x)-Alg2::Vector::truncate(y));
  constexpr auto mul = t*(u^v);
  constexpr auto mat = s*m;
  constexpr auto tmt = Alg2::Util::truncate_left_col(mat);
  constexpr auto mz = m*z;
  constexpr auto lum = Alg2::Util::Sq::LU::decomposition(luee);

  std::cout << "Hello test world!" << std::endl;
  if (1) {
    std::cout << mul << std::endl;
    std::cout << mz << std::endl;
    std::cout << tmt << std::endl;
    std::cout << lum << std::endl;
    std::cout << Alg2::Util::GJE::elimination(et) << std::endl;
  }

  return 0;
}
