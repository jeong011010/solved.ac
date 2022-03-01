#include <iostream>
using namespace std;

long long DP[101][10];
int N;

void solve()
{
    for (int i = 0; i < 10; i++)
        DP[1][i] = 1;
    cin >> N;
    for (int i = 2; i <= N; i++)
    {
        DP[i][0] = DP[i - 1][1] % 1000000000;
        DP[i][9] = DP[i - 1][8] % 1000000000;
        for (int j = 1; j < 9; j++)
        {
            DP[i][j] = (DP[i - 1][j - 1] + DP[i - 1][j + 1]) % 1000000000;
        }
    }
    int ans = 0;
    for (int i = 1; i < 10; i++)
    {
        ans = (ans + DP[N][i]) % 1000000000;
    }
    cout << ans % 1000000000;
}

int main()
{
    solve();
    return 0;
}