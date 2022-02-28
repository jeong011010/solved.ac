#include <iostream>
using namespace std;

int N;
int DP[1001], Card[1001];

void solve()
{
    cin >> N;
    int tmp;
    for (int i = 1; i <= N; i++)
    {
        cin >> tmp;
        DP[i] = Card[i] = tmp;
    }
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j < i; j++)
        {
            DP[i] = max(DP[i], DP[i - j] + Card[j]);
        }
    }
    cout << DP[N];
}

int main()
{
    solve();
    return 0;
}