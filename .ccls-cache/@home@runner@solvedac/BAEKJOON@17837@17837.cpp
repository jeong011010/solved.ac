//시작 14:15 끝 15:30
#include <deque>
#include <iostream>
using namespace std;

int ym[4] = {0, 0, -1, 1};
int xm[4] = {1, -1, 0, 0};

typedef struct pin {
  int y, x;
  int m;
  int num;
} pin;

int N, K;
int map[12][12];

deque<pin> dq[10];

void input() {
  cin >> N >> K;
  for (int i = 0; i < N; i++)
    for (int j = 0; j < N; j++)
      cin >> map[i][j];
  for (int i = 0; i < K; i++) {
    pin p;
    int y, x, m;
    cin >> y >> x >> m;
    p.y = y - 1, p.x = x - 1, p.m = m - 1, p.num = i;
    dq[i].push_back(p);
  }
}

void solve() {
  int turn = 0;
  while (turn++ <= 1000) {
    for (int i = 0; i < K; i++) {
      int ni,nj;
      for(int a=0;a<K;a++){
        for(int b=0;b<dq[a].size();b++){
          if(dq[a][b].num==i)
            ni=a, nj=b;
        }
      }
      //cout<<"dq["<<ni<<"]["<<nj<<"]="<<dq[ni][nj].num<<endl;
      pin p = dq[ni][nj];
      int ny = p.y + ym[p.m];
      int nx = p.x + xm[p.m];
      if (ny < 0 || ny >= N || nx < 0 || nx >= N ||
          (map[ny][nx] == 2)) { // 범위이탈 및 파란칸
        if (p.m == 1 || p.m == 3)
          dq[ni][nj].m--;
        else
          dq[ni][nj].m++;
      } // 방향바꾸기
      //cout << "방향:" << dq[i][0].m << endl;
      ny = p.y + ym[dq[ni][nj].m];
      nx = p.x + xm[dq[ni][nj].m];
      if (ny < 0 || ny >= N || nx < 0 || nx >= N || (map[ny][nx] == 2)) {
        //cout << "논외!" << endl;
        continue;
      }
      if (map[ny][nx] == 0) { // 하얀칸
        //cout << "흰탕!" << endl;
        int size = dq[ni].size();
        deque<pin> tmp;
        for (int k = nj; k < size; k++) { // 전부 이동
          dq[ni].back().y = ny;
          dq[ni].back().x = nx;
          tmp.push_back(dq[ni].back());
          dq[ni].pop_back();
        }
        for(int k = nj; k<size; k++){
          dq[i].push_back(tmp.back());
          tmp.pop_back();
        }
        for (int k = 0; k < K; k++) { // 그칸에 이미 누가 있다면
          if (dq[k][0].y == ny && dq[k][0].x == nx && k != i && dq[k].size()>0) {
            while (!dq[i].empty()) {
              dq[k].push_back(dq[i].front());
              dq[i].pop_front();
            }
          }
        }
      }

      if (map[ny][nx] == 1) { // 빨간칸
        //cout << "빨탕!" << endl;
        int t = dq[ni].back().num;
        deque<pin> tmp;
        if(t!=i)
          while (dq[ni].size()!=nj && !dq[ni].empty()) { // 전부이동
            dq[t].push_back(dq[ni].back());
            dq[ni].pop_back();
          }
        else {
          dq[t].push_back(dq[ni].back());
          dq[ni].pop_back();  
        }
        for (int k = 0; k < dq[t].size(); k++) { // 전부 이동
          dq[t][k].y = ny;
          dq[t][k].x = nx;
          //cout<<dq[t][k].y<<' '<<dq[t][k].x<<endl;
        }

        for (int k = 0; k < K; k++) { // 그칸에 이미 누가 있다면
          if (dq[k][0].y == ny && dq[k][0].x == nx && k != t && dq[k].size()>0) {
            while (!dq[t].empty()) {
              dq[k].push_back(dq[t].front());
              dq[t].pop_front();
            }
          }
        }
      }


      /*
      cout << "이동한번호:" << i << endl;
      for (int q = 0; q < K; q++)
        cout << dq[q].size() << ' ';
      cout << "입니다" << endl;
      for (int q = 0; q < N; q++) {
        for (int j = 0; j < N; j++) {
          bool s = true;
          for (int k = 0; k < K; k++) {
            if (dq[k][0].y == q && dq[k][0].x == j && dq[k].size() > 0) {
              cout << "(";
              for (int l = 0; l < dq[k].size(); l++) {
                cout << dq[k][l].num + 1 << ' ';
                s = false;
              }
              cout << ") ";
            }
          }
          if (s)
            cout << '0' << ' ';
        }
        cout << endl;
      }
      cout << endl;
      */
      for (int i = 0; i < K; i++) {
        if (dq[i].size() > 3) {
          cout << turn;
          return;
        }
      }
    }

  }
  cout << "-1";
  return;
}

int main() {
  input();
  solve();
  return 0;
}