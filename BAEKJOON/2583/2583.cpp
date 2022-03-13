#include <iostream>
#include <algorithm>
#include <stack>
#include <vector>
using namespace std;

int M, N, K;
int arr[100][100];
int ym[4] = {0, 1, 0, -1};
int xm[4] = {1, 0, -1, 0};

void solve()
{
    vector<int> ans;
    cin >> N >> M >> K;
    int a, b, c, d;
    for (int i = 0; i < K; i++)
    {
        cin >> a >> b >> c >> d;
        for (int i = b; i < d; i++)
        {
            for (int j = a; j < c; j++)
            {
                arr[i][j] = -1;
            }
        }
    }
    int cnt = 0;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            if (arr[i][j] == 0)
            {
                ans.push_back(1);
                cnt++;
                arr[i][j] = cnt;
                stack<pair<int, int>> s;
                s.push({i, j});
                while (!s.empty())
                {
                    int y = s.top().first;
                    int x = s.top().second;
                    s.pop();
                    for (int k = 0; k < 4; k++)
                    {
                        int ny = y + ym[k];
                        int nx = x + xm[k];
                        if (nx >= 0 && ny >= 0 && nx < M && ny < N)
                        {
                            if (arr[ny][nx] == 0)
                            {
                                ans[cnt - 1]++;
                                arr[ny][nx] = cnt;
                                s.push({ny, nx});
                            }
                        }
                    }
                }
            }
        }
    }

    sort(ans.begin(), ans.end());
    cout << ans.size() << '\n';
    for (int i = 0; i < ans.size(); i++)
        cout << ans[i] << ' ';
}

int main()
{
    solve();
    return 0;
}