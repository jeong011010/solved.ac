#include <iostream>
using namespace std;

int arr[8];
bool use[8];
int N, M;

void f(int cnt)
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
        if (!use[i])
        {
            arr[cnt] = i + 1;
            use[i] = true;
            f(cnt + 1);
            use[i] = false;
        }
    }
}

void solve()
{
    cin >> N >> M;
    f(0);
}

int main()
{
    solve();
    return 0;
}