#include <iostream>
using namespace std;

int n;
int dp[10001];
int arr[10001];

int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> arr[i];
    }
    dp[0] = arr[0] = 0;
    dp[1] = arr[1];
    dp[2] = arr[1] + arr[2];
    for (int i = 3; i <= n; i++)
    {
        dp[i] = max(max(arr[i] + dp[i - 2], arr[i] + arr[i - 1] + dp[i - 3]), dp[i - 1]);
    }
    cout << dp[n];
}