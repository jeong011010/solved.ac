//시작 20:12 종료 20:50 시작 22:24

#include <iostream>
using namespace std;

typedef struct shark {
  int s = 0; //속력
  int d = 0; //이동 방향
  int z = 0; //크기
} shark;

shark map[101][101];
int R, C, M;
int ym[4] = {-1, 1, 0, 0};
int xm[4] = {0, 0, 1, -1}; // 상 하 우 좌
int man = -1, sum = 0, count = 0;

void input() {
  cin >> R >> C >> M;
  int r, c, s, d, z;
  for (int i = 0; i < M; i++) {
    cin >> r >> c >> s >> d >> z;
    if(d<=2) s%=(R-1)*2;
    else s %= (C-1)*2;
    shark S = {s, d, z};
    map[r-1][c-1] = S;
  }
}

void def() {
  shark init = {0, 0, 0};
  shark tmp[101][101]={init,};
  man++;                        // 낚시왕 오른쪽 한 칸 이동
  for (int i = 0; i < R; i++) { // 상어잡기
    if (map[i][man].z != 0) {
      sum += map[i][man].z;
      map[i][man]=init;
      break;
    }
  } 
  /*
  for(int i=0;i<R;i++){
    for(int j=0;j<C;j++){
      cout<<map[i][j].z<<' ';
    }
    cout<<endl;
  }
  cout<<endl;
  */
  for (int i = 0; i < R; i++) { // 상어이동
    for (int j = 0; j < C; j++) {
      if (map[i][j].z != 0) {
        shark s = map[i][j];
        int y = i, x = j;
        if (s.d < 3) { // 상하
          for (int k = 0; k < s.s; k++) {
            if (y + ym[s.d-1] < 0 || y + ym[s.d-1] > R - 1)
              s.d = s.d % 2 + 1;
            y += ym[s.d-1];
          }
          if(tmp[y][x].z!=0){// 이동할 칸에 이미 상어가 이동해 있다면
            if(tmp[y][x].z<map[i][j].z) // 현재 움직인 상어가 더 크면
              tmp[y][x] = s; // 상어 이동
          }
          else tmp[y][x] = s;
        } else { // 좌우
          for (int k = 0; k < s.s; k++) {
            if (x + xm[s.d-1] < 0 || x + xm[s.d-1] > C - 1)
              s.d = (s.d-2) % 2 + 3;
            x += xm[s.d-1];
          }
          if(tmp[y][x].z!=0){// 이동할 칸에 이미 상어가 이동해 있다면
            if(tmp[y][x].z<map[i][j].z) // 현재 움직인 상어가 더 크면
              tmp[y][x] = s; // 상어 이동
          }
          else tmp[y][x] = s;
        }
      }
    }
  }
  for(int i=0;i<R;i++)
    for(int j=0;j<C;j++)
      map[i][j]=tmp[i][j];

  /*
  for(int i=0;i<R;i++){
    for(int j=0;j<C;j++){
      cout<<map[i][j].z<<' ';
    }
    cout<<endl;
  }
  cout<<endl;
  */
}

void solve() {
  for (int i = 0; i < C; i++) {
    def();
  }
  cout << sum;
}

int main() {
  input();
  solve();
  return 0;
}