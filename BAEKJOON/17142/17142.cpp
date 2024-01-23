// 시작 18:00 끝 20:03

#include<iostream>
#include<queue>
#include<vector>
using namespace std;

int N,M;
int map[51][51];
int ym[4] = {0,1,0,-1};
int xm[4] = {1,0,-1,0}; // 우 하 좌 상
int arr[10], arr_cnt=0;
int vp=0;
vector<pair<int,int>> virus;


void input(){
  cin>>N>>M;
  vp=N*N;
  for(int i=0;i<N;i++)
    for(int j=0;j<N;j++){
      cin>>map[i][j];
      if(map[i][j]==2)
        virus.push_back({i,j});
      if(map[i][j]==2||map[i][j]==1) vp--;
    }
}

int bfs(){ // 바이러스 퍼뜨리기
  int timer=0;
  bool check[51][51]={0,}; // 방문 여부
  for(int i=0;i<N;i++)
    for(int j=0;j<N;j++){
      if(map[i][j]==1) check[i][j]=1; // 벽 방문
    }
  queue<pair<pair<int,int>,int>> q; // y,x,cnt
  for(int i=0;i<M;i++){
    q.push({{virus[arr[i]].first,virus[arr[i]].second},0});
    check[virus[arr[i]].first][virus[arr[i]].second]=1; // 활성 바이러스 방문
  }
  int visit_empty=0;
  while(!q.empty()){
    if(visit_empty==vp){
      return timer;
    }

    int y = q.front().first.first;
    int x = q.front().first.second;
    int cnt = q.front().second;
    q.pop();
    for(int i=0;i<4;i++){
      int ny = y+ym[i];
      int nx = x+xm[i];
      if(ny<0 || nx<0 || ny>=N || nx>=N || map[ny][nx]==1 || check[ny][nx]) // 범위이탈, 벽, 방문한곳
        continue;
      // 빈공간, 비활성 바이러스에 닿으면

      q.push({{ny,nx},cnt+1});
      check[ny][nx]=1;
      if(map[ny][nx]==0)
        visit_empty++;
      timer = max(timer,cnt+1);
    }
  }

  return 1000000;
}

int ans=1000000;

void dfs(int n, int cnt){ // 바이러스 고르기
  if(cnt==M){
    ans=min(ans,bfs());
    return;
  }
  for(int i=n;i<virus.size();i++){
    arr[arr_cnt++]=i;
    dfs(i+1,cnt+1);
    arr_cnt--;
  }
}

void solve(){
  dfs(0,0);
  if(ans==1000000) cout<<-1;
  else  cout<<ans;
}

int main(){
  input();
  solve();
  return 0;
}