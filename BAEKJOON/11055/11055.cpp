#include <iostream>
using namespace std;

int arr[1001];
int dp[1001];
int n;

void solve()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> arr[i];
    }
    dp[0] = 1;
    int m = 0;
    for (int i = 1; i <= n; i++)
    {
        dp[i] = arr[i];
        for (int j = 1; j < i; j++)
        {
            if (arr[j] < arr[i] && dp[i] < dp[j] + arr[i])
            {
                dp[i] = dp[j] + arr[i];
            }
        }
        m = max(m, dp[i]);
    }
    cout << m;
}

int main()
{
    solve();
    return 0;
}