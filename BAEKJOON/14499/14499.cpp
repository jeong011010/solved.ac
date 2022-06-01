#include <iostream>
#include <queue>
using namespace std;

int board[20][20];
int dice[6] = {0, 0, 0, 0, 0, 0};
int N, M, x, y, K;
int go[1001];
int my[4] = {0, 0, -1, 1};
int mx[4] = {1, -1, 0, 0};

void input()
{
    cin >> N >> M >> x >> y >> K;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            cin >> board[i][j];
        }
    }
    int mode;
    for (int i = 0; i < K; i++)
    {
        cin >> go[i];
    }
}

void rolling(int k)
{
    int rx[3] = {2, 5, 3};
    int ry[3] = {1, 5, 4};
    switch (k)
    {
    case 1:
        for (int i = 0; i < 3; i++)
            swap(dice[0], dice[rx[i]]);
        break;
    case 2:
        for (int i = 2; i >= 0; i--)
            swap(dice[0], dice[rx[i]]);
        break;
    case 3:
        for (int i = 0; i < 3; i++)
            swap(dice[0], dice[ry[i]]);
        break;
    case 4:
        for (int i = 2; i >= 0; i--)
            swap(dice[0], dice[ry[i]]);
        break;
    }
}

void dicing()
{

    for (int i = 0; i < K; i++)
    {
        int My = x + my[go[i] - 1];
        int Mx = y + mx[go[i] - 1];
        if (My == -1 || Mx == -1 || My == N || Mx == M)
        {
            // cout << My << ',' << Mx << '\n';
            continue;
        } // 맵 이탈
        x = My;
        y = Mx;
        rolling(go[i]); // 주사위 상태변화
        if (board[My][Mx] == 0)
        {
            board[My][Mx] = dice[5];
        }
        else
        {
            dice[5] = board[My][Mx];
            board[My][Mx] = 0;
        }
        cout << dice[0] << '\n';
    }
}

void solve()
{
    input();
    dicing();
}

int main()
{
    solve();
    return 0;
}