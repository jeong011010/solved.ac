#include <iostream>
using namespace std;

long long M[2][2] = {{1, 1}, {1, 0}};
long long n;

void multiply(long long F[2][2], long long M[2][2])
{
    long long a = F[0][0] * M[0][0] + F[0][1] * M[1][0];
    long long b = F[0][0] * M[0][1] + F[0][1] * M[1][1];
    long long c = F[1][0] * M[0][0] + F[1][1] * M[1][0];
    long long d = F[1][0] * M[0][1] + F[1][1] * M[1][1];
    F[0][0] = a % 1000000007;
    F[0][1] = b % 1000000007;
    F[1][0] = c % 1000000007;
    F[1][1] = d % 1000000007;
}

void power(long long F[2][2], long long n)
{
    if (n == 0 || n == 1)
        return;
    power(F, n / 2);
    multiply(F, F);
    if (n % 2 != 0)
        multiply(F, M);
}

int fibo()
{
    if (n == 0)
        return 0;
    long long F[2][2] = {{1, 1}, {1, 0}};
    power(F, n - 1);
    return F[0][0];
}

void solve()
{
    cin >> n;
    cout << fibo();
}

int main()
{
    solve();
    return 0;
}