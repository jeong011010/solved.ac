#include <iostream>
using namespace std;

int Arr[5][5];
int N;
long long B;

void mul(int F[5][5], int M[5][5])
{
    int tmp[5][5] = {
        0,
    };
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            for (int k = 0; k < N; k++)
            {
                tmp[i][j] += (F[i][k] * M[k][j]);
            }
        }
    }
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            F[i][j] = tmp[i][j] % 1000;
        }
    }
}

void power(int F[5][5], long long n)
{
    if (n == 0 || n == 1)
        return;
    power(F, n / 2);
    mul(F, F);
    if (n % 2 != 0)
        mul(F, Arr);
}

void print(int Ans[5][5])
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
            cout << Ans[i][j] % 1000 << ' ';
        cout << '\n';
    }
}

void solve()
{
    cin >> N >> B;
    int tmp[5][5];
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
        {
            cin >> Arr[i][j];
            tmp[i][j] = Arr[i][j];
        }
    power(tmp, B);
    print(tmp);
}

int main()
{
    solve();
    return 0;
}