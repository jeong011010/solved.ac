#include <iostream>
using namespace std;

int coin[6] = {500, 100, 50, 10, 5, 1};
int N;

void solve()
{
    cin >> N;
    N = 1000 - N;
    int tmp = 0, ans = 0;
    while (N != 0)
    {
        if (N >= coin[tmp])
        {
            ans += N / coin[tmp];
            N %= coin[tmp];
        }
        tmp++;
    }
    cout << ans;
}

int main()
{
    solve();
    return 0;
}