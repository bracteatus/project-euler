#include <iostream>
#include <fstream>
#include <vector>
#include <set>

namespace {
  std::set<int> primes;

  bool pair_check (int p, int q) {
    bool is_prime_pair{false};

    // left compare
    long long m{1};
    while (m < q) {
      m *= 10;
    }
    long long stringed_q{q};
    stringed_q += m * p;

    // right compare
    long long n{1};
    while (n < p) {
      n *= 10;
    }
    long long stringed_p{p};
    stringed_p += n * q;

    if (stringed_q != (int) stringed_q) return false;
    if (stringed_p != (int) stringed_p) return false;

    // symmetric compare
    is_prime_pair = ::primes.count(stringed_q) && ::primes.count(stringed_p);

    return is_prime_pair;
  }
}

int main (void) {

  // generate primes
  {
    std::ifstream f_data("primes-20000.txt");
    int prime{};
    for (int i{}; i < 20000; ++i) {
      f_data >> prime;
      ::primes.insert(prime);
    }
    f_data.close();
  }

  // find prime pair
  int l{}, r{};
  bool pair_found;
  for (auto xs = ::primes.cbegin(); xs != ::primes.cend() && ! pair_found; ++xs) {
    for (auto ys = ::primes.cbegin(); ys != ::primes.cend() && ! pair_found; ++ys) {
      pair_found = ::pair_check(*xs, *ys);
      if (pair_found) {
	l = *xs;
	r = *ys;
      }
    }
  }

  return 0;
}
