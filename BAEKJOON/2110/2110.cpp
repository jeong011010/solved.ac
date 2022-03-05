#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int N, C;

void solve()
{
    cin >> N >> C;
    vector<int> v(N, 0);
    for (int i = 0; i < N; i++)
        cin >> v[i];
    sort(v.begin(), v.end());

    int left = 0, right = v[N - 1];

    while (left <= right)
    {
        int iptime_cnt = 1;
        int pre_i = 0;
        int mid = (left + right) / 2;
        for (int i = 1; i < N; ++i)
        {
            if (v[i] - v[pre_i] >= mid)
            {
                pre_i = i;
                iptime_cnt++;
            }
        }
        if (iptime_cnt >= C)
            left = mid + 1;
        else
            right = mid - 1;
    }
    cout << right;
}

int main()
{
    solve();
    return 0;
}