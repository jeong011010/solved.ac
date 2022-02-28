#include <iostream>
using namespace std;

int N, K;
long long Arr[201][201];
long long DP[201];

void solve()
{
    cin >> N >> K;
    for (int i = 1; i < K; i++)
    {
        Arr[i][1] = 1;
    }
    for (int i = 1; i < K; i++)
    {
        for (int j = 2; j <= N + 1; j++)
        {
            Arr[i][j] = (Arr[i][j - 1] + Arr[i - 1][j]) % 1000000000;
        }
    }

    DP[0] = 1;
    for (int i = 1; i <= N; i++)
    {
        DP[i] = (DP[i - 1] + Arr[K - 1][i + 1]) % 1000000000;
    }
    cout << DP[N];
}

int main()
{
    solve();
    return 0;
}