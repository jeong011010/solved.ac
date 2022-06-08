#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<pair<pair<int, int>, int>> tree; // y,x,age,die
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
        tree.push_back({{y - 1, x - 1}, z});
    }
}

void season()
{
    vector<pair<pair<int, int>, int>> die;
    sort(tree.begin(), tree.end());
    for (int i = 0; i < tree.size(); i++)
    { // spring

        int y = tree[i].first.first;
        int x = tree[i].first.second;
        int z = tree[i].second;
        if (z <= board[y][x])
        {
            board[y][x] -= z;
            tree[i].second++;
        }
        else
        {
            tree.erase(tree.begin() + i);
            i--;
            die.push_back({{y, x}, z});
        }
    }

    for (int i = 0; i < die.size(); i++)
    { // summer
        int y = die[i].first.first;
        int x = die[i].first.second;
        board[y][x] += die[i].second / 2;
    }

    for (int i = 0; i < tree.size(); i++)
    { // fall
        if (tree[i].second % 5 == 0)
        {
            int y = tree[i].first.first;
            int x = tree[i].first.second;
            for (int j = 0; j < 8; j++)
            {
                int ny = y + my[j];
                int nx = x + mx[j];
                if (ny >= 0 && ny < N && nx >= 0 && nx < N)
                {
                    tree.push_back({{ny, nx}, 1});
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
    cout << tree.size();
}

void print()
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cout << board[i][j] << ' ';
        }
        cout << '\n';
    }
    for (int i = 0; i < tree.size(); i++)
    {
        cout << tree[i].first.first << ',' << tree[i].first.second << ':' << tree[i].second << '\n';
    }
}

void solve()
{
    input();
    // print();
    while (K--)
    {
        season();
        // print();
    }
    livetree();
}

int main()
{
    solve();
    return 0;
}