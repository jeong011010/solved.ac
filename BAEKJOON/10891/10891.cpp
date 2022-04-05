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
            continue; // 다음 정점이 왔던곳이라면 스킵
        if (visit[v[cur][i]])
        { // 다음 정점에 방문한 적 있으면 사이클 확인
            int tmp = cur;
            while (tmp != parent[v[cur][i]])
            {
                if (visit[tmp] == 2) // 사이클 확인중 visit가 이미 2라면 이미 사이클 한번 돈 단순 사이클이므로 cactus가 아님.
                {
                    cout << "Not cactus";
                    exit(0);
                }
                visit[tmp]++; // 방문 수를 늘려 visit가 2라면 사이클 한번 돈것.
                tmp = parent[tmp];
            }
        }
        else // 다음 정점에 방문한 적 없다면
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