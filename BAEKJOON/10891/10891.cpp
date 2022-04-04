#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int N, M, idx = 1;
vector<int> v[100001];
int visit[100001], dfsn[100001], parent[100001];

void cactus(int cur, int par)
{
    dfsn[cur] = idx++;
    visit[cur]++;
    parent[cur] = par;
    for (int i = 0; i < v[cur].size(); i++)
    {
        if (v[cur][i] == par || dfsn[v[cur][i]] >= dfsn[cur])
            continue;
        if (visit[v[cur][i]])
        {
            int tmp = cur;
            while (tmp != parent[v[cur][i]])
            {
                if (visit[tmp] == 2)
                {
                    cout << "Not cactus";
                    exit(0);
                }
                visit[tmp]++;
                tmp = parent[tmp];
            }
        }
        else
            cactus(v[cur][i], cur);
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

    cactus(1, -1);
    cout << "Cactus";
}

int main()
{
    solve();
    return 0;
}