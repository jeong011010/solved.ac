#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<pair<pair<int, int>, pair<int, bool>>> tree; // y,x,age,die
int A[10][10];
int board[10][10];
int my[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
int mx[8] = {-1, 0, 1, -1, 1, -1, 0, 1};
int N, M, K;

void input()
{
    cin >> N >> M >> K;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cin >> A[i][j];
            board[i][j] = 5;
        }
    }
    int x, y, z;
    for (int i = 0; i < M; i++)
    {
        cin >> x >> y >> z;
        tree.push_back({{y - 1, x - 1}, {z, 0}});
    }
}

void season()
{
    sort(tree.begin(), tree.end());
    for (int i = 0; i < tree.size(); i++)
    { // spring
        if (!tree[i].second.second)
        {
            int y = tree[i].first.first;
            int x = tree[i].first.second;
            int z = tree[i].second.first;
            if (z <= board[y][x])
            {
                board[y][x] -= z;
                tree[i].second.first++;
            }
            else
            {
                tree[i].second.second = 1;
            }
        }
    }

    for (int i = 0; i < tree.size(); i++)
    { // summer
        if (tree[i].second.second && tree[i].second.first > 0)
        {
            int y = tree[i].first.first;
            int x = tree[i].first.second;
            board[y][x] += tree[i].second.first / 2;
            tree[i].second.first = 0;
        }
    }

    for (int i = 0; i < tree.size(); i++)
    { // fall
        if (tree[i].second.first % 5 == 0 && !tree[i].second.second)
        {
            int y = tree[i].first.first;
            int x = tree[i].first.second;
            for (int j = 0; j < 8; j++)
            {
                int ny = y + my[j];
                int nx = x + mx[j];
                if (ny >= 0 && ny < N && nx >= 0 && nx < N)
                {
                    tree.push_back({{ny, nx}, {1, 0}});
                }
            }
        }
    }

    for (int i = 0; i < N; i++)
    { // winter
        for (int j = 0; j < N; j++)
        {
            board[i][j] += A[i][j];
        }
    }
}

void livetree()
{
    int sum = 0;
    for (int i = 0; i < tree.size(); i++)
    {
        if (!tree[i].second.second)
            sum++;
    }
    cout << sum;
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