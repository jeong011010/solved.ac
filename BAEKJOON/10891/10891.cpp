#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int N, M;
vector<int> v[100001];
int visit[100001];

void cactus(int u, int p)
{
    for (int i = 0; i < v[u].size(); i++)
    {
        int tmp = v[u][i];
        if (p != tmp)
        {
            if (visit[tmp] == 0)
            {
                visit[tmp] = visit[u] + 1;
            }
        }
    }
}

void solve()
{
    cin >> N >> M;
    int x, y;
    for (int i = 0; i < M; i++)
    {
        cin >> x >> y;
        v[x].push_back(y);
        v[y].push_back(x);
    }

    for (int i = 1; i <= N; i++)
    {
        if (!visit[i])
            cactus(i);
    }
}

int main()
{
    solve();
    return 0;
}