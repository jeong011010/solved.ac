#include<iostream>
using namespace std;

int t,n,m,tmp;
int dp[30][30];

int combi(int n, int r){
     if(dp[n][r] != 0) return dp[n][r];
     if(n==r||r==0) return 1;
     else{
         dp[n][r] = combi(n-1,r-1) + combi(n-1,r);
         return dp[n][r];
     } 
}

void solve(){
    cin>>t;
    for(int tc=0;tc<t;tc++){
        for(int i=0;i<30;i++)
            for(int j=0;j<30;j++) dp[i][j]=0;
        cin>>n>>m;
        cout<<combi(m,n)<<'\n';
    }
}

int main(){
    solve();
    return 0;
}