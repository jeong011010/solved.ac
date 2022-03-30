#include <iostream>
#include <stack>
#include <vector>
using namespace std;

vector<int> v[500];
bool go[500];

int n, m, ans = 0;

void dfs()
{
    stack<int> s;
    s.push(1);
    go[1] = 1;
    while (!s.empty())
    {
        int n = s.top();
        s.pop();
        for (int i = 0; i < v[n].size(); i++)
        {
            if (!go[v[n][i]])
            {
                if (n == 1)
                {
                    s.push(v[n][i]);
                }
                go[v[n][i]] = 1;
                ans++;
                // cout << v[n][i] << '\n';
            }
        }
    }
}

void solve()
{
    cin >> n >> m;
    int a, b;
    for (int i = 0; i < m; i++)
    {
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    dfs();
    cout << ans;
}

int main()
{
    solve();
    return 0;
}