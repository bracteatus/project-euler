#include <iostream>
int main (void) {
  long long const target{600851475143ll};

  long long primes[62113] = { 0 };

  // find primes less than sqrt(target)

  long long x{2ll};
  primes[0] = 2;
  bool is_x_prime{true};
  for (int i{1}; i < 62114; ) {
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
      primes[i] = x;
      ++i;
    }
  }

  // calculate largest prime factor

  long long product{1ll};
  long long largest_factor{};
  for (int i{}; i < 62113 && product != target; ++i) {
    if (!(target % primes[i])) {
      largest_factor = primes[i];
      product *= largest_factor;
    }
  }

  std::cout << ((int) largest_factor) << std::endl;

  return 0;
}
