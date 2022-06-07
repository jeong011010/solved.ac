#include <iostream>
#include <stack>
using namespace std;

int T;

void cal()
{

    stack<int> n, f; // +:1 *:2 (:3 ):4
    string s, s2 = "";
    cin >> s;
    for (int i = 0; i < s.size(); i++)
    {
        switch (s[i])
        {
        case '+':
            f.push(1);
            break;
        case '*':
            f.push(2);
            break;
        case '(':
            f.push(3);
            break;
        case ')':

            break;

        default:

            break;
        };
    }
}

void solve()
{
    cin >> T;
    while (T--)
    {
        cal();
    }
}

int main()
{
    cout << (int)'1';
    // solve();
    return 0;
}