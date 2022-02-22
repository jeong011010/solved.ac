#include <iostream>
using namespace std;

int t, N, ans_cnt = 0;
int ans[51];

void Anti_Fibo(int cnt)
{
    if (ans_cnt == N)
        return;
    if (cnt == N)
    {
        for (int i = 0; i < cnt; i++)
            cout << ans[i] << ' ';
        cout << '\n';
        ans_cnt++;
        return;
    }
    for (int i = 0; i < N; i++)
    {
        bool isIn = false;
        for (int j = 0; j < cnt; j++)
        {
            if (ans[j] == i + 1)
            {
                isIn = true;
                break;
            }
        }
        if (cnt > 1)
            if (ans[cnt - 1] + ans[cnt - 2] == i + 1)
            {
                isIn = true;
                // cout << cnt << ':' << ans[cnt] << ' ' << ans[cnt - 1] << ' ' << i + 1 << '\n';
            }
        if (!isIn)
        {
            ans[cnt] = i + 1;
            Anti_Fibo(cnt + 1);
        }
    }
}

void solve()
{
    cin >> t;
    int n;
    for (int i = 0; i < t; i++)
    {
        ans_cnt = 0;
        cin >> N;
        Anti_Fibo(0);
    }
}

int main()
{
    solve();
    return 0;
}