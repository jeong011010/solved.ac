// 시작 17:59 끝 18:17
#include<iostream>
#include<vector>
using namespace std;

int N, M;
bool dp[2001][2001];
int arr[2001];

void input(){
  cin>>N;
  for(int i=0;i<N;i++){
    dp[i][i]=true;
    cin>>arr[i];
  }

}

void solve(){
  for(int i=0;i<N-1;i++){
    if(arr[i]==arr[i+1]) dp[i][i+1]=true;
  }

  for(int i=2;i<N;i++){
    for(int j=0;j<i-1;j++){
      if(arr[j]==arr[i]&&dp[j+1][i-1]){
        dp[j][i]=true;
      }
    }
  }
/*
  for(int i=0;i<N;i++){
    for(int j=0;j<N;j++){
      cout<<"i:"<<i<<" j:"<<j<<" dp[i][j]:"<<dp[i][j]<<endl;
    }
  }
  */
  cin>>M;
  for(int i=0;i<M;i++){
    int S,E;
    cin>>S>>E;
    cout<<dp[S-1][E-1]<<"\n";
  }
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  input();
  solve();
  return 0;
}