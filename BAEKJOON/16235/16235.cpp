#include <iostream>
#include <vector>
#include <deque>
#include <queue>
#include <algorithm>
using namespace std;

deque<int> trees[11][11];
int A[11][11];
int board[11][11];
int my[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
int mx[8] = {-1, 0, 1, -1, 1, -1, 0, 1};
int N, M, K;

void input()
{
    cin >> N >> M >> K;
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            cin >> A[i][j];
            board[i][j] = 5;
        }
    }
    int x, y, z;
    for (int i = 0; i < M; i++)
    {
        cin >> x >> y >> z;
        trees[x][y].push_back(z);
    }
}

void season()
{
    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= N; j++)
        {
            int size = trees[i][j].size();
            int k = 0;
            for (; k < size; k++)
            {
                if (board[i][j] >= trees[i][j][k])
                {
                    board[i][j] -= trees[i][j][k];
                    trees[i][j][k]++;
                }
                else
                {
                    break;
                }
            }
            for (int p = size - 1; p >= k; p--)
            {
                board[i][j] += trees[i][j][p] / 2;
                trees[i][j].pop_back();
            }
        }

    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            for (int k = 0; k < trees[i][j].size(); k++)
            {
                if (trees[i][j][k] % 5 == 0)
                {
                    for (int l = 0; l < 8; l++)
                    {
                        int nx = i + mx[l];
                        int ny = j + my[l];
                        if (nx < 1 || nx > N || ny < 1 || ny > N)
                            continue;
                        else
                            trees[nx][ny].push_front(1);
                    }
                }
            }
            board[i][j] += A[i][j];
        }
    }
}

void livetree()
{
    int ans = 0;
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            // cout << trees[i][j].size() << '\n';
            if (trees[i][j].size() > 0)
            {
                ans += trees[i][j].size();
            }
        }
    }
    cout << ans;
}

void solve()
{
    input();
    while (K--)
    {
        season();
    }
    livetree();
}

int main()
{
    solve();
    return 0;
}