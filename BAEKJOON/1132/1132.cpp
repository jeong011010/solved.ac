#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int N;
long long arr[10];

void solve()
{
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        string s;
        cin >> s;
        long long tmp = 1;
        for (int j = s.size() - 1; j >= 0; j--)
        {
            arr[(int)s[j] - 65] += tmp;
            tmp *= 10;
        }
    }
    for (int i = 0; i < 10; i++)
    {
        cout << arr[i] << '\n';
    }
    sort(arr, arr + 10, greater<int>());
    long long sum = 0;
    for (int i = 0; i < 10; i++)
    {
        cout << arr[i] << '\n';
        sum += arr[i] * (9 - i);
        cout << sum << '\n';
    }
    cout << sum;
}

int main()
{
    solve();
    return 0;
}