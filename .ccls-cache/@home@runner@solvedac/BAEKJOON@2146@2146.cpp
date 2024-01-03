#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int arr[100][100];
int ym[4] = {0, 1, 0, -1};
int xm[4] = {1, 0, -1, 0};
int N;

void solve()
{
    vector<pair<int, int>> island;

    cin >> N;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            cin >> arr[i][j];

    int cnt = 0;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
        {
            if (arr[i][j] == 1)
            {
                island.push_back({i, j});
                cnt++;
                queue<pair<int, int>> q;
                q.push({i, j});
                arr[i][j] = cnt + 1;
                while (!q.empty())
                {
                    int y = q.front().first;
                    int x = q.front().second;
                    for (int k = 0; k < 4; k++)
                    {
                        int ny = y + ym[i];
                        int nx = x + xm[i];
                        if (ny >= 0 && nx >= 0 && ny < N && nx < N)
                        {
                            if (arr[ny][nx] == 1)
                            {
                                arr[ny][nx] = cnt + 1;
                                q.push({ny, nx});
                            }
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