#include <iostream>
#include <deque>
#include <vector>
#include <queue>
using namespace std;

int N, K, L, P = 0; // 0:R, 1:D, 2:L, 3:U
queue<pair<int, int>> turn;
deque<pair<int, int>> snake;

int board[101][101];
int my[4] = {0, 1, 0, -1};
int mx[4] = {1, 0, -1, 0};

void input()
{
    cin >> N >> K;
    int y, x;
    for (int i = 0; i < K; i++)
    {
        cin >> y >> x;
        board[y][x] = 2;
    }
    board[1][1] = 1;
    snake.push_front({1, 1});
    cin >> L;
    int len;
    char p;
    for (int i = 0; i < L; i++)
    {
        cin >> len >> p;
        turn.push({len, (p == 'D' ? 1 : -1)}); // 오른쪽:1 , 왼쪽:-1
    }
}

void print()
{
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            cout << board[i][j];
        }
        cout << '\n';
    }
    cout << '\n';
}

void simul()
{
    int ans = 0;
    int hy, hx;
    int cnt = turn.front().first;
    while (1)
    {
        // cout << '\n';
        // print();
        // cout << ans << '\n';
        hy = snake.front().first;
        hx = snake.front().second;
        if (cnt == ans)
        {
            int tmp = P + turn.front().second;

            if (turn.size() == 0)
            {
                break;
            }
            turn.pop();
            cnt = turn.front().first;
            if (tmp == -1)
            {
                P = 3;
            }
            else if (tmp == 4)
            {
                P = 0;
            }
            else
                P = tmp;
        }
        // cout << P << ' ' << hy << ',' << hx << ':' << cnt << '\n';
        int ny = hy + my[P];
        int nx = hx + mx[P];
        if (ny == 0 || nx == 0 || ny > N || nx > N)
        {
            // cout << ny << "," << nx << '\n';
            break;
        }
        if (board[ny][nx] == 2)
        {
            board[ny][nx] = 1;
            snake.push_front({ny, nx});
        }
        else if (board[ny][nx] == 1)
        {
            break;
        }
        else
        {
            board[ny][nx] = 1;
            board[snake.back().first][snake.back().second] = 0;
            snake.push_front({ny, nx});
            snake.pop_back();
        }
        ans++;
    }
    cout << ans + 1;
}

void solve()
{
    input();
    simul();
}

int main()
{
    solve();
    return 0;
}