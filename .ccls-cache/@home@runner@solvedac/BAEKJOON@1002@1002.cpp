#include <iostream>
#include <cmath>
using namespace std;

int y, x1, r1, x2, y2, r2, t, d;

void solve()
{
    cin >> t;
    while (t--)
    {
        cin >> x1 >> y >> r1 >> x2 >> y2 >> r2;

        d = (x1 - x2) * (x1 - x2) + (y - y2) * (y - y2);
        int cond1 = (r1 - r2) * (r1 - r2);
        int cond2 = (r1 + r2) * (r1 + r2);
        if (d == 0)
        {
            if (cond1 == 0)
                cout << "-1" << '\n';
            else
                cout << "0" << '\n';
        }
        else if (d == cond1 || d == cond2)
            cout << "1" << '\n';
        else if (cond1 < d && d < cond2)
            cout << "2" << '\n';
        else
            cout << "0" << '\n';
    }
}

int main()
{
    solve();
    return 0;
}