#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, M, K;
double score[101];
vector<double> sv;

void solve()
{
    cin >> N >> M >> K;
    for (int i = 0; i < M; i++)
    {
        int I;
        double S;
        for (int j = 0; j < N; j++)
        {
            cin >> I >> S;
            score[I] = max(S, score[I]);
        }
    }
    for (int i = 1; i <= N; i++)
    {
        sv.push_back(score[i]);
    }
    sort(sv.begin(), sv.end());
    double ans = 0.0;
    for (int i = N - 1; i >= N - K; i--)
    {
        ans += sv[i];
    }
    printf("%.1lf", ans);
}

int main()
{
    solve();
    return 0;
}