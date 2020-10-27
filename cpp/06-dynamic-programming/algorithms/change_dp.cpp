#include <iostream>
#include <vector>
#define INT_MAX 2147483647

using std::vector;

int CountMinWays(int Coins[], int n, int Money) {
	vector<int> Ways(Money + 1, INT_MAX);
	Ways[0] = 0;
	for (int i = 1; i <= Money; i++) {    
		for (int c = 0; c < n; c++) {
      if(i < Coins[c])
        continue;

      int index = i - Coins[c];
      int sub_res = Ways[index];
      if (sub_res != INT_MAX && sub_res + 1 < Ways[i])
        Ways[i] = sub_res + 1;
		}
	}
	return Ways[Money];
}

// 1, 3, 4
int main() {
  int m;
  std::cin >> m;
  int Coins[3] = { 1,3,4 };
  std::cout << CountMinWays(Coins, 3, m) << '\n';
}
