#include <iostream>
#include <algorithm>
using namespace std;

int N;
long long arr[10000], M;

long long sum(long long limit)
{
    long long s = 0;
    for (int i = 0; i < N; i++)
    {
        if (arr[i] < limit)
            s += arr[i];
        else
            s += limit;
    }
    return s;
}

void solve()
{
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        cin >> arr[i];
    }
    sort(arr, arr + N);
    cin >> M;
    long long left = 0, right = arr[N - 1];
    long long ans = 0;
    while (left <= right)
    {
        long long mid = (left + right) / 2;
        if (sum(mid) <= M)
        {
            ans = mid;
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
        }
    }
    cout << ans;
}

int main()
{
    solve();
    return 0;
}