#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int ans = 1;
int N;
int arr[103][103];
int ym[4] = {0, 1, 0, -1};
int xm[4] = {1, 0, -1, 0};
bool tower[101];

void f(int high)
{
    int save = 0;
    bool water[103][103] = {
        0,
    };
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            if (arr[i][j] > high)
                water[i][j] = true;
        }
    }
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            if (water[i][j])
            {
                queue<pair<int, int>> q;
                q.push({i, j});
                water[i][j] = false;
                while (!q.empty())
                {
                    int y = q.front().first;
                    int x = q.front().second;
                    q.pop();
                    for (int i = 0; i < 4; i++)
                    {
                        if (water[y + ym[i]][x + xm[i]])
                        {
                            q.push({y + ym[i], x + xm[i]});
                            water[y + ym[i]][x + xm[i]] = false;
                        }
                    }
                }
                save++;
            }
        }
    }
    ans = max(ans, save);
}

void solve()
{
    cin >> N;
    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= N; j++)
        {
            cin >> arr[i][j];
            tower[arr[i][j]] = true;
        }
    for (int i = 0; i <= N + 1; i++)
        arr[i][0] = arr[i][N + 1] = arr[0][i] = arr[N + 1][i] = 0;
    for (int i = 1; i < 101; i++)
    {
        if (tower[i])
        {
            f(i);
        }
    }
    cout << ans;
}

int main()
{
    solve();
    return 0;
}