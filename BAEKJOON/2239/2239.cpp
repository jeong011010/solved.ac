#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<int> v[9];

bool isin[9][9][9];
int ans[9];

int block[9][9][2] = {
    {{0, 0}, {0, 1}, {0, 2}, {1, 0}, {1, 1}, {1, 2}, {2, 0}, {2, 1}, {2, 2}},
    {{0, 3}, {0, 4}, {0, 5}, {1, 3}, {1, 4}, {1, 5}, {2, 3}, {2, 4}, {2, 5}},
    {{0, 6}, {0, 7}, {0, 8}, {1, 6}, {1, 7}, {1, 8}, {2, 6}, {2, 7}, {2, 8}},
    {{3, 0}, {3, 1}, {3, 2}, {4, 0}, {4, 1}, {4, 2}, {5, 0}, {5, 1}, {5, 2}},
    {{3, 3}, {3, 4}, {3, 5}, {4, 3}, {4, 4}, {4, 5}, {5, 3}, {5, 4}, {5, 5}},
    {{3, 6}, {3, 7}, {3, 8}, {4, 6}, {4, 7}, {4, 8}, {5, 6}, {5, 7}, {5, 8}},
    {{6, 0}, {6, 1}, {6, 2}, {7, 0}, {7, 1}, {7, 2}, {8, 0}, {8, 1}, {8, 2}},
    {{6, 3}, {6, 4}, {6, 5}, {7, 3}, {7, 4}, {7, 5}, {8, 3}, {8, 4}, {8, 5}},
    {{6, 6}, {6, 7}, {6, 8}, {7, 6}, {7, 7}, {7, 8}, {8, 6}, {8, 7}, {8, 8}},
};

int f(vector<int> board[9], int y, int x)
{
    bool check[10];
    for (int i = 0; i < 10; i++)
        check[i] = 0;

    for (int i = 0; i < 9; i++)
    {
        check[board[y][i]] = 1;
        check[board[i][x]] = 1;
    }
    int n;
    bool b = false;
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            if (block[i][j][0] == y && block[i][j][1] == x)
            {
                n = i;
                b = true;
                break;
            }
        }
        if (b)
            break;
    }

    for (int i = 0; i < 9; i++)
    {
        check[board[block[n][i][0]][block[n][i][1]]] = 1;
    }
    int cnt = 0;
    for (int i = 1; i < 10; i++)
    {
        if (!check[i])
        {
            cnt++;
            n = i;
        }
    }
    if (cnt == 1)
        return n;
    return 0;
}

void sudoku(vector<int> board[9])
{
    bool full = true;
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            if (board[i][j] == 0)
            {
                full = false;
                int tmp = f(board, i, j);
                if (tmp != 0 && !isin[i][j][tmp])
                {
                    // cout << i << ' ' << j << ' ' << tmp << '\n';
                    board[i][j] = tmp;
                    isin[i][j][tmp] = 1;
                    sudoku(board);
                    board[i][j] = 0;
                }
            }
        }
    }

    if (full)
    {
        bool change = false;
        for (int i = 0; i < 9; i++)
        {
            int tmp = 0;
            for (int j = 0; j < 9; j++)
            {
                tmp += board[i][j];
                if (j < 8)
                    tmp *= 10;
            }
            if (ans[i] > tmp)
            {
                change = true;
            }
            if (change)
            {
                ans[i] = tmp;
            }
        }
    }
}

void solve()
{
    for (int i = 0; i < 9; i++)
        ans[i] = 999999999;
    string tmp;
    vector<int> b[9];
    for (int i = 0; i < 9; i++)
    {
        cin >> tmp;
        for (int j = 0; j < 9; j++)
        {
            b[i].push_back(tmp[j] - 48);
        }
    }
    sudoku(b);
    for (int i = 0; i < 9; i++)
    {
        cout << ans[i] << '\n';
    }
}

int main()
{
    solve();
    return 0;
}