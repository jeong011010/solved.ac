#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void solve()
{
    int N, M, tmp;
    cin >> N;
    vector<int> A, B;
    for (int i = 0; i < N; i++)
    {
        cin >> tmp;
        A.push_back(tmp);
    }

    sort(A.begin(), A.end());
    cin >> M;
    for (int i = 0; i < M; i++)
    {
        cin >> tmp;
        B.push_back(tmp);
    }
    for (int i = 0; i < M; i++)
    {
        int ans = 0;
        int left = 0, right = N - 1, mid;
        while (left <= right)
        {
            mid = (right + left) / 2;
            if (B[i] > A[mid])
                left = mid + 1;
            else if (B[i] < A[mid])
                right = mid - 1;
            else
            {
                ans = 1;
                break;
            }
        }
        cout << ans << '\n';
    }
}

int main()
{
    solve();
    return 0;
}