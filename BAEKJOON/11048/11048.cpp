//15:24 시작 15:40 끝
#include<iostream>
#include<algorithm>
using namespace std;

int N,M;
int dp[1001][1001];

void input(){
  cin>>N>>M;
  for(int i=1;i<=N;i++){
    for(int j=1;j<=M;j++){
      cin>>dp[i][j]; // 사탕 개수
    }
  }
}

void solve(){
  for(int i=1;i<=N;i++){
    for(int j=1;j<=M;j++){
      int tmp=dp[i][j];
      int a=tmp+dp[i-1][j]; //상
      int b=tmp+dp[i][j-1]; //좌
      int c=tmp+dp[i-1][j-1]; //좌상      
      dp[i][j] = max({tmp,a,b,c});
    }
  }
  cout<<dp[N][M];
}

int main(){
  input();
  solve();
  return 0;
}