#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, cnt = 0;
vector<pair<int, int>> v;
vector<int> v_ans;

void f()
{
    vector<int> tmp;
    int here;
    tmp.push_back(v[0].second);
    for (int i = 1; i < N; i++)
    {
        if (tmp[cnt] > v[i].second)
        {
            tmp[lower_bound(v.begin(), v.end(), v[i].second) - v.begin()] = v[i].second;
        }
        else
        {
            tmp.push_back(v[i].second);
            cnt++;
        }
    }
}

void solve()
{
    cin >> N;
    int a, b;
    for (int i = 0; i < N; i++)
    {
        cin >> a >> b;
        v.push_back({a, b});
    }
    sort(v.begin(), v.end());
}

int main()
{
    solve();
    return 0;
}