#include <iostream>
using namespace std;

int N, M, H;

int lad[10][30];

void init()
{
    for (int i = 0; i < H; i++)
    {
        for (int j = 0; j < N; j++)
        {
            lad[i][j] = j;
        }
    }
}

void input()
{
    cin >> N >> M >> H;
    int a, b; // N, H
    init();
    for (int i = 0; i < M; i++)
    {
        cin >> a >> b;
        lad[b - 1][a - 1] = a;
        lad[b - 1][a] = a - 1;
    }
}

int n = 0, ans = 4;

void run()
{
    for (int i = 0; i < N; i++)
    {
        int line = i;
        for (int j = 0; j < H; j++)
        {
            line = lad[j][line];
        }
        if (line != i)
            return;
    }
    ans = min(ans, n);
}

void setting()
{
    for (int i = 0; i < H; i++)
    {
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