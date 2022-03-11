#include <iostream>
#include <string>

using namespace std;

int n;
long long k;
int ans;

long long cal_length(int x)
{
    // 1 ~ 9 : 9 * 1
    // 10 ~ 99 : 90 * 2
    // 100 ~ 999 : 900 * 3
    //     ....
    long long n_length = 0LL;
    long long n_size = to_string(x).size();
    for (long long add = 9LL, len = 1LL; len < n_size; add *= 10, len += 1)
    {
        n_length += add * len;
    }
    int start = 1;
    // ~ n
    for (int i = 1; i < n_size; i++)
    {
        start *= 10;
    }
    return n_length += n_size * (x - start + 1);
}

void cal(int start, int end)
{
    if (start >= end)
        return;
    int mid = (start + end) / 2;
    if (cal_length(mid) > k)
    {
        cal(start, mid - 1);
    }
    else
    {
        ans = mid;
        cal(mid + 1, end);
    }
}

int main()
{
    scanf("%d %lld", &n, &k);
    long long n_length = cal_length(n);
    if (n_length < k)
    {
        printf("-1\n");
        return 0;
    }
    cal(1, n);
    long long ans_length = cal_length(ans);
    string s = to_string(ans);
    // (ans_length < k) to
    // (k < ans_length)
    while (ans_length < k)
    {
        ans += 1;
        s += to_string(ans);
        ans_length += to_string(ans).size();
    }
    printf("%c\n", s[s.size() - ans_length + k - 1]);
}