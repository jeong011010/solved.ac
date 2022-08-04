#include <iostream>

using namespace std;

int R, C, M, d;
typedef struct shark
{
    int s; // size
    int f; // fast
    int p; // path (1:up, 2:down, 3:right, 4:left)
    int m; // move time
};

shark board[101][101];

void input()
{
    cin >> R >> C >> M;
    int r, c, s, d, z;
    for (int i = 0; i < M; i++)
    {
        cin >> r >> c >> s >> d >> z;
        board[c][r] = {s, d, z, 1};
    } // d
}

int n = 0;
int ans = 0;

void move()
{
    for (int n = 1; n <= C; n++)
    {
        for (int i = 1; i <= R; i++)
        {
            if (board[n][i].s > 0)
            {
                ans += board[n][i].s;
                board[n][i].s = board[n][i].f = board[n][i].p = 0;
                break;
            }
        }
        for (int i = 1; i <= C; i++)
        {
            for (int j = 1; j <= R; j++)
            {
                if (board[i][j].s > 0 && board[i][j].m == n)
                {
                    int tmp_p = board[i][j].p;
                    if (board[i][j].s < 3)
                    { // 위아래
                        board[i][j].s % R if ((board[i][j].s / R) % 2 == 0)
                        {
                        }
                    }
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