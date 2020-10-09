#include <iostream>
#include <iostream>
using namespace std;

//https://en.wikipedia.org/wiki/Pisano_period
long long calc_fib(long long n) {

    n = (n+2)%60;
    const int size = n + 1;
    int* fib = new int[size];
    fib[0]=0;
    fib[1]=1;
    int res = 1;
    for(int i = 2; i<=n;i++){
        fib[i] = (fib[i-1]%10 + fib[i-2]%10)%10;
        // res = res + fib[i];
    }
    // cout<<fib[n]<<"\n";
    if(fib[n] == 0){
        return 9;
    }
    return (fib[n]%10-1);
}

int fibonacci_sum_naive(long long n) {
    if (n <= 1)
        return n;

    long long previous = 0;
    long long current  = 1;
    long long sum      = 1;

    for (long long i = 0; i < n - 1; ++i) {
        long long tmp_previous = previous;
        previous = current;
        current = tmp_previous + current;
        sum += current;
    }

    return sum % 10;
}

long long fibonacci_sum_fast(long long n) {
    return calc_fib(n);
}

int main() {
    long long n = 0;
    std::cin >> n;
    std::cout << fibonacci_sum_fast(n);
    return 0;
}
