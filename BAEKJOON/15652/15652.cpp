#include<iostream>
using namespace std;

int N,M;
int arr[9];

void dfs(int n,int cnt){
    if(cnt==M){
        for(int i=0;i<M;i++)
            cout<<arr[i]<<' ';
        cout<<'\n';
        return;
    }
    for(int i=n;i<=N;i++){
        arr[cnt]=i;
        dfs(i,cnt+1);
    }
}

void solve(){
    cin>>N>>M;
    dfs(1,0);
}

int main(){
    solve();
    return 0;
}