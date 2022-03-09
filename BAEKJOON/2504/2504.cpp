#include <iostream>
#include <string>
#include <stack>
using namespace std;

string s;
int arr[31];

void solve()
{
    cin >> s;
    stack<pair<int, int>> st; // 1( 2[
    for (int i = 0; i < s.size(); i++)
    {
        switch (s[i])
        {
        case '(':
            st.push({1, i});
            arr[i] = 2;
            break;
        case ')':
            if (!st.empty() && st.top().first == 1)
            {
                int sum = 0;
                for (int j = st.top().second + 1; j < i; j++)
                {
                    if (arr[j] != 0)
                    {
                        sum += arr[j];
                        arr[j] = 0;
                    }
                }
                if (sum != 0)
                    arr[st.top().second] *= sum;
                st.pop();
            }
            else
            {
                cout << '0';
                return;
            }
            break;
        case '[':
            st.push({2, i});
            arr[i] = 3;
            break;
        case ']':
            if (!st.empty() && st.top().first == 2)
            {
                int sum = 0;
                for (int j = st.top().second + 1; j < i; j++)
                {
                    if (arr[j] != 0)
                    {
                        sum += arr[j];
                        arr[j] = 0;
                    }
                }
                if (sum != 0)
                    arr[st.top().second] *= sum;
                st.pop();
            }
            else
            {
                cout << '0';
                return;
            }
            break;
        }
    }
    if (!st.empty())
    {
        cout << '0';
        return;
    }
    int sum = 0;
    for (int i = 0; i < s.size(); i++)
    {
        sum += arr[i];
    }
    cout << sum;
}

int main()
{
    solve();
    return 0;
}