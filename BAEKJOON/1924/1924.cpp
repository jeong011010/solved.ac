#include <iostream>
using namespace std;

int x, y;
int date[12] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30};
string dotw[7] = {
    "SUN",
    "MON",
    "TUE",
    "WED",
    "THU",
    "FRI",
    "SAT"};

void solve()
{
    cin >> x >> y;
    int ans = 0;
    for (int i = 0; i < x; i++)
    {
        ans += date[i];
    }
    ans += y;
    cout << dotw[ans % 7];
}

int main()
{
    solve();
    return 0;
}