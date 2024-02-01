//시작 17:40 끝 19:49
#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int N, M, G; // 칸, 승객, 연료
int map[20][20];
int goalmap[20][20];
int ty, tx; // 현재 위치

int ym[4] = {0, 1, 0, -1};
int xm[4] = {1, 0, -1, 0};

vector<pair<int, int>> s, g;

void input() {
  cin >> N >> M >> G;
  int tmp;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      cin >> tmp;
      if (tmp == 1)
        map[i][j] = -1; // 벽 -1
    }
  }

  cin >> ty >> tx;
  ty--; tx--;
  int sy, sx, gy, gx;
  for (int i = 0; i < M; i++) {
    cin >> sy >> sx >> gy >> gx;
    s.push_back({sy-1, sx-1});
    g.push_back({gy-1, gx-1});
    map[sy-1][sx-1] = i + 1;
  }
  sort(s.begin(), s.end()); // 승객
/*
  for(int i=0;i<N;i++){
    for(int j=0;j<N;j++){
      if(i==ty&&j==tx)
        cout<<"T\t";
      else
        cout<<map[i][j]<<'\t';
    }
    cout<<endl;
  }
  cout<<endl;*/
}

int find(int a, int b, int c, int gas) { // y,x, c:0 승객 c:1이상 골인번호 gas:남은기름
  if(c==0) // 출발했는데 거기에 바로 손님이 있을경우
    if(map[a][b]>0){
      return 0;
    }
  map[a][b]=0;

  bool check[20][20];
  for(int i=0;i<N;i++)
    for(int j=0;j<N;j++){
      if(map[i][j]==-1) check[i][j]=1; // 벽은 방문했다치고
      else check[i][j]=0; // 나머지는 방문 안한걸로
    }

  check[a][b]=1;
  int findcnt=1000; // 같은 거리 승객이 여러명일 경우를 대비
  int ansy=21, ansx=21;
  queue<pair<pair<int, int>, int>> q; // y,x,cnt
  q.push({{a, b}, 0});
  while (!q.empty()) {
    int y = q.front().first.first;
    int x = q.front().first.second;
    int cnt = q.front().second;
    q.pop();
    if(findcnt>=cnt && cnt<gas){
      for (int i = 0; i < 4; i++) {
        int ny = y + ym[i];
        int nx = x + xm[i];
        if (map[ny][nx] == -1 || ny < 0 || nx < 0 || ny >= N || nx >= N || check[ny][nx]) // 범위이탈
          continue;
        //cout<<ny<<' '<<nx<<":"<<map[ny][nx]<<endl;

        if(g[c-1].first==ny && g[c-1].second==nx){ // 알맞는 골인지점을 찾았다면
          ty=ny, tx=nx;
          /*
          cout<<ty<<','<<tx<<endl;
          for(int i=0;i<N;i++){
            for(int j=0;j<N;j++){
              if(i==ty&&j==tx)
                cout<<"T\t";
              else
                cout<<map[i][j]<<'\t';
            }
            cout<<endl;
          }
          cout<<endl;*/

          return cnt+1; // 거리 return
        }

        if(map[ny][nx]==0){ // 빈공간이라면

          q.push({{ny,nx},cnt+1});
          check[ny][nx]=1;
        }
        else if(map[ny][nx]>0){ // 승객이라면
          for(int j=0;j<M;j++){
            if(c==0 && s[j].first==ny && s[j].second==nx){
              //cout<<cnt<<endl;
              findcnt=min(findcnt,cnt);
              if(ansy>=ny){ // 행번호가 작은 승객
                if(ansy==ny){ // 행번호가 같다면
                  if(ansx>nx) // 열번호가 작은 승객
                    ansy=ny, ansx=nx;
                } 
                else // 행번호가 작기만 하다면 요걸로
                  ansy=ny, ansx=nx;
              }
              //cout<<"("<<ansy<<","<<ansx<<")"<<endl;
            }

            else{ // 골인지점을 찾는중 승객을 만나셨나요
              q.push({{ny,nx},cnt+1}); // 넘어가세요
              check[ny][nx]=1;
            }
          }
        }
      }    
    }
  }
  /*
  cout<<ansy<<','<<ansx<<endl;
  for(int i=0;i<N;i++){
    for(int j=0;j<N;j++){
      if(i==ansy&&j==ansx)
        cout<<"T\t";
      else
        cout<<map[i][j]<<'\t';
    }
    cout<<endl;
  }
  cout<<endl;*/

  if(findcnt==1000) return -1;
  ty=ansy, tx=ansx;
  return findcnt+1;
}

void solve() {

  for(int i=0;i<M;i++){
    //cout<<"승객찾기\n";
    //cout<<"남은 연료:"<<G<<endl;
    int gas = find(ty, tx, 0, G);
    if(gas==-1){
      cout<<"-1";
      return;
    }
    G-=gas; // 손님찾는만큼 연료 소비
    //cout<<map[ty][tx]<<"번 골인지점 찾기\n";
    //cout<<"남은 연료:"<<G<<endl;
    gas = find(ty, tx, map[ty][tx], G);
    if(gas==-1){
      cout<<"-1";
      return;
    }
    G+=gas; // 골인지점 찾은만큼 연료충전
  }
  cout<<G;
  return;
}

int main() {
  input();
  solve();
  return 0;
}