#include <iostream>
#include <vector>
#include <algorithm>

long long MaxPairwiseProduct(const std::vector<long long>& numbers) {
    int n = numbers.size();
    long long first = 0;
    long long second = 0;

    for (long long x = 0; x < n; ++x) {
        if(numbers[x] >= first) {
            second = first;
            first = numbers[x];
        } else if(numbers[x] > second) {
            second = numbers[x];
        }
    }

    return (first * second);
}

int main() {
    int n;
    std::cin >> n;
    std::vector<long long> numbers(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> numbers[i];
    }

    std::cout << MaxPairwiseProduct(numbers) << "\n";
    return 0;
}
