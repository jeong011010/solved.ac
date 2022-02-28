#include <iostream>
using namespace std;

int DP[1002][10];
int sum = 10;
int N;

void solve()
{
    for (int i = 1; i < 10; i++)
        DP[1][i] = 1;
    cin >> N;
    for (int i = 2; i <= N; i++)
    {
        DP[i][1] = 1;
        sum = (sum + DP[i][1]) % 10007;
        for (int j = 2; j < 10; j++)
        {
            DP[i][j] = (DP[i][j - 1] + DP[i - 1][j]) % 10007;
            sum = (sum + DP[i][j]) % 10007;
        }
    }
    cout << sum;
}

int main()
{
    solve();
    return 0;
}