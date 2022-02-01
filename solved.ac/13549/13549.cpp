#include<iostream>
#include<queue>
using namespace std;

int N,K;
queue<pair<int,int>> q;
bool check[100001];
int ans=1e9+7;

void bfs(){
    bool b=false;
    q.push(make_pair(N,0));
    while(!q.empty()){
        int x = q.front().first;
        int t = q.front().second;
        //cout<<x<<' '<<t<<'\n';
        q.pop();
        if(x==K){
            b= true;
            ans = min(t,ans);
            //cout<<ans<<'\n';
        }

        check[x]=true;

        if(x-1>=0 && !check[x-1] && !b)
            q.push(make_pair(x-1,t+1));
        if(x<K && !b){
            if(x+1<=100000 && !check[x+1])
                q.push(make_pair(x+1,t+1));
            if(x*2<=100000 && !check[x*2])
                q.push(make_pair(x*2,t));
        }
    }
    cout<<ans;
}

void solve(){
    cin>>N>>K;
    bfs();
}

int main(){
    solve();
    return 0;
}