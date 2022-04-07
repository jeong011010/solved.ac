#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int N, M, D;
bool map[16][15];
bool arr[16][15];
int ans = 0;
int archer[3];
int m_x[3] = {-1, 0, 1};
int m_y[3] = {0, -1, 0};
vector<pair<int, int>> k;

void bfs(int y, int x)
{
    bool visit[16][15] = {0};
    queue<pair<pair<int, int>, int>> q;
    q.push({{y, x}, 0});
    visit[y][x] = true;
    while (!q.empty())
    {
        int ar_y = q.front().first.first;
        int ar_x = q.front().first.second;
        int cnt = q.front().second;
        q.pop();
        if (map[ar_y][ar_x])
        {
            k.push_back({ar_y, ar_x});
            return;
        }
        if (cnt < D)
        {
            for (int i = 0; i < 3; i++)
            {
                if (ar_x + m_x[i] >= 0 && ar_x + m_x[i] < M && ar_y + m_y[i] >= 0 && !visit[ar_y + m_y[i]][ar_x + m_x[i]])
                {
                    q.push({{ar_y + m_y[i], ar_x + m_x[i]}, cnt + 1});
                    visit[ar_y + m_y[i]][ar_x + m_x[i]] = true;
                }
            }
        }
    }
    return;
}

void simul(int kill, int row)
{
    if (row == 0)
    {
        ans = max(ans, kill);
        return;
    }
    int K = kill;
    for (int i = 0; i < M; i++)
    {
        map[row][i] = 0;
    }
    for (int i = 0; i < 3; i++)
    {
        bfs(row, archer[i]);
    }
    for (int i = 0; i < k.size(); i++)
    {
        if (map[k[i].first][k[i].second])
        {
            map[k[i].first][k[i].second] = 0;
            K++;
        }
    }
    int s = k.size();
    for (int i = 0; i < s; i++)
        k.pop_back();
    simul(K, row - 1);
    return;
}

void bf(int s, int n)
{
    if (n == 3)
    {
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < M; j++)
            {
                map[i][j] = arr[i][j];
            }
        }
        simul(0, N);
        return;
    }
    for (int i = s; i < M - (2 - n); i++)
    {
        archer[n] = i;
        bf(i + 1, n + 1);
    }
}

void solve()
{
    cin >> N >> M >> D;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            cin >> arr[i][j];
        }
    }
    bf(0, 0);
    cout << ans;
}

int main()
{
    solve();
    return 0;
}