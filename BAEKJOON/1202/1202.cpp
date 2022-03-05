#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;

int N, K;

void solve()
{
    cin >> N >> K;
    vector<pair<int, int>> v(N);
    vector<int> bag(K);
    priority_queue<int> pq;
    for (int i = 0; i < N; i++)
        cin >> v[i].first >> v[i].second;
    for (int i = 0; i < K; i++)
        cin >> bag[i];
    sort(v.begin(), v.end());
    sort(bag.begin(), bag.end());
    long long ans = 0;
    int idx = 0;
    for (int i = 0; i < K; i++)
    {
        while (idx < N && v[idx].first <= bag[i])
        {
            pq.push(v[idx++].second);
        }
        if (!pq.empty())
        {
            ans += (long long)pq.top();
            pq.pop();
        }
    }
    cout << ans;
}

int main()
{
    solve();
    return 0;
}