// 시작 17:43  끝 17:53
#include<iostream>

using namespace std;

int N;
int map[101][101];
long long DP[101][101];

void input(){
  cin>>N;
  for(int i=0;i<N;i++)
    for(int j=0;j<N;j++)
      cin>>map[i][j];
  DP[0][0]=1;
}

void solve(){
  for(int i=0;i<N;i++){
    for(int j=0;j<N;j++){
      int jump = map[i][j];
      if(jump==0) break;
      if(i+jump<N) DP[i+jump][j] += DP[i][j];
      if(j+jump<N) DP[i][j+jump] += DP[i][j];
    }
  } 
  cout<<DP[N-1][N-1];
}

int main(){
  input();
  solve();
  return 0;
}