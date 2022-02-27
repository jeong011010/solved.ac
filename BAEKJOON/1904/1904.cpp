#include <iostream>
using namespace std;

int N, DP[1000001];

void solve()
{
    cin >> N;
    DP[1] = 1;
    DP[2] = 2;
    for (int i = 3; i <= N; i++)
    {
        DP[i] = (DP[i - 1] + DP[i - 2]) % 15746;
    }
    cout << DP[N];
}

int main()
{
    solve();
    return 0;
}