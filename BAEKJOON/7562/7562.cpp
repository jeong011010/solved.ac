#include <iostream>
#include <queue>
using namespace std;

int ym[8] = {1, 2, 2, 1, -1, -2, -2, -1};
int xm[8] = {2, 1, -1, -2, -2, -1, 1, 2};
int l, sy, sx, gy, gx;

void solve()
{
    int tc;
    cin >> tc;
    while (tc--)
    {
        bool visit[301][301] = {
            0,
        };
        cin >> l >> sy >> sx >> gy >> gx;
        queue<pair<pair<int, int>, int>> q;
        q.push({{sy, sx}, 0});
        visit[sy][sx] = 1;
        while (!q.empty())
        {
            int y = q.front().first.first;
            int x = q.front().first.second;
            int cnt = q.front().second;
            q.pop();
            if (y == gy && x == gx)
            {
                cout << cnt << '\n';
                break;
            }
            for (int i = 0; i < 8; i++)
            {
                int ny = y + ym[i];
                int nx = x + xm[i];
                if (ny >= 0 && nx >= 0 && ny < l && nx < l)
                {
                    if (!visit[ny][nx])
                    {
                        visit[ny][nx] = 1;
                        q.push({{ny, nx}, cnt + 1});
                    }
                }
            }
        }
    }
}

int main()
{
    solve();
    return 0;
}