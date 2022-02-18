#include<iostream>
#include<algorithm>
using namespace std;

int N,M;
int arr[9];
int ans[9];

void dfs(int cnt){
    
    if(cnt==M){
        for(int i=0;i<M;i++)
            cout<<ans[i]<<' ';
        cout<<'\n';
        return;
    }
    for(int i=0;i<N;i++){
        bool isIn=false;
        for(int j=0;j<cnt;j++)
            if(ans[j]==arr[i]){
                isIn=true; break;}
        if(!isIn){
            ans[cnt]=arr[i];
            dfs(cnt+1);
        }
    }
}

void solve(){
    cin>>N>>M;
    for(int i=0;i<N;i++)
        cin>>arr[i];
    sort(arr, arr+N);
    dfs(0);
}

int main(){
    solve();
    return 0;
}