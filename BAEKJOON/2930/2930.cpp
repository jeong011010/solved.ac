#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int R, N;
string sang;
string friends[51];

void solve()
{
    cin >> R >> sang >> N;
    for (int i = 0; i < N; i++)
    {
        cin >> friends[i];
    }

    int score = 0;
    for (int i = 0; i < R; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (sang[i] == friends[j][i])
                score++; //비겼을 때
            else
            {
                if (sang[i] == 'R' && friends[j][i] == 'S' ||
                    sang[i] == 'S' && friends[j][i] == 'P' ||
                    sang[i] == 'P' && friends[j][i] == 'R') //이겼을 때
                    score += 2;
            }
        }
    }
    cout << score << '\n';

    score = 0;
    for (int i = 0; i < R; i++)
    {
        int n[3], x = 0;
        for (int j = 0; j < 3; j++)
            n[j] = 0;
        for (int j = 0; j < N; j++)
        {
            if (friends[j][i] == 'R')
                n[0]++;
            else if (friends[j][i] == 'S')
                n[1]++;
            else if (friends[j][i] == 'P')
                n[2]++;
        }
        int sum, ans = 0;
        for (int j = 0; j < 3; j++)
        {
            sum = 0;
            sum += n[j];
            sum += n[(j + 1) % 3] * 2;
            ans = max(sum, ans);
        }
        score += ans;
    }
    cout << score << '\n';
}

int main()
{
    solve();
    return 0;
}