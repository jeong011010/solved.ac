#include <iostream>
#include <queue>
using namespace std;

int N;
queue<int> q;

void solve()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N;
    string f;
    int n;
    for (int i = 0; i < N; i++)
    {
        cin >> f;
        if (f == "push")
        {
            cin >> n;
            q.push(n);
        }
        else if (f == "pop")
        {
            if (q.empty())
                cout << "-1\n";
            else
            {
                cout << q.front() << '\n';
                q.pop();
            }
        }
        else if (f == "size")
        {
            cout << q.size() << '\n';
        }
        else if (f == "empty")
        {
            if (q.empty())
                cout << "1\n";
            else
                cout << "0\n";
        }
        else if (f == "front")
        {
            if (q.empty())
                cout << "-1\n";
            else
                cout << q.front() << "\n";
        }
        else if (f == "back")
        {
            if (q.empty())
                cout << "-1\n";
            else
                cout << q.back() << "\n";
        }
    }
}

int main()
{
    solve();
    return 0;
}