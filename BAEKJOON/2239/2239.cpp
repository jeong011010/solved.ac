#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<int> v[9];

bool isin[9][9][9];
int ans[9];

bool f(vector<int> board[9], int y, int x, int k)
{
    int block_x = x / 3;
    int block_y = y / 3;
    for (int i = 0; i < 9; i++)
    {
        if (board[y][i] == k || board[i][x] == k)
        {
            return true;
        }
    }
    for (int i = 3 * block_y; i < 3 * block_y + 3; i++)
    {
        for (int j = 3 * block_y; j < 3 * block_x + 3; j++)
        {
            if (board[i][j] == k)
                return true;
        }
    }
    return false;
}

bool finish = false;

void sudoku(vector<int> board[9])
{
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            cout << board[i][j];
        }
        cout << '\n';
    }
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
                    if (!isin[i][j][k])
                    {
                        if (!f(board, i, j, k))
                        {
                            isin[i][j][k] = true;
                            board[i][j] = k;
                            cout << i << ' ' << j << ' ' << k << '\n';
                            sudoku(board);
                            board[i][j] = 0;
                            cout << "빽\n";
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