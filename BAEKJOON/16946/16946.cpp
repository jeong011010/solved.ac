#include <iostream>
#include <stack>
#include <vector>
#include <map>
using namespace std;

int arr[1003][1003];
int ans[1003][1003];
int xm[4] = {1, 0, -1, 0};
int ym[4] = {0, -1, 0, 1};
vector<pair<int, int>> v;
map<int, int> m;
int N, M;

void dfs(int i, int j, int c)
{
    int cnt = 1;
    stack<pair<int, int>> s;
    s.push({i, j});
    arr[i][j] = c;
    while (!s.empty())
    {
        int y = s.top().first;
        int x = s.top().second;
        s.pop();
        for (int i = 0; i < 4; i++)
        {
            if (arr[y + ym[i]][x + xm[i]] == 0)
            {
                cnt++;
                arr[y + ym[i]][x + xm[i]] = c;
                s.push({y + ym[i], x + xm[i]});
            }
        }
    }
    m.insert({c, cnt});
}

void solve()
{
    cin >> N >> M;
    string tmp;
    for (int i = 1; i <= N; i++)
    {
        cin >> tmp;
        for (int j = 1; j <= M; j++)
        {
            arr[i][j] = tmp[j - 1] - 48;
            if (arr[i][j] == 1)
            {
                arr[i][j] = -1;
                v.push_back({i, j});
            }
        }
    }

    for (int i = 0; i <= N + 1; i++)
        arr[i][0] = arr[i][M + 1] = -1;
    for (int i = 0; i <= M + 1; i++)
        arr[0][i] = arr[N + 1][i] = -1;

    int cnt = 1;
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= M; j++)
        {
            if (arr[i][j] == 0)
            {
                dfs(i, j, cnt++);
            }
        }
    }

    for (int i = 0; i < v.size(); i++)
    {
        int tmp[4] = {
            0,
        };
        ans[v[i].first][v[i].second] = 1;
        for (int j = 0; j < 4; j++)
        {
            if (arr[v[i].first + ym[j]][v[i].second + xm[j]] != -1)
            {
                bool check = false;
                for (int k = 0; k < 4; k++)
                    if (arr[v[i].first + ym[j]][v[i].second + xm[j]] == tmp[k])
                        check = true;
                tmp[j] = arr[v[i].first + ym[j]][v[i].second + xm[j]];
                if (!check)
                {
                    ans[v[i].first][v[i].second] += m[tmp[j]];
                }
            }
        }
    }

    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= M; j++)
            cout << ans[i][j] % 10;
        cout << '\n';
    }
}

int main()
{
    solve();
    return 0;
}