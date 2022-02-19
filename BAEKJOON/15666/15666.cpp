#include<iostream>
#include<algorithm>
using namespace std;

int N,M, cnt=0;
int arr[9];
int ans[9];

void dfs(int c){
    if(c==M){
        for(int i=0;i<M;i++)
            cout<<ans[i]<<' ';
        cout<<'\n';
        return;
    }
    for(int i=0;i<cnt;i++){
        bool isBig = false;
        for(int j=0;j<c;j++){
            if(ans[j]>arr[i]) isBig = true;
        }
        if(!isBig){
            ans[c]=arr[i];
            dfs(c+1);
        }
    }
}

void solve(){
    cin>>N>>M;
    int tmp;
    for(int i=0;i<N;i++){
        bool check=true;
        cin>>tmp;
        for(int j=0;j<i;j++)
            if(tmp==arr[j])
                check=false;
        if(check) arr[cnt++]=tmp;
    }
    sort(arr,arr+cnt);
    dfs(0);
}

int main(){
    solve();
    return 0;
}