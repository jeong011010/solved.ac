#include <iostream>
#include <vector>
using namespace std;

int arr[50][50];
int N, M;
typedef struct vecuum
{
    int r, c, d;
} vecuum;
vecuum V;

void input()
{
    cin >> N >> M;
    cin >> V.r >> V.c >> V.d;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            cin >> arr[i][j];
        }
    }
}

void simul()
{
    while (1)
    {
    }
}

void solve()
{
    input();
}

int main()
{
    solve();
    return 0;
}