#include <iostream>
using namespace std;

int n, ans;
int dp[100001];

void solve()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> dp[i];
    }
    ans = dp[0];
    for (int i = 1; i < n; i++)
    {
        dp[i] = max(dp[i], dp[i - 1] + dp[i]);
        ans = max(ans, dp[i]);
    }
    cout << ans;
}

int main()
{
    solve();
    return 0;
}