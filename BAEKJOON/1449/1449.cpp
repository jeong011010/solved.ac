#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int L, N;

void solve()
{
    cin >> N >> L;
    vector<int> pipe;
    int tmp;
    for (int i = 0; i < N; i++)
    {
        cin >> tmp;
        pipe.push_back(tmp);
    }
    sort(pipe.begin(), pipe.end());
    int now = pipe[0];
    int n = 0, use = 0;
    if (L == 1)
    {
        cout << N;
        return;
    }
    while (now <= pipe[pipe.size() - 1])
    {
        n++;
        use++;
        now += L - 1;
        if (now >= pipe[n])
        {
            while (now >= pipe[n])
            {
                n++;
            }
            now = pipe[n];
        }
        else
            now = pipe[n];
        // cout << now << ' ' << use << ' ' << n << '\n';
    }
    cout << use;
}

int main()
{
    solve();
    return 0;
}