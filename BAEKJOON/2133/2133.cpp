#include <iostream>
using namespace std;

int N;
int DP[35];

void solve()
{
    cin >> N;
    DP[0] = 1;
    DP[1] = 0;
    DP[2] = 3;
    for (int i = 4; i <= N; i = i + 2)
    {
        DP[i] = DP[i - 2] * DP[2];
        for (int j = i - 4; j >= 0; j = j - 2)
        {
            DP[i] = DP[i] + (DP[j] * 2);
        }
    }
    cout << DP[N];
}

int main()
{
    solve();
    return 0;
}