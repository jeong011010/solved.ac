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
            int a = b.ry + My[i];
            int b = b.ry + My[i];
            while (arr[b.ry + My[i]][b.rx + Mx[i]] == '.' || arr[b.by + My[i]][b.bx + Mx[i]] == '.')
            {
                if (arr[b.ry + My[i]][b.rx + Mx[i]] == '.')
                {
                    b.ry += My[i];
                    b.rx += Mx[i];
                }
                if (arr[b.by + My[i]][b.bx + Mx[i]] == '.')
                {
                    b.ry += My[i];
                    b.rx += Mx[i];
                    if (arr[b.ry + My[i]][b.rx + Mx[i]] == '.')
                    {
                        b.ry += My[i];
                        b.rx += Mx[i];
                    }
                }
                if (arr[b.ry + My[i]][b.rx + Mx[i]] == 'O')
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