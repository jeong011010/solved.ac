#include <iostream>
#include <deque>
using namespace std;

deque<int> v[4]; // v[0][2] : v[1][6], v[1][2] : v[2][6] , v[2][2] : v[3][6]
int K;

void turn(int n, int mode)
{
    if (mode == -1)
    {
        v[n].push_back(v[n].front());
        v[n].pop_front();
    }
    else
    {
        v[n].push_front(v[n].back());
        v[n].pop_back();
    }
}

void run(int n, int mode, int path)
{
    if (n > 0 && path == -1)
    {
        if (v[n][6] != v[n - 1][2])
        {
            run(n - 1, -1 * mode, -1);
            turn(n - 1, -1 * mode);
        }
    }
    if (n < 3 && path == 1)
    {
        if (v[n][2] != v[n + 1][6])
        {
            run(n + 1, -1 * mode, 1);
            turn(n + 1, -1 * mode);
        }
    }
}

void print()
{
    int point[4] = {1, 2, 4, 8};
    int ans = 0;
    for (int i = 0; i < 4; i++)
    {
        if (v[i][0] == '1')
            ans += point[i];
    }
    cout << ans;
}

void p()
{
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            cout << char(v[i][j]);
        }
        cout << '\n';
    }
    cout << '\n';
}

void solve()
{
    string s;
    for (int i = 0; i < 4; i++)
    {
        cin >> s;
        for (int j = 0; j < 8; j++)
        {
            v[i].push_back(s[j]);
        }
    }
    cin >> K;
    int n, mode;
    for (int i = 0; i < K; i++)
    {
        cin >> n >> mode;
        run(n - 1, mode, 1);
        run(n - 1, mode, -1);
        turn(n - 1, mode);
        // p();
    }
    print();
}

int main()
{
    solve();
    return 0;
}