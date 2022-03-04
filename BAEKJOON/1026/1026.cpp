#include <iostream>
#include <algorithm>
using namespace std;

int A[50], B[50], N;

bool desc(int a, int b)
{
    return a > b;
}

void solve()
{
    int sum = 0;
    cin >> N;
    for (int i = 0; i < N; i++)
        cin >> A[i];
    for (int i = 0; i < N; i++)
        cin >> B[i];
    sort(A, A + N);
    sort(B, B + N, desc);
    for (int i = 0; i < N; i++)
    {
        sum += A[i] * B[i];
    }
    cout << sum;
}

int main()
{
    solve();
    return 0;
}