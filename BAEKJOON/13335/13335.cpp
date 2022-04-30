#include <iostream>
#include <queue>
using namespace std;

int n, w, L;

void solve()
{
    queue<int> truck;
    queue<int> bridge;
    cin >> n >> w >> L;
    int tmp, ans = 0, bw = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> tmp;
        truck.push(tmp);
    }
    for (int i = 0; i < w; i++)
        bridge.push(0);
    while (!truck.empty())
    {
        bw -= bridge.front();
        bridge.pop();
        if (bridge.size() < w && bw + truck.front() <= L)
        {
            bridge.push(truck.front());
            bw += truck.front();
            truck.pop();
        }
        else
        {
            bridge.push(0);
        }
        ans++;
    }
    ans += w;
    cout << ans;
}

int main()
{
    solve();
    return 0;
}