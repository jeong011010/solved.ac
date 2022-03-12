#include <iostream>
using namespace std;

int R, C;
int ans = 1;
int arr[20][20];
int xm[4] = {1, 0, -1, 0};
int ym[4] = {0, 1, 0, -1};

void dfs(int y, int x, bool check[26], int cnt)
{
    for (int i = 0; i < 4; i++)
    {
        int ny = y + ym[i];
        int nx = x + xm[i];
        if (ny >= 0 && nx >= 0 && ny < 20 && nx < 20)
        {
            if (!check[arr[ny][nx]])
            {
                check[arr[ny][nx]] = 1;
                dfs(ny, nx, check, cnt + 1);
                check[arr[ny][nx]] = 0;
            }
            else
            {
                ans = max(ans, cnt);
            }
        }
    }
    return;
}

void solve()
{
    bool check[26] = {
        0,
    };
    cin >> R >> C;
    string tmp;
    for (int i = 0; i < R; i++)
    {
        cin >> tmp;
        for (int j = 0; j < C; j++)
        {
            arr[i][j] = tmp[j] - 65;
        }
    }
    check[arr[0][0]] = 1;
    dfs(0, 0, check, 1);
    cout << ans;
}

int main()
{
    solve();
    return 0;
}