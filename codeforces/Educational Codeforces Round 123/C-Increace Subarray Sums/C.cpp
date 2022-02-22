#include <iostream>
using namespace std;

int t;
int n, x;
int arr[5001];
int tmp[5001];
int DP[5001];

int f()
{
    DP[0] = tmp[0];
    int ans = 0;

    for (int i = 1; i < n; i++)
    {
        DP[i] = max(DP[i - 1], 0) + tmp[i];
        ans = max(DP[i], ans);
    }
    return ans;
}

void ff()
{
    for (int i = 0; i <= n; i++)
    {
        int m = 0;
        for (int j = 0; j < n - i + 1; j++)
        {
            for (int k = 0; k < n; k++)
                tmp[k] = arr[k];
            for (int k = 0; k < i; k++)
            {
                tmp[j + k] += x;
            }
            m = max(f(), m);
        }
        cout << m << ' ';
    }
    cout << '\n';
}

void solve()
{
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        cin >> n >> x;
        for (int j = 0; j < n; j++)
            cin >> arr[j];
        ff();
    }
}

int main()
{
    solve();
    return 0;
}