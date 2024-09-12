#include <iostream>
#include <fstream>
#include <vector>
#include <set>
#include <map>

namespace {
  std::set<int> primes;
  std::vector<int> primev;

  bool pair_check (int p, int q) {
    bool is_prime_pair{false};

    // left compare
    long long m{1ll};
    while (m < q) {
      m *= 10;
    }
    long long stringed_q{q};
    stringed_q += m * p;

    // right compare
    long long n{1ll};
    while (n < p) {
      n *= 10;
    }
    long long stringed_p{p};
    stringed_p += n * q;

    if (stringed_q != (int) stringed_q) return false;
    if (stringed_p != (int) stringed_p) return false;

    // symmetric compare
    is_prime_pair = ::primes.count((int) stringed_q) && ::primes.count((int) stringed_p);

    return is_prime_pair;
  }
}

int main (void) {

  // generate primes
  {
    std::ifstream f_data("primes-answer.txt");
    int prime{};
    for (int i{}; i < 4883394; ++i) {
      f_data >> prime;
      ::primes.insert(prime);
      ::primev.push_back(prime);
    }
    f_data.close();
  }

  // find prime quintuple
  long long prime_sum{};
  long long solution{};
  for (int i{4}; i < 4883394 && !solution; ++i) {
    for (int i_p{3}; i_p < i; ++i_p) {
      if (!::pair_check(::primev[i], ::primev[i_p])) continue;
      for (int i_q{2}; i_q < i_p && !solution; ++i_q) {
	if (!::pair_check(::primev[i], ::primev[i_q])) continue;
	if (!::pair_check(::primev[i_p], ::primev[i_q])) continue;
	for (int i_r{1}; i_r < i_q && !solution; ++i_r) {
	  if (!::pair_check(::primev[i], ::primev[i_r])) continue;
	  if (!::pair_check(::primev[i_p], ::primev[i_r])) continue;
	  if (!::pair_check(::primev[i_q], ::primev[i_r])) continue;
	  for (int i_s{0}; i_s < i_r && !solution; ++i_s) {
	    if (!::pair_check(::primev[i], ::primev[i_s])) continue;
	    if (!::pair_check(::primev[i_p], ::primev[i_s])) continue;
	    if (!::pair_check(::primev[i_q], ::primev[i_s])) continue;
	    if (!::pair_check(::primev[i_r], ::primev[i_s])) continue;
	    prime_sum = ::primev[i];
	    prime_sum += ::primev[i_p];
	    prime_sum += ::primev[i_q];
	    prime_sum += ::primev[i_r];
	    prime_sum += ::primev[i_s];
	    solution = prime_sum;
	  }
	}
      }
    }
  }

  std::cout << solution << std::endl;

  return 0;
}
