#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
#include <numeric>
#include <sstream>

using std::vector;
using std::string;

template <typename T>
vector<size_t> sort_indexes(const vector<T> &v) {

  // initialize original index locations
  vector<size_t> idx(v.size());
  iota(idx.begin(), idx.end(), 0);

  // sort indexes based on comparing values in v
  // using std::stable_sort instead of std::sort
  // to avoid unnecessary index re-orderings
  // when v contains elements of equal values 
  stable_sort(idx.begin(), idx.end(),
       [&v](size_t i1, size_t i2) {return v[i1] > v[i2];});

  return idx;
}

string largest_number(vector<string> a) {
  std::stringstream ret;
  int digits = 0;

  for (size_t i = 0; i < a.size(); i++) {
    for(size_t j = i+1; j < a.size(); j++) {
      if(i == j)
        continue;

      string strComb1 = a[i] + a[j];
      string strComb2 = a[j] + a[i];    
      int comb1 = stoi(strComb1);
      int comb2 = stoi(strComb2);
      
      if(comb2 > comb1) {
        string aux = a[i];
        a[i] = a[j];
        a[j] = aux;
      }      
    }
  }

  for (size_t i = 0; i < a.size(); i++) {
    ret << a[i];
  }


  string result;
  ret >> result;
  return result;
}

int main() {
  int n;
  std::cin >> n;
  vector<string> a(n);
  for (size_t i = 0; i < a.size(); i++) {
    std::cin >> a[i];
  }
  std::cout << largest_number(a);

  return 0;
}
