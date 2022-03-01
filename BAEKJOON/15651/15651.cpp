#include <iostream>
using namespace std;

int N, M;
int arr[8];

void dfs(int cnt)
{
    if (cnt == M)
    {
        for (int i = 0; i < M; i++)
            cout << arr[i] << ' ';
        cout << '\n';
        return;
    }
    for (int i = 0; i < N; i++)
    {
        arr[cnt] = i + 1;
        dfs(cnt + 1);
    }
}

void solve()
{
    cin >> N >> M;
    dfs(0);
}

int main()
{
    solve();
    return 0;
}