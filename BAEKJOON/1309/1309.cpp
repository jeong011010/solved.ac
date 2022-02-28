#include <iostream>
using namespace std;

long long DP[100002] = {0, 3, 7};
int N;

void solve()
{
    cin >> N;

    for (int i = 3; i <= N; i++)
    {
        DP[i] = (DP[i - 1] * 2 + DP[i - 2]) % 9901;
    }

    cout << DP[N];
}

int main()
{
    solve();
    return 0;
}