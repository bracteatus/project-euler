#include <iostream>
int main (void) {
  int sum_multiples{};
  for (int x{1}; x < 1000; ++x) {
    sum_multiples += x * (!(x % 3) || !(x % 5));

  }
  std::cout << sum_multiples << std::endl;
  return 0;
}
