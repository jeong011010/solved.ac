#include <iostream>
using namespace std;

int dp[1000];
int arr[1000];
int n, ans = 1;

void solve()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    dp[0] = 1;
    for (int i = 1; i < n; i++)
    {
        dp[i] = 1;
        for (int j = 0; j < i; j++)
        {
            if (dp[j] + 1 > dp[i] && arr[j] > arr[i])
            {
                dp[i] = dp[j] + 1;
                ans = max(ans, dp[i]);
            }
        }
    }
    cout << ans;
}

int main()
{
    solve();
    return 0;
}