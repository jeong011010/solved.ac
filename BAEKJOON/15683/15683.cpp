#include <iostream>
#include <vector>
using namespace std;

int N, M;
int board[8][8];
vector<pair<int, int>> cam[5];

void input()
{
    cin >> N >> M;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            cin >> board[i][j];
            if (board[i][j] > 0 && board[i][j] < 6)
                cam[board[i][j] - 1].push_back({i, j});
        }
    }
}

int ym[4] = {0, 1, 0, -1};
int xm[4] = {1, 0, -1, 0};

int cansee(int path, int y, int x)
{
    int n = 0;
    y += ym[path];
    x += xm[path];
    while (board[y][x] != 6 && y >= 0 && y < N && x >= 0 && x < M)
    {
        if (board[y][x] == 0)
        {
            n++;
            // board[y][x] = 9;
        }
        y += ym[path];
        x += xm[path];
    }
    return n;
}

void see(int path, int y, int x)
{
    int n = 0;
    y += ym[path];
    x += xm[path];
    while (board[y][x] != 6 && y >= 0 && y < N && x >= 0 && x < M)
    {
        if (board[y][x] == 0)
        {
            board[y][x] = 9;
        }
        y += ym[path];
        x += xm[path];
    }
}

void f(int c, int y, int x)
{
    int maxsee = 0;
    int minsee = 9;
    int n = 0;
    switch (c)
    {
    case 1:
        for (int j = 0; j < 4; j++)
        {
            int m = cansee(j, y, x);
            maxsee = max(maxsee, m);
            if (m == maxsee)
                n = j;
        }
        see(n, y, x);
        break;
    case 2:
        for (int j = 0; j < 2; j++)
        {
            int m = cansee(j, y, x) + cansee(j + 2, y, x);
            maxsee = max(maxsee, m);
            if (m == maxsee)
                n = j;
        }
        see(n, y, x);
        see(n + 2, y, x);
        break;

    case 3:
        for (int j = 0; j < 4; j++)
        {
            int m = cansee(j, y, x) + cansee((j + 1) % 4, y, x);
            maxsee = max(maxsee, m);
            if (m == maxsee)
                n = j;
        }
        see(n, y, x);
        see((n + 1) % 4, y, x);
        break;

    case 4:
        for (int j = 0; j < 4; j++)
        {
            int m = cansee(j, y, x);
            minsee = min(minsee, m);
            if (m == minsee)
                n = j;
        }
        for (int j = 1; j < 4; j++)
        {
            see((n + j) % 4, y, x);
        }
        break;
    case 5:
        for (int j = 0; j < 4; j++)
        {
            see(j, y, x);
        }
        break;
    }
}

void bf()
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            if (board[i][j] > 0 && board[i][j < 6])
                f(board[i][j], i, j);
        }
    }
}

void print()
{
    int ans = 0;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            cout << board[i][j] << ' ';
            if (board[i][j] == 0)
                ans++;
        }
        cout << '\n';
    }
    cout << ans;
}

void solve()
{
    input();
    bf();
    print();
}

int main()
{
    solve();
    return 0;
}