#include<iostream>
#include<algorithm>
using namespace std;

int N,M;
int arr[9];
int ans[9];
bool check[9];

void dfs(int cnt){
    if(cnt==M){
        for(int i=0;i<M;i++)
            cout<<ans[i]<<' ';
        cout<<'\n';
        return;
    }
    int tmp=0;
    for(int i=0;i<N;i++){
        if(!check[i]&&arr[i]!=tmp){
            ans[cnt]=arr[i];
            tmp = ans[cnt];
            check[i] = true;
            dfs(cnt+1);
            check[i] = false;
        }
    }
}

void solve(){
    cin>>N>>M;
    int tmp;
    for(int i=0;i<N;i++)
        cin>>arr[i];
    sort(arr,arr+N);
    dfs(0);
}

int main(){
    solve();
    return 0;
}