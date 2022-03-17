#include <iostream>
#include <vector>
using namespace std;

int N;
vector<int> dp;

void solve()
{
    dp.push_back(3);             // 2
    dp.push_back(3 * 3 + 1 * 2); // 4
}

int main()
{
    solve();
    return 0;
}