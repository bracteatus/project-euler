#include <iostream>

int main (void) {
  long long solution{};
  long long powers{};
  for (int i{1}; i <= 1000; ++i) {
    powers = 1;
    for (int j{0}; j < i; ++j) {
      powers = (powers * i) % 10000000000;
    }
    solution = (solution + powers) % 10000000000;
  }

  std::cout << solution << std::endl;
  return 0;
}
