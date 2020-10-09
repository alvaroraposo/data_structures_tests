#include <iostream>

long long lcm_naive(int a, int b) {
  for (long l = 1; l <= (long long) a * b; ++l)
    if (l % a == 0 && l % b == 0)
      return l;

  return (long long) a * b;
}

long long gcd_fast(long long a, long long b) {
  long long current_gcd = (a < b) ? a : b;

  while(current_gcd >= 1) {

    long long mod1 = a % current_gcd;
    long long mod2 = b % current_gcd;
    
    if(mod1 == 0 && mod2 == 0)
      return current_gcd;

    long long next = (mod1 < mod2 && mod1 != 0) ? mod1 : (mod2 != 0) ? mod2 : mod1;
    
    current_gcd = current_gcd - next;
  }
  
  return current_gcd;
}

long long lcm_fast(long long a, long long b) {
  long long result = (a * b) / gcd_fast(a, b);

  return result;
}

int main() {
  long long a, b;
  std::cin >> a >> b;
  std::cout << lcm_fast(a, b) << std::endl;
  return 0;
}
