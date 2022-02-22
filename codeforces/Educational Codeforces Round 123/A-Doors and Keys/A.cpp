#include <iostream>
#include <string>
using namespace std;

int t;

bool check(string way)
{
    bool r, g, b;
    r = g = b = false;
    for (int i = 0; i < 6; i++)
    {
        if (way[i] == 'r')
            r = true;
        else if (way[i] == 'g')
            g = true;
        else if (way[i] == 'b')
            b = true;
        else if (way[i] == 'R' && !r)
            return false;
        else if (way[i] == 'G' && !g)
            return false;
        else if (way[i] == 'B' && !b)
            return false;
    }
    return true;
}

void solve()
{

    cin >> t;
    for (int i = 0; i < t; i++)
    {
        string way;
        cin >> way;

        cout << (check(way) ? "YES" : "NO") << '\n';
    }
}

int main()
{
    solve();
    return 0;
}