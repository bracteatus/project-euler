#include <iostream>

namespace {
  int constexpr u{100000};
  int constexpr t{1};
  bool is_sym (int z) {
    bool palindrome{true};
    int d_l{}, d_r{};
    for (int l{u}, r{t}; l > r && palindrome; ) {
      // calculate digits
      d_l = (z / l) % 10;
      d_r = (z / r) % 10;

      // compare digits
      palindrome &= d_l == d_r;
      l /= 10;
      r *= 10;
    }

    return palindrome;
  }
}

int main (void) {
  int z{}, p{};
  for (int x{999}; x >= 0; --x) {
    for (int y{999}; y >= 0; --y) {
      z = x * y;
      bool is_palindrome = is_sym(z);
      if (is_palindrome && p < z) {
	p = z;
      }
    }
  }

  std::cout << p << std::endl;

  return 0;
}
