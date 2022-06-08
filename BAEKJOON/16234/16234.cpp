#include <iostream>
#include <stack>
#include <cmath>
using namespace std;

int board[50][50];
int N, L, R;

int my[4] = {0, 1, 0, -1};
int mx[4] = {1, 0, -1, 0};

void input()
{
    cin >> N >> L >> R;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cin >> board[i][j];
        }
    }
}

bool dfs()
{
    bool isopen = false;
    bool check[50][50] = {0};
    stack<pair<int, int>> s;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (check[i][j])
            {
                continue;
            }
            stack<pair<int, int>> open;
            int sum = board[i][j];
            int n = 1;
            s.push({i, j});
            open.push({i, j});
            while (!s.empty())
            {
                check[i][j] = 1;
                int y = s.top().first;
                int x = s.top().second;
                s.pop();
                for (int k = 0; k < 4; k++)
                {
                    int ny = y + my[k];
                    int nx = x + mx[k];
                    int tmp = abs(board[y][x] - board[ny][nx]);
                    // cout << tmp << ',' << ny << ',' << nx << ',' << check[ny][nx] << '\n';
                    if (!check[ny][nx] && ny >= 0 && ny < N &&
                        nx >= 0 && nx < N && tmp >= L && tmp <= R)
                    {
                        // cout << "헉\n";
                        isopen = true;
                        sum += board[ny][nx];
                        n++;
                        check[ny][nx] = 1;
                        s.push({ny, nx});
                        open.push({ny, nx});
                    }
                }
            }
            sum /= n;
            while (!open.empty())
            {
                board[open.top().first][open.top().second] = sum;
                open.pop();
            }
        }
    }
    return isopen;
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
    cout << '\n';
}

void f()
{
    int cnt = 0;
    while (dfs())
    {
        // print();
        //  cout << "!";
        cnt++;
    }
    cout << cnt;
}

void solve()
{
    input();
    f();
}
int main()
{
    solve();
    return 0;
}