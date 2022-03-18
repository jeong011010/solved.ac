#include <iostream>
using namespace std;

int N, K;
int dp[1001][1001];
void solve()
{
    cin >> N >> K;
    for (int i = 0; i <= N; i++)
    {
        dp[i][0] = 1;
    }
    for (int i = 0; i <= K; i++)
    {
        dp[i][i] = 1;
    }
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j < N; j++)
        {
            dp[i][j] = (dp[i - 1][j] + dp[i - 1][j - 1]) % 10007;
        }
    }
    cout << dp[N][K] % 10007;
}

int main()
{
    solve();
    return 0;
}