#include <iostream>
using namespace std;

int dp[100000];
int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        dp[i] = i;
        for (int j = 1; j * j <= i; j++)
        {
            dp[i] = min(dp[i], dp[i - j * j] + 1);
        }
    }
    cout << dp[n] << '\n';
}