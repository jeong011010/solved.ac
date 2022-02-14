#include<iostream>
using namespace std;

int arr[100001][2];
int tc, n;

void input(){
    cin>>n;
    for(int i=0;i<2;i++)
        for(int j=1;j<=n;j++)
            cin>>arr[j][i];
}

void f(){
    int DP[100001][2];
    DP[1][0]=arr[1][0];
    DP[1][1]=arr[1][1];
    for(int i=2;i<=n;i++){
        for(int j=0;j<2;j++){
            DP[i][j]=arr[i][j];
            if(DP[i-1][j==0?1:0]>DP[i-2][j==0?1:0])
                DP[i][j]+=DP[i-1][j==0?1:0];
            else
                DP[i][j]+=DP[i-2][j==0?1:0];
            //cout<<i<<' '<<j<<' '<<DP[i][j]<<'\n';
        }
    }
    cout<<max(DP[n][0],DP[n][1])<<'\n';
}

void solve(){
    cin>>tc;
    for(int i=0;i<tc;i++){
        input();
        f();
    }
}

int main(){
    solve();
    return 0;
}