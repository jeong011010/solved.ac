#include <iostream>
using namespace std;

int N, ans = 0;
bool arr[10][10];
bool isin1[10];
bool isin2[9];

void f()
{
    for (int i = 0; i < (N * 2) - 1; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            if (j < N && i - j < N)
            {
                if (arr[0 + j][i - j])
                {
                }
            }
        }
    }
}

void solve()
{
    cin >> N;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            cin >> arr[i][j];
}

int main()
{
    solve();
    return 0;
}