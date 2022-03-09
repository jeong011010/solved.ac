#include <iostream>
#include <vector>
#include <queue>
using namespace std;
#define MAX 5001

vector<pair<int, int>> USADO[MAX];
int N, Q;

void bfs(int start, int limit)
{
    bool visited[MAX] = {
        0,
    };
    int ans = 0;
    queue<int> q;
    visited[start] = 1;
    for (int i = 0; i < USADO[start].size(); i++)
    {
        if (USADO[start][i].second >= limit)
        {
            q.push(USADO[start][i].first);
            ans++;
            visited[USADO[start][i].first] = 1;
        }
    }
    while (!q.empty())
    {
        int next = q.front();
        q.pop();
        for (int i = 0; i < USADO[next].size(); i++)
        {
            if (!visited[USADO[next][i].first] && USADO[next][i].second >= limit)
            {
                q.push(USADO[next][i].first);
                visited[USADO[next][i].first] = 1;
                ans++;
            }
        }
    }
    cout << ans << '\n';
}

void solve()
{
    cin >> N >> Q;
    int p, q, r, k, v;
    for (int i = 0; i < N - 1; i++)
    {
        cin >> p >> q >> r;
        USADO[p].push_back({q, r});
        USADO[q].push_back({p, r});
    }
    for (int i = 0; i < Q; i++)
    {
        cin >> k >> v;
        bfs(v, k);
    }
}

int main()
{
    solve();
    return 0;
}