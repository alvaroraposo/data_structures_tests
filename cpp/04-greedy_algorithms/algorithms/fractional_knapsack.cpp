#include <iostream>
#include <vector>
#include <algorithm> 

using std::vector;

double get_optimal_value(int capacity, vector<int> weights, vector<int> values) {
  double value = 0.0;
  double sac = 0;
  vector<double> ratioVector(weights.size());
  vector<double> ratioVectorSorted(weights.size());

  for(int i = 0; i < weights.size(); i++) {
    ratioVector[i] = double(values[i]) / weights[i];    
    ratioVectorSorted[i] = double(values[i]) / weights[i];  
  }

  sort(ratioVectorSorted.begin(), ratioVectorSorted.end(), std::greater <>());

  for(int i = 0; i < ratioVectorSorted.size(); i++) {
    for(int j = 0; j < ratioVector.size(); j++) {
      if(ratioVector[j] == ratioVectorSorted[i]) {
        if(sac + weights[j] <= capacity) {
          sac = sac + weights[j];
          value = value + values[j];
        }
        else if(sac < capacity) {
          double left = capacity - sac;
          double ratio =double(values[j]) / weights[j];
          sac = sac + left;
          value = value + (ratio * left);
        }
        break;
      }
    }
  }
  // write your code here

  return value;
}

int main() {
  int n;
  int capacity;
  std::cin >> n >> capacity;
  vector<int> values(n);
  vector<int> weights(n);
  for (int i = 0; i < n; i++) {
    std::cin >> values[i] >> weights[i];
  }

  double optimal_value = get_optimal_value(capacity, weights, values);

  std::cout.precision(10);
  std::cout << optimal_value << std::endl;
  return 0;
}
