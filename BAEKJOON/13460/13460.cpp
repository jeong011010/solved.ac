#include <iostream>
#include <queue>
#include <vector>
using namespace std;

string arr[10];
int Rx, Ry, Bx, By, Ox, Oy;
int N, M;
int My[4] = {0, -1, 0, 1};
int Mx[4] = {1, 0, -1, 0};

typedef struct ball
{
    int ry, rx, by, bx, m = 0;
} ball;

void bfs()
{
    queue<ball> B;
    B.push({Ry, Rx, By, Bx});
    while (!B.empty())
    {
        ball b = B.front();
        B.pop();
        for (int i = 0; i < 4; i++)
        {
            int rym = b.ry + My[i];
            int rxm = b.rx + Mx[i];
            int bym = b.by + My[i];
            int bxm = b.bx + Mx[i];
            while (arr[rym][rxm] == '.' || arr[bym][bxm] == '.')
            {
                if (arr[rym][rxm] == '.')
                {
                    b.ry += My[i];
                    b.rx += Mx[i];
                }
                if (arr[bym][bxm] == '.')
                {
                    b.ry += My[i];
                    b.rx += Mx[i];
                    if (arr[rym][rxm] == '.')
                    {
                        b.ry += My[i];
                        b.rx += Mx[i];
                    }
                }
                if (arr[rym][rxm] == 'O')
                {
                }
            }
        }
    }
}

void solve()
{
    int x, y;
    cin >> N >> M;
    for (int i = 0; i < N; i++)
    {
        cin >> arr[i];
        for (int j = 0; j < M; j++)
        {
            if (arr[i][j] == 'R')
            {
                arr[i][j] == '.';
                Ry = i;
                Rx = j;
            }
            else if (arr[i][j] == 'B')
            {
                arr[i][j] == '.';
                By = i;
                Bx = j;
            }
            if (arr[i][j] == 'O')
            {
                Oy = i;
                Ox = j;
            }
        }
    }
}

int main()
{
    solve();
    return 0;
}