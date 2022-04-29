#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<int> v[9];

bool isin[9][9][9];
int ans[9];

int f(vector<int> board[9], int y, int x, int k)
{
    bool check[10];
    for (int i = 0; i < 10; i++)
        check[i] = false;
    bool a, b, c;
    a = b = c = false;
    int block_x = x / 3;
    int block_y = y / 3;
    for (int i = 0; i < 9; i++)
    {
        check[board[y][i]] = true;
        check[board[i][x]] = true;
        if (board[y][i] == k)
            a = true;
        if (board[i][x] == k)
            b = true;
    }
    for (int i = 3 * block_y; i < 3 * block_y + 3; i++)
    {
        for (int j = 3 * block_x; j < 3 * block_x + 3; j++)
        {
            check[board[i][j]] = true;
            if (board[i][j] == k)
            {
                c = true;
            }
        }
    }
    bool can = false;
    for (int i = 1; i < 10; i++)
    {
        if (!check[i])
            can = true;
    }
    if (!can)
        return 2;
    if (!a && !b && !c)
        return 0;
    else
        return 1;
}

bool finish = false;

void sudoku(vector<int> board[9])
{
    /*for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            cout << board[i][j];
        }
        cout << '\n';
    }*/
    if (finish)
        return;
    bool full = true;
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            if (board[i][j] == 0)
            {
                full = false;
                for (int k = 1; k < 10; k++)
                {
                    {
                        int tmp = f(board, i, j, k);
                        if (tmp == 0)
                        {
                            board[i][j] = k;
                            cout << i << ' ' << j << ' ' << k << '\n';
                            sudoku(board);
                            board[i][j] = 0;
                            // cout << "빽1\n";
                        }
                        else if (tmp == 2)
                        {
                            // cout << "빽2\n";
                            return;
                        }
                    }
                }
            }
        }
    }

    if (full)
    {
        cout << "!!!\n";
        finish = true;
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