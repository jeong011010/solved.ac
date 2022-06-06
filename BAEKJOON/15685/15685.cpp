#include <iostream>
#include <deque>
#include <vector>
using namespace std;

int N;
bool board[101][101];
deque<int> dq[20];
vector<pair<pair<int, int>, int>> start;
int my[4] = {0, -1, 0, 1};
int mx[4] = {1, 0, -1, 0};

void input()
{
    int x, y, d, g;
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        cin >> x >> y >> d >> g;
        start.push_back({{x, y}, g});
        dq[i].push_back(d);
        board[y][x] = 1;
    }
}

void curb()
{
    int x, y, g;
    for (int i = 0; i < N; i++)
    {
        x = start[i].first.first;
        y = start[i].first.second;
        g = start[i].second;
        int tmp = 1;

        y += my[dq[i][0]];
        x += mx[dq[i][0]];
        board[y][x] = 1;
        dq[i].push_front((dq[i][0] + 1) % 4);

        for (int j = 1; j <= g; j++)
        {
            for (int k = 0; k < tmp; k++)
            {
                y += my[dq[i][tmp - k - 1]];
                x += mx[dq[i][tmp - k - 1]];
                board[y][x] = 1;
            }
            tmp *= 2;
            for (int k = 0; k < tmp; k++)
            {
                dq[i].push_front((dq[i][k + k] + 1) % 4);
            }
        }
    }
}

void find_square()
{
    int ans = 0;
    for (int i = 0; i < 101; i++)
    {
        for (int j = 0; j < 101; j++)
        {
            if (board[i][j] == 1)
            {
                if (board[i + 1][j] && board[i][j + 1] && board[i + 1][j + 1])
                {
                    ans++;
                }
                board[i][j] = 0;
            }
        }
    }
    cout << ans;
}

void solve()
{
    input();
    curb();
    find_square();
}

int main()
{
    solve();
    return 0;
}