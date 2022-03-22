#include <iostream>
#include <vector>
using namespace std;

int arr[50][50];
int ym[4] = {0, 1, 0, -1};
int xm[4] = {-1, 0, 1, 0};
// 북서남동 순서.(↑,←,↓,→) 왼쪽으로 도니까
int N, M;
typedef struct vecuum
{
    int r, c, d;
} vecuum;
vecuum V;

void input()
{
    cin >> N >> M;
    cin >> V.r >> V.c >> V.d;
    if (V.d == 1)
        V.d = 3;
    else if (V.d == 3)
        V.d = 1;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            cin >> arr[i][j];
        }
    }
}

void simul()
{
    while (arr[V.r][V.c] != 1) // 시작지점이 벽일 때를 대비
    {
        arr[V.r][V.c] = 2;          // 해당칸 청소
        bool isgo = false;          // 전진 여부
        for (int i = 0; i < 4; i++) // 왼쪽으로 돌며 사방 확인
        {
            if (arr[V.r + ym[V.d]][V.c + xm[V.d]] == 0)
            {                // 왼쪽칸이 빈칸이라면
                isgo = true; // 해당칸으로 전진
                V.r += ym[V.d];
                V.c += xm[V.d];
                V.d = (V.d + 1) % 4; // 왼쪽으로 회전
                break;
            }
            V.d = (V.d + 1) % 4; // 왼쪽으로 회전
        }
        if (!isgo)
        { // 사방으로 갈 수 없으며
            if (arr[V.r + ym[(V.d + 1) % 4]][V.c + xm[(V.d + 1) % 4]] == 1)
            {           // 뒤가 벽이라면
                return; //종료
            }
            else
            {                             // 뒤가 이미 청소한 길이라면
                V.r += ym[(V.d + 1) % 4]; // 방향 유지한체 후진
                V.c += xm[(V.d + 1) % 4];
            }
        }
    }
}

void print()
{
    int ans = 0;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            // cout << arr[i][j] << ' ';
            if (arr[i][j] == 2)
                ans++;
        }
        // cout << '\n';
    }
    cout << ans;
}

void solve()
{
    input();
    simul();
    print();
    return;
}

int main()
{
    solve();
    return 0;
}