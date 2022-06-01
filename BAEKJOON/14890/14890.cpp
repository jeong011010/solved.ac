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
    int ans = N;
    for (int i = 0; i < N; i++)
    {
        int n = board[i][0];
        int up = 1, down = 0;
        for (int j = 1; j < N; j++)
        {
            if (board[i][j] == n)
            {
                up++;
            }
            else if (board[i][j] == n - 1)
            {
                n--;
                down++;
            }
            else if (board[i][j] == n + 1)
            {
                if (up == L)
                {
                    up = 1;
                }
                else
                {
                    ans--;
                    break;
                }
            }
        }
    }
}

void solve()
{
    input();
}

int main()
{
    solve();
    return 0;
}