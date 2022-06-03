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

bool check[8][8];
int ans = 64;

void print(int arr[8][8])
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            cout << arr[i][j] << ' ';
        }
        cout << '\n';
    }
    cout << '\n';
}

void bf(int arr[8][8])
{
    // print(arr);
    int tmp_board[8][8];
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            tmp_board[i][j] = arr[i][j];
            board[i][j] = arr[i][j];
        }
    }
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            if (arr[i][j] > 0 && arr[i][j] < 6 && !check[i][j])
            {
                // cout << i << ',' << j << '\n';
                f(arr[i][j], i, j);
                check[i][j] = true;
                for (int i = 0; i < N; i++)
                {
                    for (int j = 0; j < M; j++)
                    {
                        arr[i][j] = board[i][j];
                    }
                }
                bf(arr);
                check[i][j] = false;
                for (int i = 0; i < N; i++)
                {
                    for (int j = 0; j < M; j++)
                    {
                        arr[i][j] = tmp_board[i][j];
                    }
                }
            }
        }
    }
    int a = 0;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            if (arr[i][j] == 0)
                a++;
        }
    }
    ans = min(ans, a);
}

void solve()
{
    input();
    bf(board);
    // print(board);
    cout << ans << '\n';
}

int main()
{
    solve();
    return 0;
}