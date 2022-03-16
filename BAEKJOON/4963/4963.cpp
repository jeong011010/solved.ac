#include <iostream>
#include <stack>
using namespace std;

int arr[50][50];
int my[8] = {0, 1, 1, 1, 0, -1, -1, -1};
int mx[8] = {1, 1, 0, -1, -1, -1, 0, 1};

void solve()
{
    int w, h;
    cin >> w >> h;
    while (w != 0 && h != 0)
    {
        int cnt = 0;
        for (int i = 0; i < h; i++)
        {
            for (int j = 0; j < w; j++)
            {
                cin >> arr[i][j];
            }
        }
        stack<pair<int, int>> s;
        for (int i = 0; i < h; i++)
        {
            for (int j = 0; j < w; j++)
            {
                if (arr[i][j] == 1)
                {
                    cnt++;
                    s.push({i, j});
                    arr[i][j] = 2;
                    while (!s.empty())
                    {
                        int y = s.top().first;
                        int x = s.top().second;
                        s.pop();
                        for (int k = 0; k < 8; k++)
                        {
                            int ny = y + my[k];
                            int nx = x + mx[k];
                            if (ny >= 0 && nx >= 0 && ny < h && nx < w)
                            {
                                if (arr[ny][nx] == 1)
                                {
                                    s.push({ny, nx});
                                    arr[ny][nx] = 2;
                                }
                            }
                        }
                    }
                }
            }
        }
        cout << cnt << '\n';
        cin >> w >> h;
    }
}

int main()
{
    solve();
    return 0;
}