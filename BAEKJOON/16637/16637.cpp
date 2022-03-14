#include <iostream>
#include <vector>
using namespace std;

int N, K;
int sd[100];
int tap[100];
bool use[101];

void solve()
{
    cin >> N >> K;
    int cnt = 0, ans = 0;
    for (int i = 0; i < K; i++)
    {
        cin >> sd[i];
    }
    for (int i = 0; i < K; i++)
    {
        if (use[sd[i]])
        {
            continue;
        }
        else if (cnt < N)
        {
            use[sd[i]] = 1;
            tap[cnt++] = sd[i];
        }
        else
        {
            ans++;
            bool allin = true;
            int m = 0, tmp = 0;
            for (int j = 0; j < N; j++)
            {
                bool isin = false;
                for (int k = i; k < K; k++)
                {
                    if (sd[k] == tap[j])
                    {
                        if (m < k)
                        {
                            m = k;
                            tmp = j;
                        }
                        isin = true;
                        break;
                    }
                }
                if (!isin)
                {
                    allin = false;
                    use[tap[j]] = 0;
                    use[sd[i]] = 1;
                    tap[j] = sd[i];
                    break;
                }
            }
            if (allin)
            {
                use[tap[tmp]] = 0;
                use[sd[i]] = 1;
                tap[tmp] = sd[i];
            }
        }
    }
    cout << ans;
}

int main()
{
    solve();
    return 0;
}