#include <iostream>

int gcd_naive(int a, int b) {
  int current_gcd = 1;
  for (int d = 2; d <= a && d <= b; d++) {
    if (a % d == 0 && b % d == 0) {
      if (d > current_gcd) {
        current_gcd = d;
      }
    }
  }
  return current_gcd;
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

int main() {
  int a, b;
  std::cin >> a >> b;
  std::cout << gcd_fast(a, b) << std::endl;
  return 0;
}
