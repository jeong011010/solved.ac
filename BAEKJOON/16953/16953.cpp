#include <iostream>
#include <queue>
using namespace std;

long long A,B;
queue<pair<long long,int>> q;

void solve(){
    cin>>A>>B;
    q.push({A,1});
    while(!q.empty()){
        long long a = q.front().first;
        int cnt = q.front().second;
        q.pop();
        if(a==B){
            cout<<cnt;
            return;
        }
        if(B>a){
            q.push({a*2,cnt+1});
            q.push({a*10+1,cnt+1});
        }
    }
    cout<<"-1";
    return;
}

int main(){
    solve();
    return 0;
}