#include <iostream>
#include <queue>
#include <vector>
using namespace std;

vector<pair<int, int>> line[10000];
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
int V, E;
bool c[10001];

void input()
{
    cin >> V >> E;
    int A, B, C;
    for (int i = 0; i < E; i++)
    {
        cin >> A >> B >> C;
        line[A].push_back({B, C});
        line[B].push_back({A, C});
    }
}

void solve()
{
    int sum = 0;
    input();
    int e = 1;
    for (int k = 0; k < V - 1; k++)
    {
        c[e] = true;
        for (int i = 0; i < line[e].size(); i++)
        {
            // cout << line[e].size() << ' ';
            if (!c[line[e][i].first])
                pq.push({line[e][i].second, line[e][i].first});
        }
        // cout << pq.size() << ' ' << e << ' ';
        e = pq.top().second;
        // if(k==V-1) break;
        while (c[e])
        {
            pq.pop();
            e = pq.top().second;
        }
        // cout << pq.top().second << ' ' << pq.top().first << '\n';
        sum += pq.top().first;
        pq.pop();
    }
    cout << sum;
}

int main()
{
    solve();
    return 0;
}