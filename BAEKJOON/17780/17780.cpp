#include <iostream>
#include <deque>
#include <vector>
using namespace std;

int N, K;
int board[14][14];
int ym[4] = {0, 0, -1, 1};
int xm[4] = {1, -1, 0, 0};

struct horse
{
    int y, x, m;
};

vector<horse> h[12];

void bfs()
{
    int size = N;
    deque<horse> dq[12];
    for (int i = 0; i < N; i++)
    {
        if (h[i].size() > 0)
            dq[i].push_back(h[i][0]);
    }
    while (size > 1)
    {
        for (int i = 0; i < N; i++)
        {
            if (dq[i].size() > 0)
            {
                horse h = dq[i].front();
                int m = h.m - 1;
                switch (board[h.y + ym[m]][h.x + xm[m]])
                {
                case 0:
                    break;
                }
            }
        }
    }
}

void solve()
{
    cin >> N >> K;
    for (int i = 0; i <= N + 1; i++)
        board[0][i] = board[N + 1][i] = board[i][0] = board[i][N + 1] = 2;
    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= N; j++)
            cin >> board[i][j];
    int y, x, m;
    for (int i = 0; i < K; i++)
    {
        cin >> y >> x >> m;
        h[i].push_back({y, x, m});
    }
}

int main()
{
    solve();
    return 0;
}