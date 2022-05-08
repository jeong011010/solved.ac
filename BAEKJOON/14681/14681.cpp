#include <iostream>
using namespace std;

int x, y;

void solve()
{
    cin >> x >> y;
    if (x > 0)
    {
        if (y > 0)
            cout << 1;
        else
            cout << 4;
    }
    else
    {
        if (y > 0)
            cout << 2;
        else
            cout << 3;
    }
}

int main()
{
    solve();
    return 0;
}