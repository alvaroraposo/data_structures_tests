#include <iostream>
#include <vector>

using namespace std;

// void type -> does not return anything
void print (vector<int> input) {
    // range-based for loop (since C++ 11)
    // no brackets -> only one instruction in for loop
    for(int i : input)
        cout << i << ",";
}

vector<int> merge (vector<int> left, vector<int> right, int * inv_count) {
    vector<int> output;
    // multiple variable definition of the same type
    int i=0, j=0;

    // spaces around "<", after "while", before "{" for readability
    while (i < left.size() && j < right.size()) {

        // one-instruction trick again
        if (left[i] <= right[j])
            // i++ is evaluated to <previous value of i> and then increments i
            // this is strictly equivalent to your code, but shorter
            // check the difference with ++i
            output.push_back(left[i++]);
        // else because the two conditions were complementary
        else {
            output.push_back(right[j++]);
            // pointer incrementation
            *inv_count += (left.size() - i);
        }
    }

    // first field of for ommited because there is no need to initialize i
    for(; i < left.size(); i++)
        output.push_back(left[i]);

    for(; j < right.size(); j++)
        output.push_back(right[j]);

    return output;
}

vector<int> merge_sort (vector<int> input, int * inv_count) {
    // no-braces-idiom again
    // spaces around "<" and after "if" for readability
    if (input.size() < 2)
        return input;

    // no need for else keyword because of the return

    // multiple variable definition
    vector<int> left, right;

    int middle = input.size() / 2;

    // one-instruction for loop
    for(int i=0; i < middle; i++)
        left.push_back(input[i]);

    for(int i=middle; i < input.size(); i++)
        right.push_back(input[i]);

    // no need for intermediate variable
    return merge( merge_sort(left, inv_count),
                  merge_sort(right, inv_count),
                  inv_count);
}

// consistent convention : brace on the same line as function name with a space
int main () {
    int n;
    std::cin >> n;
    vector<int> a(n);
    for (size_t i = 0; i < a.size(); i++) {
      std::cin >> a[i];
    }
    // vector initialization (valid only since C++ 11)
    // vector<int> input = {2, 1, 10, 4, 42, 3, 21, 7};

    int inv_count = 0;

    // No need for intermediate variables again, you can chain functions
    merge_sort(a, &inv_count);

    // The value inv_count was modified although not returned
    cout << inv_count << "\n";
}

// using std::vector;

// long long get_number_of_inversions(vector<int> &a, vector<int> &b, size_t left, size_t right) {
//   long long number_of_inversions = 0;
//   if (right <= left + 1) return number_of_inversions;
//   size_t ave = left + (right - left) / 2;
//   number_of_inversions += get_number_of_inversions(a, b, left, ave);
//   number_of_inversions += get_number_of_inversions(a, b, ave, right);
//   //write your code here
//   return number_of_inversions;
// }

// int main() {
//   int n;
//   std::cin >> n;
//   vector<int> a(n);
//   for (size_t i = 0; i < a.size(); i++) {
//     std::cin >> a[i];
//   }
//   vector<int> b(a.size());
//   std::cout << get_number_of_inversions(a, b, 0, a.size()) << '\n';
// }

// using namespace std;
// int merge(vector<int> arr, vector<int> temp, int left, int mid, int right) {
//    int i, j, k;
//    int count = 0;
//    i = left; //i to locate first array location
//    j = mid; //i to locate second array location
//    k = left; //i to locate merged array location
//    while ((i <= mid - 1) && (j <= right)) {
//       if (arr[i] <= arr[j]){ //when left item is less than right item
//       temp[k++] = arr[i++];
//       } else {
//          temp[k++] = arr[j++];
//          count += (mid - i); //find how many convertion is performed
//       }
//    }
//    while (i <= mid - 1) //if first list has remaining item, add them in the list
//       temp[k++] = arr[i++];
//    while (j <= right) //if second list has remaining item, add them in the list
//       temp[k++] = arr[j++];
//    for (i=left; i <= right; i++)
//       arr[i] = temp[i]; //store temp Array to main array
//    return count;
// }

// int mergeSort(vector<int> arr, vector<int> temp, int left, int right){
//    int mid, count = 0;
//    if (right > left) {
//       mid = (right + left)/2; //find mid index of the array
//       count = mergeSort(arr, temp, left, mid); //merge sort left sub array
//       count += mergeSort(arr, temp, mid+1, right); //merge sort right sub array
//       count += merge(arr, temp, left, mid+1, right); //merge two sub arrays
//    }
//    return count;
// }

// int arrInversion(vector<int> arr, int n) {
//    vector<int> temp(n);
//    return mergeSort(arr, temp, 0, n - 1);
// }
// int main() {
//   int n;
//   std::cin >> n;
//   vector<int> a(n);
//   for (size_t i = 0; i < a.size(); i++) {
//     std::cin >> a[i];
//   }
//   // vector<int> b(a.size());
//   // std::cout << get_number_of_inversions(a, b, 0, a.size()) << '\n';
//   //  int arr[] = {1, 5, 6, 4, 20};
//   //  int n = 5;
//    cout << arrInversion(a, n) << "\n";
//    return 1;
// }