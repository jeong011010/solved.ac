#include <iostream>
#include <stack>
#include <queue>
#include <vector>
using namespace std;

int N, M;

typedef struct ball
{
    int x, y;
} b;

b R, B;

int Rx, Ry, Bx, By;

int arr[10][10]; // 0: 공간, 1: 벽, 2: R, 4: B, 9: 골
bool visited[10][10][10][10];

int m_x[4] = {1, 0, -1, 0};
int m_y[4] = {0, 1, 0, -1};

void input()
{
    cin >> N >> M;
    string s;
    for (int i = 0; i < N; i++)
    {
        cin >> s;
        for (int j = 0; j < M; j++)
        {
            switch (s[j])
            {
            case '.':
                arr[i][j] = 0;
                break;
            case '#':
                arr[i][j] = 1;
                break;
            case 'R':
                arr[i][j] = 0;
                R.y = i;
                R.x = j;
                break;
            case 'B':
                arr[i][j] = 0;
                B.y = i;
                B.x = j;
                break;
            case 'O':
                arr[i][j] = 9;
                break;
            }
        }
    }
    visited[R.y][R.x][B.y][B.x] = true;
}

void bfs()
{
    queue<pair<pair<b, b>, int>> q;
    q.push({{R, B}, 1});
    while (!q.empty())
    {
        b bR = q.front().first.first;
        b bB = q.front().first.second;
        int cnt = q.front().second;
        if (cnt > 10)
        {
            // cout << bR.y << ',' << bR.x << ' ' << bB.y << ',' << bB.x << ' ' << cnt;
            cout << -1;
            return;
        }
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            bool Rf = false;
            switch (i)
            {
            case 0:
                if (bR.x > bB.x)
                    Rf = true;
                break;

            case 1:
                if (bR.y > bB.y)
                    Rf = true;
                break;

            case 2:
                if (bR.x < bB.x)
                    Rf = true;
                break;

            case 3:
                if (bR.y < bB.y)
                    Rf = true;
                break;
            }
            b mR, mB;
            mR.y = bR.y + m_y[i];
            mR.x = bR.x + m_x[i];
            mB.y = bB.y + m_y[i];
            mB.x = bB.x + m_x[i];
            bool gR = false, gB = false;
            bool move = true;
            // cout << Rf << '\n';
            if (Rf)
            {

                while (1)
                {
                    if (mR.y == bB.y && mR.x == bB.x)
                    {
                        mR.y -= m_y[i];
                        mR.x -= m_x[i];
                        break;
                    }
                    else if (arr[mR.y][mR.x] == 0)
                    {
                        mR.y += m_y[i];
                        mR.x += m_x[i];
                    }
                    else if (arr[mR.y][mR.x] == 9)
                    {
                        mR.y = mR.x = 0;
                        gR = true;
                        break;
                    }
                    else
                    {
                        mR.y -= m_y[i];
                        mR.x -= m_x[i];
                        break;
                    }
                }
                while (1)
                {
                    if (mB.y == mR.y && mB.x == mR.x)
                    {
                        mB.y -= m_y[i];
                        mB.x -= m_x[i];
                        break;
                    }
                    else if (arr[mB.y][mB.x] == 0)
                    {
                        mB.y += m_y[i];
                        mB.x += m_x[i];
                    }
                    else if (arr[mB.y][mB.x] == 9)
                    {
                        mB.y = mB.x = 0;
                        gB = true;
                        break;
                    }
                    else
                    {
                        mB.y -= m_y[i];
                        mB.x -= m_x[i];
                        break;
                    }
                }
            }
            else
            {
                while (1)
                {
                    if (mB.y == bR.y && mB.x == bR.x)
                    {
                        mB.y -= m_y[i];
                        mB.x -= m_x[i];
                        break;
                    }
                    else if (arr[mB.y][mB.x] == 0)
                    {
                        mB.y += m_y[i];
                        mB.x += m_x[i];
                    }
                    else if (arr[mB.y][mB.x] == 9)
                    {
                        mB.y = mB.x = 0;
                        gB = true;
                        break;
                    }
                    else
                    {
                        mB.y -= m_y[i];
                        mB.x -= m_x[i];
                        break;
                    }
                }
                while (1)
                {
                    if (mR.y == mB.y && mR.x == mB.x)
                    {
                        mR.y -= m_y[i];
                        mR.x -= m_x[i];
                        break;
                    }
                    else if (arr[mR.y][mR.x] == 0)
                    {
                        mR.y += m_y[i];
                        mR.x += m_x[i];
                    }
                    else if (arr[mR.y][mR.x] == 9)
                    {
                        mR.y = mR.x = 0;
                        gR = true;
                        break;
                    }
                    else
                    {
                        mR.y -= m_y[i];
                        mR.x -= m_x[i];
                        break;
                    }
                }
                if (mR.x == bR.x && mR.y == bR.y && mB.x == bB.x && mB.y == bB.y)
                    move = false;
            }
            if (gR && !gB)
            {
                // cout << bR.y << ',' << bR.x << ' ' << bB.y << ',' << bB.x << '\n';
                // cout << mR.y << ',' << mR.x << ' ' << mB.y << ',' << mB.x << '\n';
                cout << cnt;
                return;
            }
            else if (!gR && !gB && move && !visited[mR.y][mR.x][mB.y][mB.x])
            {
                visited[mR.y][mR.x][mB.y][mB.x] = true;
                // cout << mR.y << ',' << mR.x << ' ' << mB.y << ',' << mB.x << ' ' << cnt << '\n';
                q.push({{mR, mB}, cnt + 1});
            }
        }
    }
    cout << "-1";
    return;
}

void solve()
{
    input();
    bfs();
}

int main()
{
    solve();
    return 0;
}