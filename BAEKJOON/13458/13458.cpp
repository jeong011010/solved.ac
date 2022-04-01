#include <iostream>
#include <cmath>
using namespace std;

long long B, C;
double A[1000000];
long long N, ans = 0;

void solve()
{
    cin >> N;
    for (int i = 0; i < N; i++)
        cin >> A[i];
    cin >> B >> C;
    for (int i = 0; i < N; i++)
    {
        ans++;
        if (A[i] - B > 0)
        {
            ans += ceil((A[i] - B) / C);
        }
    }
    cout << ans;
}

int main()
{
    solve();
    return 0;
}