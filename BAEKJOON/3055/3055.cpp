#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int arr[50][50];
bool visited[50][50];
int xm[4] = {1, 0, -1, 0};
int ym[4] = {0, 1, 0, -1};
int R, C;
int y, x;

typedef struct MOVE
{
    int y, x, c;
} MOVE;

queue<MOVE> s, w;
void bfs()
{
    while (!s.empty())
    {

        int ws = w.size();
        for (int i = 0; i < ws; i++)
        {
            MOVE wm = w.front();
            w.pop();
            for (int j = 0; j < 4; j++)
            {
                int ny = wm.y + ym[j];
                int nx = wm.x + xm[j];
                if (ny >= 0 && nx >= 0 && ny < R && nx < C)
                {
                    if (arr[ny][nx] == 0)
                    {
                        arr[ny][nx] = 1;
                        w.push({ny, nx, wm.c + 1});
                    }
                }
            }
        }
        int ss = s.size();
        for (int i = 0; i < ss; i++)
        {
            MOVE sm = s.front();
            visited[sm.y][sm.x] = true;
            s.pop();
            for (int j = 0; j < 4; j++)
            {
                int ny = sm.y + ym[j];
                int nx = sm.x + xm[j];
                if (ny >= 0 && nx >= 0 && ny < R && nx < C)
                {
                    if (arr[ny][nx] == 0 && !visited[ny][nx])
                    {
                        s.push({ny, nx, sm.c + 1});
                        visited[ny][nx] = true;
                    }
                    else if (arr[ny][nx] == 9)
                    {
                        cout << sm.c + 1;
                        return;
                    }
                }
            }
        }
    }
    cout << "KAKTUS";
    return;
}

void solve()
{
    string tmp;
    cin >> R >> C;
    for (int i = 0; i < R; i++)
    {
        cin >> tmp;
        for (int j = 0; j < C; j++)
        {
            switch (tmp[j])
            {
            case '.':
                arr[i][j] = 0;
                break;
            case 'X':
                arr[i][j] = 1;
                break;
            case '*':
                w.push({i, j, 0});
                arr[i][j] = 2;
                break;
            case 'S':
                s.push({i, j, 0});
                arr[i][j] = 0;
                break;
            case 'D':
                arr[i][j] = 9;
                break;
            }
        }
    }
    bfs();
}

int main()
{
    solve();
    return 0;
}