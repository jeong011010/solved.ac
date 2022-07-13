#include <iostream>
using namespace std;

bool R[9][9], C[9][9], S[9][9]; // Row, Col, Square
int MAP[9][9];

void input()
{
    string s;
    for (int i = 0; i < 9; i++)
    {
        cin >> s;
        for (int j = 0; j < 9; j++)
        {
            MAP[i][j] = s[j] - 48;
            if (MAP[i][j] != 0)
            {
                R[i][MAP[i][j]] = true;
                C[j][MAP[i][j]] = true;
                S[(i / 3) * 3 + (j / 3)][MAP[i][j]] = true;
            }
        }
    }
}

void print()
{
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            cout << MAP[i][j];
        }
        cout << '\n';
    }
}

void DFS(int cnt)
{

    int x = cnt / 9;
    int y = cnt % 9;

    if (cnt == 81)
    {
        print();
        exit(0);
    }

    if (MAP[x][y] == 0)
    {
        for (int i = 1; i <= 9; i++)
        {
            if (R[x][i] == false && C[y][i] == false && S[(x / 3) * 3 + (y / 3)][i] == false)
            {
                R[x][i] = true;
                C[y][i] = true;
                S[(x / 3) * 3 + (y / 3)][i] = true;
                MAP[x][y] = i;
                DFS(cnt + 1);
                R[x][i] = false;
                C[y][i] = false;
                S[(x / 3) * 3 + (y / 3)][i] = false;
                MAP[x][y] = 0;
            }
        }
    }
    else
        DFS(cnt + 1);
}

void solve()
{
    input();
    DFS(0);
}

int main()
{
    solve();
    return 0;
}