#include <iostream>

int get_change(int m) {
  //write your code here
  int total = m;
  int n = 0;
  
  while(total > 0) {
    if(total / 10 >= 1) {
      total -= 10;
      n++;
      continue;
    }

    if(total / 5 >= 1){
      total -= 5;
      n++;
      continue;
    }

    if(total > 0){
      total--;
      n++;
    }
  }

  return n;
}

int main() {
  int m;
  std::cin >> m;
  std::cout << get_change(m) << '\n';
}
