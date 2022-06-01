#include <iostream>
using namespace std;

int board[101][101];

int N, L;

void input()
{
    cin >> N >> L;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cin >> board[i][j];
        }
    }
}

void checking()
{
    int ans = N * 2;
    for (int k = 0; k < 2; k++)
    {
        for (int i = 0; i < N; i++)
        {
            int n = k == 0 ? board[i][0] : board[0][i];
            int up = 1, down = 0;
            for (int j = 1; j < N; j++)
            {
                int tile = k == 0 ? board[i][j] : board[j][i];
                if (tile == n)
                {
                    if (down > 0)
                    {
                        down--;
                    }
                    else
                        up++;
                }
                else if (tile == n - 1)
                {
                    down--;
                    if (down > 0)
                    {
                        ans--;
                        down = 0;
                        // cout << k << ' ' << i << ',' << j << ":1\n";
                        break;
                    }
                    n--;
                    down = L;
                }
                else if (tile == n + 1)
                {
                    if (down != 0)
                    {
                        ans--;
                        down = 0;
                        // cout << k << ' ' << i << ',' << j << ":2\n";
                        break;
                    }
                    if (up >= L)
                    {
                        n++;
                        up = 1;
                    }
                    else
                    {
                        ans--;
                        down = 0;
                        // cout << k << ' ' << i << ',' << j << ":3\n";
                        break;
                    }
                }
                else
                {
                    ans--;
                    down = 0;
                    break;
                }
            }
            // cout << down << '\n';
            if (down > 1)
                ans--;
        }
    }
    cout << ans;
}

void solve()
{
    input();
    checking();
}

int main()
{
    solve();
    return 0;
}