#include <iostream>
#include <vector>
using std::vector;

long long get_fibonacci_partial_sum_naive(long long from, long long to) {
    long long sum = 0;

    long long current = 0;
    long long next  = 1;

    for (long long i = 0; i <= to; ++i) {
        if (i >= from) {
            sum += current;
        }

        long long new_current = next;
        next = next + current;
        current = new_current;
    }

    return sum % 10;
}

//https://stackoverflow.com/questions/62306496/last-digit-of-the-sum-of-fibonacci-numbers-in-range-a-to-b

long long calc_fib(long long a,long long b) {    
    if(b <= 2) return b; 
    a = a % 60;
    b = b % 60;
    long long prev = 1; 
    long long curr = 1; 
    long long sum = a < 3 ? 2 : 0;
    
    if(a > b) {
        b = b + 60;
    }

    for(long long i = 3; i <= b; ++i){
        curr += prev;
        prev = curr - prev;
        if(i >= a){
            sum = (sum + curr) % 10;
        }       
        prev %= 10;
        curr %= 10;
    }

    return sum;
}

long long fibonacci_sum_fast(long long from, long long to) {
    return calc_fib(from, to);
}

int main() {
    long long from, to;
    std::cin >> from >> to;
    std::cout << fibonacci_sum_fast(from, to) << '\n';
}
