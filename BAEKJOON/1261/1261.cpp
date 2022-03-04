#include <iostream>
#include <deque>
using namespace std;

int N, M;
int arr[101][101];
bool visited[101][101];
int mx[4] = {0, -1, 0, 1};
int my[4] = {1, 0, -1, 0};

struct Info
{
    int x, y, sum;
};

void bfs()
{
    deque<Info> dq;
    dq.push_back({0, 0, 0});
    visited[0][0] = true;
    while (!dq.empty())
    {
        auto cur = dq.front();
        dq.pop_front();
        int x = cur.x;
        int y = cur.y;
        int sum = cur.sum;
        if (x == N - 1 && y == M - 1)
        {
            cout << sum;
            return;
        }
        for (int i = 0; i < 4; i++)
        {
            int nx = x + mx[i];
            int ny = y + my[i];
            if (nx < 0 || nx >= N || ny < 0 || ny >= M)
                continue;
            if (visited[nx][ny])
                continue;
            visited[nx][ny] = true;
            if (arr[nx][ny])
                dq.push_back({nx, ny, sum + 1});
            else
                dq.push_front({nx, ny, sum});
        }
    }
}

void solve()
{
    cin >> M >> N;
    string tmp;
    for (int i = 0; i < N; i++)
    {
        cin >> tmp;
        for (int j = 0; j < M; j++)
        {
            arr[i][j] = tmp[j] - 48;
        }
    }
    bfs();
}

int main()
{
    solve();
    return 0;
}