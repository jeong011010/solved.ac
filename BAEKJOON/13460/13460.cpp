#include <iostream>
#include <queue>
#include <vector>
using namespace std;

string arr[10];
int N, M;

void bfs()
{
}

void solve()
{
    int x, y;
    cin >> N >> M;
    for (int i = 0; i < N; i++)
    {
        cin >> arr[i];
        for (int j = 0; j < M; j++)
        {
            if (arr[i][j] == 'R')
            {
                y = i;
                x = j;
            }
        }
    }
}

int main()
{
    solve();
    return 0;
}