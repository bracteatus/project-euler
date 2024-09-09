#include <iostream>
int main (void) {
  long long const target{600851475143ll};

  // 1. find primes less than sqrt(target)
  // 2. calculate largest prime factor

  long long product{1ll};
  long long largest_factor{};

  long long x{2ll};
  bool is_x_prime{true};
  for (int i{1}; i < 62114 && product != target; ) {
    ++x;

    is_x_prime = true;
    for (long long j{2ll}; j < x; ++j) {
      if (!(x % j)) {
	// not prime
	is_x_prime = false;
	break;
      }
    }

    if (is_x_prime) {
      if (!(target % x)) {
	largest_factor = x;
	product *= largest_factor;
      }

      ++i;
    }
  }

  std::cout << ((int) largest_factor) << std::endl;

  return 0;
}
