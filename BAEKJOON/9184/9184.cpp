#include <iostream>
using namespace std;

int DP[21][21][21];

int f(int a, int b, int c)
{
    if (a <= 0 || b <= 0 || c <= 0)
        return 1;
    if (a > 20 || b > 20 || c > 20)
        return f(20, 20, 20);
    if (DP[a][b][c])
        return DP[a][b][c];
    if (a < b && b < c)
    {
        DP[a][b][c] = f(a, b, c - 1) + f(a, b - 1, c - 1) - f(a, b - 1, c);
        return DP[a][b][c];
    }
    DP[a][b][c] = f(a - 1, b, c) + f(a - 1, b - 1, c) + f(a - 1, b, c - 1) - f(a - 1, b - 1, c - 1);
    return DP[a][b][c];
}

void solve()
{

    int a, b, c;
    cin >> a >> b >> c;
    while (a != -1 || b != -1 || c != -1)
    {
        cout << "w(" << a << ", " << b << ", " << c << ") = " << f(a, b, c) << '\n';
        cin >> a >> b >> c;
    }
}

int main()
{
    solve();
    return 0;
}