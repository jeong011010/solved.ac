#include <iostream>
#include <map>
using namespace std;

map<string, bool> m;
int N, M, H;

int lad[30][10];

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
        lad[a - 1][b - 1] = b;
        lad[a - 1][b] = b - 1;
    }
}

int n = 0, ans = 4;

bool key()
{
    string s = "";
    for (int i = 0; i < H; i++)
    {
        for (int j = 0; j < N; j++)
        {
            s += to_string(lad[i][j]);
        }
    }
    if (m.find(s) != m.end())
    {
        return false;
    }
    m.insert({s, 0});
    return true;
}

void print()
{
    for (int i = 0; i < H; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cout << lad[i][j] << ' ';
        }
        cout << '\n';
    }
    cout << '\n';
}

bool run()
{
    for (int i = 0; i < N; i++)
    {
        int line = i;
        for (int j = 0; j < H; j++)
        {
            line = lad[j][line];
        }
        if (line != i)
            return false;
    }
    ans = min(ans, n);
    // print();
    // cout << n << '\n';
    return true;
}

void setting(int y, int x)
{
    if (!key())
        return;
    if (run())
        return;
    if (n > 3)
        return;
    // print();
    for (int i = y; i < H; i++)
    {
        for (int j = 0; j < N - 1; j++)
        {
            if (i == y && j <= x)
                continue;
            if (lad[i][j] == j && lad[i][j + 1] == j + 1)
            {
                lad[i][j] = j + 1;
                lad[i][j + 1] = j;
                n++;
                // cout << i << ',' << j << 'i' << '\n';
                setting(i, j);
                // cout << i << ',' << j << 'd' << '\n';
                lad[i][j] = j;
                lad[i][j + 1] = j + 1;
                n--;
            }
        }
    }
}

void solve()
{
    input();
    // print();
    setting(0, -1);
    if (ans > 3)
        cout << -1;
    else
        cout << ans;
}

int main()
{
    solve();
    return 0;
}