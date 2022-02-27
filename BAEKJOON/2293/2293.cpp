#include <iostream>
using namespace std;

int DP[10001];
int Coin[101];
int n, k;

void solve()
{
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
        cin >> Coin[i];
    DP[0] = 1;
    for (int i = 1; i <= n; i++)
    {
        for (int j = Coin[i]; j <= k; j++)
        {
            DP[j] += DP[j - Coin[i]];
        }
    }
    cout << DP[k];
}

int main()
{
    solve();
    return 0;
}