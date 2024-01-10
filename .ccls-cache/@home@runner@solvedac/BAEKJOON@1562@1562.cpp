#include<iostream>
#define mod 1000000000
using namespace std;

int N;
long long dp[101][10][1<<10];

void input(){
  cin>>N;
}

void solve(){
  int full = (1<<10)-1;
  if(N<=9){
    cout<<0<<endl;
    return;
  }

  for(int i=1;i<=9;i++){ //1번째 길이 초기화. 0은 0.
    dp[1][i][1<<i] = 1;
  }

  for(int i=2;i<=N;i++){
    for(int j=0;j<=9;j++){
      for(int k=0;k<=full;k++){
        if(j==0){
          dp[i][j][k|1<<j] = (dp[i][j][k | 1 << j] + dp[i - 1][j + 1][k]) % mod;
        } //1에서만 올 수 있으므로. dp[길이+1][1][k] 더해주는거.
        else if(j==9){
          dp[i][j][k|1<<j] = (dp[i][j][k | 1 << j] + dp[i - 1][j - 1][k]) % mod;
        } //8에서만 올 수 있으므로. dp[길이+1][8][k] 더해주는거.
        else{
          dp[i][j][k|1<<j] = (dp[i][j][k | 1 << j] + dp[i-1][j-1][k] + dp[i - 1][j + 1][k]) % mod;
        } // 양옆 숫자에서 올 수 있으므로.
      }
    }
  }
  long long ans = 0;
  for(int i=0;i<=9;i++){
    ans=(ans+dp[N][i][full])%mod;
  }
  cout<<ans;

}

int main(){
  input();
  solve();
  return 0;
}