#include <iostream>
using namespace std;
#define MOD 1000000007

long long power(long long n, long long m)
{
    long long ret = 1;
    while (m)
    {
        if (m & 1)
            ret = ret * n % MOD;
        m = m / 2;
        n = n * n % MOD;
    }
    return ret;
}

void solve()
{
    long long ans = 0, N, S;
    int M;
    cin >> M;
    for (int i = 0; i < M; i++)
    {
        cin >> N >> S;
        ans += (S * (power(N, MOD - 2))) % MOD;
    }
    cout << ans % MOD;
}

int main()
{
    solve();
    return 0;
}