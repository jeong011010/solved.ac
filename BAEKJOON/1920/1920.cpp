#include <iostream>
#include <algorithm>
using namespace std;

int N, M;
int arr[100000], sol[100000];

void solve()
{
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        cin >> arr[i];
    }
    sort(arr, arr + N);
    cin >> M;
    for (int i = 0; i < M; i++)
    {
        cin >> sol[i];
    }
    sort(arr, arr + N);
    int t, left, right;
    for (int i = 0; i < M; i++)
    {
        int ans = 0;

        if (binary_search(arr, arr + N, sol[i]))
        {
            ans = 1;
        }
        cout << ans << '\n';
    }
}

int main()
{
    solve();
    return 0;
}