#include<iostream>
#include<vector>
#include<queue>
#include<tuple>

using namespace std;

int map[1001][1001], solveMap[1001][1001], n, m;
int ym[4] = {0, 1, 0, -1};
int xm[4] = {1, 0, -1, 0};
int sX,sY;


void input() {
  cin>>n>>m;
  for(int i=0;i<n;i++) {
    for(int j=0;j<m;j++) {
      cin>>map[i][j];
      if (map[i][j] == 2) {sY=i,sX=j;}
    }
  }
}

void print(){
  for(int i=0;i<n;i++) {
    for(int j=0;j<m;j++) {
      cout<<solveMap[i][j]<<" ";
    }
    cout<<"\n";
  }
}

void bfs(){
  bool copyMap[1001][1001];
  for(int i=0;i<n;i++) { // copyMap 초기화
    for(int j=0;j<m;j++) {
      if(map[i][j] == 1) {
        copyMap[i][j] = true;
      }
      else{
        copyMap[i][j] = false;
      }
    }
  }
  queue<tuple<int, int, int>> q;
  q.push(make_tuple(sY, sX, 0));
  copyMap[sY][sX] = 0;
  while(!q.empty()) {
    int y = get<0>(q.front());
    int x = get<1>(q.front());
    int cnt = get<2>(q.front());;
    q.pop();
    for(int i=0;i<4;i++) {
      int ny = y + ym[i];
      int nx = x + xm[i];

      if(ny<0 || nx<0 || ny>=n || nx>=m) continue;
      if(map[ny][nx] == 0 || copyMap[ny][nx] == false) continue;
      q.push(make_tuple(ny, nx, cnt+1));
      copyMap[ny][nx] = false;
      solveMap[ny][nx] = cnt+1;
    }
  }
  for(int i=0;i<n;i++) {
    for(int j=0;j<m;j++) {
      if(map[i][j] == 1 && copyMap[i][j]) {
        solveMap[i][j] = -1;
      }
    }
  }
}

void solve(){
  vector<pair<int, int>> route;
  bfs();
}


int main(){
  input();
  solve();
  print();
}

