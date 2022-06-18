#include <iostream>
#include <queue>
#include <vector>
#include <cmath>
using namespace std;

int t;
int h_x, h_y, p_x, p_y;
vector<pair<int, int>> store;

void input()
{

    int n, x, y;
    cin >> n;
    cin >> h_x >> h_y;
    int tmp = store.size();
    for (int i = 0; i < tmp; i++)
    {
        store.pop_back();
    }

    for (int i = 0; i < n; i++)
    {
        cin >> x >> y;
        store.push_back({x, y});
    }
    cin >> p_x >> p_y;
}

void cango()
{
    bool check[100] = {
        0,
    };
    queue<pair<int, int>> q;
    q.push({h_x, h_y});
    while (!q.empty())
    {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        if (abs(p_x - x) + abs(p_y - y) <= 1000)
        {
            cout << "happy" << '\n';
            return;
        }

        for (int i = 0; i < store.size(); i++)
        {
            if (check[i])
                continue;
            int s_x = store[i].first;
            int s_y = store[i].second;
            int l = abs(s_x - x) + abs(s_y - y);
            if (l <= 1000)
            {
                check[i] = true;
                q.push({s_x, s_y});
            }
        }
    }
    cout << "sad" << '\n';
}

void solve()
{
    cin >> t;
    while (t--)
    {
        input();
        cango();
    }
}

int main()
{
    solve();
    return 0;
}
