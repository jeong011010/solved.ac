#include <iostream>
#include <vector>
using namespace std;

int N, S;
vector<int> v;

void solve()
{
    cin >> N >> S;
    int tmp;
    for (int i = 0; i < N; i++)
    {
        cin >> tmp;
        v.push_back(tmp);
    }

    int s = 0, e = 0, sum = v[0], ans = 100001;
    while (1)
    {
        if (sum >= S)
        {
            ans = min(ans, e - s + 1);
            sum -= v[s];
            s++;
        }
        else
        {
            e++;
            sum += v[e];
        }
        if (s == v.size() || (sum < S && e >= v.size()))
        {
            if (ans == 100001)
                cout << 0;
            else
                cout << ans;
            return;
        }
        // cout << s << ' ' << e << ' ' << ans << ' ' << sum << '\n';
    }
}

int main()
{
    solve();
    return 0;
}