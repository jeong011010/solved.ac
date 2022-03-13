#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<int> v[101];
bool visited[101];
int N, A, B, M;

void bfs()
{
    queue<pair<int, int>> q;
    q.push({A, 1});
    visited[A] = true;
    while (!q.empty())
    {
        int now = q.front().first;
        int cnt = q.front().second;
        q.pop();
        for (int i = 0; i < v[now].size(); i++)
        {

            if (v[now][i] == B)
            {
                cout << cnt;
                return;
            }
            else if (!visited[v[now][i]])
            {
                visited[v[now][i]] = 1;
                q.push({v[now][i], cnt + 1});
            }
        }
    }
    cout << -1;
    return;
}

void solve()
{
    cin >> N >> A >> B >> M;
    int a, b;
    for (int i = 0; i < M; i++)
    {
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    bfs();
    return;
}

int main()
{
    solve();
    return 0;
}