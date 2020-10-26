#include <algorithm>
#include <iostream>
#include <vector>

using std::vector;

int get_majority_element(vector<int> &a, int left, int right) {
  if (left == right) return -1;
  if (left + 1 == right) return a[left];
  sort(a.begin(), a.end());

  int maxCount = -1;
  int count = 1;
  int element = a[0];

  for(int i = 1; i < right; i++) {
    if(a[i] == element) {
      count++;
      if(count > (float(right) / 2))
        return 1;
    }
    else {
      element = a[i];
      count = 1;
    }
  }

  //write your code here
  return -1;
}

int main() {
  int n;
  std::cin >> n;
  vector<int> a(n);
  for (size_t i = 0; i < a.size(); ++i) {
    std::cin >> a[i];
  }
  std::cout << (get_majority_element(a, 0, a.size()) != -1) << '\n';
}
