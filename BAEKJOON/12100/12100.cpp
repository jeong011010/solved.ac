#include <iostream>
#include <map>
using namespace std;

int N, M = 0;

int My[4] = {0, 1, 0, -1};
int Mx[4] = {1, 0, -1, 0};

map<string, bool> check;

typedef int (*Temp)[21];

void print(int map[21][21])
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cout << map[i][j] << ' ';
        }
        cout << '\n';
    }
    cout << '\n';
}

Temp simul(int map[21][21], int flag)
{
    bool comb[21][21] = {false};
    // print(map);
    //  cout << "?\n";
    int Sy, Sx, Cy, Cx;
    switch (flag)
    {
    case 0: //오른쪽
        Sy = 0;
        Sx = N - 1;
        Cy = 1;
        Cx = -1;
        break;
    case 1: //아래
        Sy = N - 1;
        Sx = 0;
        Cy = -1;
        Cx = 1;
        break;
    case 2: //왼쪽
        Sy = 0;
        Sx = 0;
        Cy = 1;
        Cx = 1;
        break;
    case 3: //위
        Sy = 0;
        Sx = 0;
        Cy = 1;
        Cx = 1;
        break;
    }
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            int Y = Sy + (i * Cy);
            int X = Sx + (j * Cx);

            int n = map[Y][X];
            int y = Y + My[flag];
            int x = X + Mx[flag];
            // cout << Y << ',' << X << ':' << flag << '\n';
            if (((y >= 0 && y < N) && (x >= 0 && x < N)) && n != 0)
            {
                // cout << "skip\n";
                while (map[y][x] == 0 && (y >= 0 && y < N) && (x >= 0 && x < N))
                {
                    y += My[flag];
                    x += Mx[flag];
                }
                if (map[y][x] == n && !comb[y][x])
                {
                    map[y][x] *= 2;
                    comb[y][x] = true;
                }
                else
                {
                    y -= My[flag];
                    x -= Mx[flag];
                    map[y][x] = n;
                }
                if (!(Y == y) || !(X == x))
                    map[Y][X] = 0;
                // print(map);
                // cout << Y << ',' << X << ',' << n << '\n';
                // cout << y << ',' << x << '\n';
                // cout << "-----\n";
            }
        }
    }

    return map;
}

int bign(int map[21][21])
{
    int big = 0;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            big = max(big, map[i][j]);
        }
    }
    return big;
}

void bt(int board[21][21], int cnt)
{

    M = max(bign(board), M);
    string s = "";
    s += cnt;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            s += to_string(board[i][j]);
        }
    }
    // print(board);
    // cout << cnt << '\n';
    //  cout << s << "!" << '\n';
    if (check.find(s) != check.end())
    {
        // cout << "있다!\n";
        return;
    }
    check.insert({s, 1});

    if (cnt == 5)
    {
        // cout << "초과!\n";
        return;
    }
    for (int i = 0; i < 4; i++)
    {
        int tmp[21][21];
        // print(simul(board, i));
        for (int j = 0; j < N; j++)
        {
            for (int k = 0; k < N; k++)
            {
                tmp[j][k] = board[j][k];
            }
        }
        // cout << cnt << ' ' << i << '\n';

        bt(simul(tmp, i), cnt + 1);
    }
}

void solve()
{
    int m[21][21];
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cin >> m[i][j];
        }
    }
    bt(m, 0);
    cout << M;
}

int main()
{
    solve();
    return 0;
}