#include <iostream>
#include <queue>
#include <map>
#include <algorithm>
using namespace std;

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};

int main(int argc, const char *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int start = 0;
    int temp;

    //예시로 입력받은 것을 193425786처럼 만든다.
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cin >> temp;
            if (temp == 0)
                temp = 9;

            start = start * 10 + temp;
        }
    }

    map<int, int> dist; // key, value쌍
    queue<int> q;
    q.push(start);   // 193425786
    dist[start] = 0; //처음 위치까지 움직인 수는 0(초기값)

    while (!q.empty())
    {
        int now_num = q.front();             //큐의 제일 앞 원소 저장
        string now_str = to_string(now_num); //문자열로 만들어줌
        q.pop();

        int z = (int)now_str.find('9'); // 9가 저장되어 있는 Index를 찾아줌
        int x = z / 3;                  // x좌표는 상하
        int y = z % 3;                  // y좌표는 좌우

        for (int i = 0; i < 4; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx < 0 || nx > 2 || ny < 0 || ny > 2)
                continue; //범위 벗어나면 continue
            string next_str = now_str;
            swap(next_str[x * 3 + y], next_str[nx * 3 + ny]); //교환
            int next_num = stoi(next_str);

            if (dist.count(next_num) == 0)
            {                                       //처음 가는 길이라면
                dist[next_num] = dist[now_num] + 1; // 1추가
                q.push(next_num);
            }
        }
    }

    if (dist.count(123456789) == 0)
        cout << "-1" << '\n';
    else
        cout << dist[123456789] << '\n';

    return 0;
}