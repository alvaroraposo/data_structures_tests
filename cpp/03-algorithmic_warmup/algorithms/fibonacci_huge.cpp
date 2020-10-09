#include <iostream>
#include <vector>
#define REP(i,n) for (int i = 1; i <= n; i++)
using namespace std;

typedef long long ll;
typedef vector<vector<ll> > matrix;
const int K = 2;

// computes A * B
matrix mul(matrix A, matrix B, int m)
{
    matrix C(K+1, vector<ll>(K+1));
    REP(i, K) REP(j, K) REP(k, K)
        C[i][j] = (C[i][j] + A[i][k] * B[k][j]) % m;
    return C;
}

// computes A ^ p
matrix pow(matrix A, long long p, int m)
{
    if (p == 1)
        return A;
    if (p % 2)
        return mul(A, pow(A, p-1, m), m);
    matrix X = pow(A, p/2, m);
    return mul(X, X, m);
}

// returns the N-th term of Fibonacci sequence
int fib(long long N, int m)
{
    // create vector F1
    vector<ll> F1(K+1);
    F1[1] = 1;
    F1[2] = 1;

    // create matrix T
    matrix T(K+1, vector<ll>(K+1));
    T[1][1] = 0, T[1][2] = 1;
    T[2][1] = 1, T[2][2] = 1;

    // raise T to the (N-1)th power
    if (N == 1)
        return 1;
    T = pow(T, N-1, m);

    // the answer is the first row of T . F1
    ll res = 0;
    REP(i, K)
        res = (res + T[1][i] * F1[i]) % m;
    return res;
}

long long get_fibonacci_huge_naive(long long n, long long m) {
    if (n <= 1)
        return n;

    long long previous = 0;
    long long current  = 1;

    for (long long i = 0; i < n - 1; ++i) {
        long long tmp_previous = previous;
        previous = current;
        current = tmp_previous + current;
    }

    return current % m;
}

int main() {
    long long n, m;
    std::cin >> n >> m;
    std::cout << fib(n, m) << '\n';
    return 0;
}
