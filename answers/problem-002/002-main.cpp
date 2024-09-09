#include <iostream>

int main (void) {
  int u{};
  long s{};

  for (int x{0}, y{1}; y <= 4000000; ) {
    // add only even Fibonacci values
    s += y * !(y % 2);

    // find next Fibonacci values
    u = y;
    y = x + y;
    x = u;
  }

  std::cout << s << std::endl;
}
