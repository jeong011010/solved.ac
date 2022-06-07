#include <iostream>
#include <cmath>
using namespace std;

int N;
long amax = -1000000000;
long amin = 1000000000;
int num[11], flag[4], f[10];

void input()
{
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        cin >> num[i];
    }
    for (int i = 0; i < 4; i++)
    {
        cin >> flag[i];
    }
}

void cal()
{
    long sum = num[0];
    float tmp = 0;
    for (int i = 0; i < N - 1; i++)
    {
        switch (f[i])
        {
        case 0:
            sum += num[i + 1];
            break;
        case 1:
            sum -= num[i + 1];
            break;
        case 2:
            sum *= num[i + 1];
            break;
        case 3:
            sum = (sum / num[i + 1]);
            break;
        }
    }
    amax = max(amax, sum);
    /*if (amax == sum)
    {
        for (int i = 0; i < N - 1; i++)
        {
            cout << num[i];
            switch (f[i])
            {
            case 0:
                cout << '+';
                break;
            case 1:
                cout << '-';
                break;
            case 2:
                cout << '*';
                break;
            case 3:
                cout << '%';
                break;
            }
        }
        cout << num[N - 1];
        cout << ':' << sum << '\n';
    }*/
    amin = min(amin, sum);
    /*if (amin == sum)
    {
        for (int i = 0; i < N - 1; i++)
        {
            cout << num[i];
            switch (f[i])
            {
            case 0:
                cout << '+';
                break;
            case 1:
                cout << '-';
                break;
            case 2:
                cout << '*';
                break;
            case 3:
                cout << '%';
                break;
            }
        }
        cout << num[N - 1];
        cout << ':' << sum << '\n';
    }*/
}

void bf(int n)
{
    if (n == N - 1)
    {
        cal();
        return;
    }
    for (int i = 0; i < 4; i++)
    {
        if (flag[i] > 0)
        {
            flag[i]--;
            f[n] = i;
            // cout << f[n] << '\n';
            bf(n + 1);
            // cout << "delete" << n << '\n';
            flag[i]++;
        }
    }
    return;
}

void solve()
{
    input();
    bf(0);
    cout << amax << '\n'
         << amin << '\n';
}

int main()
{
    solve();
    return 0;
}
