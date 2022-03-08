#include <iostream>
#include <cmath>
#include <cstring>
using namespace std;
const int MAX = 300000 + 1;
int P;
int visited[MAX];

void DFS(int num)
{
    visited[num]++;
    if (visited[num] == 3)
        return;
    int sum = 0;
    while (num)
    {
        sum += (int)pow((num % 10), P);
        num /= 10;
    }
    DFS(sum);
}

int main(void)

{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int A;
    cin >> A >> P;
    DFS(A);
    int result = 0;
    for (int i = 0; i < MAX; i++)
        if (visited[i] == 1)
            result++;
    cout << result << "\n";
    return 0;
}