#include <iostream>
using namespace std;

int arr[1000001];
int N, M;

int isin(int a)
{
    if (arr[a] == a)
    {
        return a;
    }
    else
    {
        return arr[a] = isin(arr[a]);
    }
}

void uf(int a, int b)
{
    int pa = isin(a);
    int pb = isin(b);
    arr[pb] = pa;
}

void solve()
{
    cin >> N >> M;
    for (int i = 1; i <= N; i++)
    {
        arr[i] = i;
    }
    int m, a, b;
    for (int i = 0; i < M; i++)
    {
        cin >> m >> a >> b;
        if (m)
        {
            if (isin(a) == isin(b))
                cout << "YES\n";
            else
                cout << "NO\n";
        }
        else
        {
            uf(a, b);
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}