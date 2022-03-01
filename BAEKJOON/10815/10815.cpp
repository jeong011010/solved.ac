#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int N, M;

priority_queue<unsigned int> sgCard;
priority_queue<pair<unsigned int, int>> Card;
vector<int> v;

void solve()
{
    unsigned int tmp;
    cin >> N;

    for (int i = 0; i < N; i++)
    {
        cin >> tmp;
        sgCard.push(tmp);
    }
    cin >> M;

    for (int i = 0; i < M; i++)
    {
        cin >> tmp;
        Card.push({tmp, i});
    }
    v.resize(M, 0);

    for (int i = 0; i < M; i++)
    {
        // cout << sgCard.top() << ',' << Card.top().first << '\n';
        if (sgCard.top() == Card.top().first)
        {
            v[Card.top().second] = 1;
            Card.pop();
        }
        else
        {
            v[Card.top().second] = 0;
            Card.pop();
        }

        if (sgCard.top() > Card.top().first)
            sgCard.pop();
    }
    for (int i = 0; i < M; i++)
    {
        cout << v[i] << ' ';
    }
}

int main()
{
    solve();
    return 0;
}