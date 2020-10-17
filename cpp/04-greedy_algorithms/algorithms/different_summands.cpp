#include <iostream>
#include <vector>
#include <algorithm>

using std::vector;

vector<int> optimal_summands(int n) {
  int left = n;
  int init = 1;
  int count = 1;
  vector<int> summands;

  if(n <= 2) {
    summands.push_back(n);
    return summands;
  }

  while(count < n) {
    if(std::find(summands.begin(), summands.end(), count) == summands.end()) {
      /* v does not contain x */
      left = left - count;
//      std::cout << left << " left " << count << " count \n";      

      if(left < 0) {
        count = ++init;
        left = n;
        summands.clear();
        continue;
      }
            
      if(count > left && left != 0) {
        left += count;
        count++;
        continue;
      }            
      
      summands.push_back(count);
      
      if(left == 0)
        break;
    }

    if(left > 0)
      count++;
    else if(left == 0)
      break;
  }


  //write your code here
  return summands;
}

int main() {
  int n;
  std::cin >> n;
  vector<int> summands = optimal_summands(n);
  std::cout << summands.size() << '\n';
  for (size_t i = 0; i < summands.size(); ++i) {
    std::cout << summands[i] << ' ';
  }
}
