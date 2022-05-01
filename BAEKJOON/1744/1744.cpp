#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int N;
vector<int> v1, v2;

void solve()
{
    cin >> N;
    int tmp;
    for (int i = 0; i < N; i++)
    {
        cin >> tmp;
        if (tmp > 0)
            v1.push_back(tmp);
        else
            v2.push_back(tmp);
    }
    sort(v1.begin(), v1.end());
    sort(v2.begin(), v2.end());

    int a = v1.size() - 1, b = 0, sum = 0;

    while (a > 0 && v1.size() > 1)
    {
        if (v1[a] == 1)
        {
            sum += (a + 1);
            a = -1;
            break;
        }
        else if (v1[a - 1] == 1)
        {
            sum += (a);
            sum += v1[a];
            a = -1;
            break;
        }
        sum += (v1[a] * v1[a - 1]);
        a -= 2;
    }
    if (a == 0)
        sum += v1[0];
    while (b < v2.size() - 1 && v2.size() > 1)
    {

        sum += (v2[b] * v2[b + 1]);
        b += 2;
    }
    if (b == v2.size() - 1)
        sum += v2[v2.size() - 1];
    cout << sum;
}

int main()
{
    solve();
    return 0;
}