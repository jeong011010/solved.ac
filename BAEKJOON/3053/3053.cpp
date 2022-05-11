#include <iostream>
#include <cmath>
using namespace std;

void solve()
{
    double R;
    cin >> R;
    printf("%.6lf\n%.6lf", R * R * M_PI, R * R * 2);
}

int main()
{
    solve();
    return 0;
}