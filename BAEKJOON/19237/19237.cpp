//시작 16:13 종료 17:20 시작 19:00 끝 19:49
#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int N, M, k;

int ym[4] = {-1, 1, 0, 0};
int xm[4] = {0, 0, -1, 1}; // 상 하 좌 우

typedef struct shark {
  int n;          // 상어 번호
  int m;          // 보고있는 방향
  int y,x;       // 상어 현 위치
  int move[4][4]; // 보고있는 방향에 따른 움직일 방향
} s;

typedef struct place {
  int smell;
  int n;
} m;

m map[20][20]; // 격자(냄새, 누구냄새)
vector<s> sharkArr;

bool cmp(const s &a, const s &b) {
  if (a.n < b.n)
    return true;
  else
    return false;
}

void input() {
  cin >> N >> M >> k;
  int tmp;
  s tmpShark;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      cin >> tmp;
      if (tmp != 0) {
        tmpShark = {tmp, 0, i, j};
        sharkArr.push_back(tmpShark);
        map[i][j] = {k, tmp}; // 상어있는칸
        //cout << i << ' ' << j << endl;
      } else
        map[i][j] = {0, tmp}; // 빈칸
    }
  }
  sort(sharkArr.begin(), sharkArr.end(), cmp); // 상어 번호순으로 정렬
  int moveTmp;
  for (int i = 0; i < M; i++) { // 각 상어의 첫 방향
    cin >> moveTmp;
    sharkArr[i].m = moveTmp - 1;
  }
  for (int i = 0; i < M; i++) {
    for (int j = 0; j < 4; j++) {
      for (int l = 0; l < 4; l++) {
        cin >> moveTmp;
        sharkArr[i].move[j][l] = moveTmp - 1; // 각 방향의 우선순위 방향
      }
    }
  }
}

void def() {
  int ans = 0;
  int sharkCnt = M;
  while (sharkCnt != 1 && ans <= 1000) { // 상어가 한마리 남거나 1000초가 넘어가면
    //cout<<"정답"<<sharkCnt<<" "<<ans<<endl;
    m tmpMap[20][20];
    for (int i = 0; i < N; i++) {
      for (int j = 0; j < N; j++) {
        tmpMap[i][j] = map[i][j]; // 임시 맵 초기화
        //cout << "(" << tmpMap[i][j].n << "," << tmpMap[i][j].smell << ") ";
      }
      //cout << endl;
    }
    //cout << endl;
    for (int i = 0; i < M; i++) { // 상어 전부
      if (sharkArr[i].n == 0)
        continue;            // 죽은 상어면 패스
      int y = sharkArr[i].y; // 현 상어 위치
      int x = sharkArr[i].x;
      int sm = sharkArr[i].m; // 현 상어 바라보는 방향
      bool noSmell = false;
      bool mySmell = false;
      int tmpy, tmpx, tmpm;
      //cout<<sharkArr[i].n<<endl;
      //cout<<y<<' '<<x<<endl;
      for (int j = 0; j < 4; j++) {
        if(!noSmell){
          int ny = y + ym[sharkArr[i].move[sm][j]];
          int nx = x + xm[sharkArr[i].move[sm][j]];
          if(ny>=N||nx>=N||ny<0||nx<0) continue; // 범위이탈
          //cout<<sm<<','<<j<<": ";
          //cout<<ym[sharkArr[i].move[sm][j]]<<' '<<xm[sharkArr[i].move[sm][j]]<<endl;
          //cout<<"ny:"<<ny<<" nx:"<<nx<<endl;
          if (map[ny][nx].smell == 0) {
            if(tmpMap[ny][nx].smell == 0){
              tmpMap[ny][nx] = {k + 1, sharkArr[i].n}; // 냄새생명, 상어번호
            }
            noSmell = true;
            sharkArr[i].y = ny, sharkArr[i].x = nx, sharkArr[i].m = sharkArr[i].move[sm][j];
          }
          if (map[ny][nx].n == sharkArr[i].n &&
              !mySmell) { // 우선순위에 가장 가까운 현재 상어의 냄새 방향
            tmpy = ny, tmpx = nx, tmpm = sharkArr[i].move[sm][j];
            mySmell = true;
            //cout<<"여기로가자\n";
          }
        }
      }
      if (!noSmell && mySmell) { // 전부 냄새로 꽉 차있으면
        //cout<<"은신이요~"<<endl;
        tmpMap[tmpy][tmpx] = {k + 1, sharkArr[i].n}; // 자신의 냄새로 이동
        sharkArr[i].y = tmpy, sharkArr[i].x = tmpx, sharkArr[i].m = tmpm;
      }
    }
    for (int i = 0; i < N; i++) {
      for (int j = 0; j < N; j++) {
        map[i][j] = tmpMap[i][j];
        bool sharkIsIn = false;
        for (int k = 0; k < M; k++) {
          if(sharkArr[k].n==0)
            continue;
          if (sharkArr[k].y == i && sharkArr[k].x == j) {
            if (!sharkIsIn) { // 첫 상어
              sharkIsIn = true;
            } else {             // 이후 상어
              //cout<<"죽은놈:"<<sharkArr[k].n<<endl;
              sharkArr[k].n = 0; // 사망
              sharkCnt--;
            }
          }
        }
        if (map[i][j].smell > 0)
          map[i][j].smell--; // 냄새 생명 차감
        if (map[i][j].smell == 0)
          map[i][j].n=0;
      }
    }
    ans++;
  }
  if (ans > 1000)
    cout << -1;
  else
    cout << ans;
}

int main() {
  input();
  def();
  return 0;
}