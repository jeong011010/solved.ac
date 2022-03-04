#include <iostream>
using namespace std;
#define SIZE 17

int DP[SIZE], T[SIZE], P[SIZE], N;

void solve()
{
    int ans = 0;
    cin >> N;
    for (int i = 1; i <= N; i++)
    {
        cin >> T[i] >> P[i];
    }

    for (int i = 1; i <= N; i++)
    {
        if (i + T[i] <= N + 1)
        {
            DP[i + T[i]] = max(DP[i] + P[i], DP[i + T[i]]);
            ans = max(ans, DP[i + T[i]]);
        }
        DP[i + 1] = max(DP[i + 1], DP[i]);
        ans = max(ans, DP[i + 1]);
    }
    cout << ans;
}

int main()
{
    solve();
    return 0;
}