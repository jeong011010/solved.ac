#include <iostream>
using namespace std;

int tc;

void solve()
{
    cin >> tc;
    while (tc--)
    {
        int N, ans = 0;
        bool visited[1001] = {
            0,
        };
        int arr[1001];
        cin >> N;
        for (int i = 1; i <= N; i++)
        {
            cin >> arr[i];
        }
        for (int i = 1; i <= N; i++)
        {
            if (!visited[i])
            {
                int tmp = arr[i];
                do
                {
                    visited[tmp] = 1;
                    tmp = arr[tmp];
                } while (tmp != arr[i]);
                ans++;
            }
        }
        cout << ans << '\n';
    }
}

int main()
{
    solve();
    return 0;
}