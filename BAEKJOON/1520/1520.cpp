//12:55 시작 14:03 끝
#include<iostream>
#include<vector>
#include<stack>
using namespace std;

int N,M;
int map[501][501];
int dp[501][501];
int my[4]={0,1,0,-1};
int mx[4]={1,0,-1,0}; //우하좌상

void input(){
  cin>>M>>N;
  for(int i=0;i<M;i++)
    for(int j=0;j<N;j++){
      cin>>map[i][j];
      dp[i][j]=-1;
    }
  dp[M-1][N-1]=1;
}

int dfs(int a, int b){

  int y=a;
  int x=b;

  dp[y][x]=0;
  for(int i=0;i<4;i++){
    int ny=y+my[i];
    int nx=x+mx[i];
    if(ny<0||nx<0||ny>=M||nx>=N) continue; //이탈시
    if(map[ny][nx]>=map[y][x]||dp[ny][nx]==0) continue; //내리막길 아니거나 경로가 없는곳이라면
    if(dp[ny][nx]==-1){ // 방문안했던곳이라면
      dp[y][x] += dfs(ny,nx);
    }
    else {dp[y][x] += dp[ny][nx];} //방문했거나 도착지점이라면
  }
  return dp[y][x];
}

int main(){
  input();
  cout<<dfs(0,0)<<endl;
  return 0;
}