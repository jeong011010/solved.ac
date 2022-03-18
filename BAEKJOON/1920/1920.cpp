#include <iostream>
#include <algorithm>
using namespace std;

int N, M;
int arr[100000];

void solve()
{
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        cin >> arr[i];
    }
    sort(arr, arr + N);
    cin >> M;
    int t, left, right;
    for (int i = 0; i < M; i++)
    {
        int ans = 0;
        cin >> t;
        left = 0;
        right = N;
        while (left <= right)
        {
            int mid = (right + left) / 2;
            if (arr[mid] == t)
            {
                ans = 1;
                break;
            }
            else if (arr[mid] > t)
                right = mid - 1;
            else
                left = mid + 1;
        }
        cout << ans << '\n';
    }
}

int main()
{
    solve();
    return 0;
}