//시작 20:10 
#include <iostream>
#include <stack>
using namespace std;

int dice[10];
int arr[33] = {0,  2,  4,  6,  8,  10, 12, 14, 16, 18, 20, 22,
               24, 26, 28, 30, 32, 34, 36, 38, 13, 16, 19, 22,
               24, 28, 27, 26, 25, 30, 35, 40, 0}; // 0 시작 32 도착, 5->20 ,
                                                   // 10-> 23, 15-> 25, 19->31,
                                                   // 22->28, 24->28
int moving[33];  // 파란칸
int moving2[33]; // 중앙
int ans = 0;
bool check[33][33][33][33];

void input() {
  for (int i = 0; i < 10; i++)
    cin >> dice[i];
  moving[5] = 20;
  moving[10] = 23;
  moving[15] = 25;
  moving2[19] = 31;
  moving2[22] = 28;
  moving2[24] = 28;
}

int ta[4] = {0, 1, 2, 3};

void dfs(int cnt, int horse[4], int score) {
  if (cnt == 10 || (horse[0] == horse[1] && horse[1] == horse[2] &&
                    horse[2] == horse[3] && horse[0] == 32)) {
    ans = max(ans, score);
    //cout << "점수:" << score << endl <<"돌아가!\n\n";
    return;
  }
  /*
  if (check[horse[0]][horse[1]][horse[2]][horse[3]]) {
    //cout << "돌아가\n\n";
    return;
  }
  for (int i = 0; i < 4; i++)
    for (int j = 0; j < 4; j++)
      if(i!=j)
        for (int k = 0; k < 4; k++)
          if(i!=k&&j!=k)
            for (int l = 0; l < 4; l++)
              if(i!=l&&j!=l&&k!=l)
                check[horse[i]][horse[j]][horse[k]][horse[l]] = true;*/


  //cout << endl << cnt << endl;
  /*for (int i = 0; i < 4; i++)
    cout << arr[horse[i]] << ' ';
  cout << endl;*/

  for (int i = 0; i < 4; i++) {
    if (horse[i] == 32)
      continue; // 도착한 말이라면 패스
    int next = horse[i];
    int tmp = horse[i];
    int mCnt = dice[cnt];
    if (moving[next] > 0) { // 현제칸이 파란색이라면
      //cout << "파랑";
      next = moving[horse[i]];
      mCnt--; // 파란칸에서 한칸 움직임.
    }
    for (int j = 0; j < mCnt; j++) {
      if (moving2[next] > 0)  // 중앙 지름길이라면
        next = moving2[next]; // 이동
      else
        next++;
    }
    bool isin = false;
    for (int j = 0; j < 4; j++) {
      if (horse[j] == next) // 이동할 칸에 이미 다른 말이 있는지 체크
        isin = true;
    }
    if (isin) continue;
    if (next > 31) {
      horse[i] = 32;
      //cout << "도착!" << endl;
    }      // 움직일 칸이 도착지점 이상이라면
    else { // 도착지점이 아니면
      horse[i] = next; // 말 이동
    }
    /*
    for (int i = 0; i < 4; i++)
      cout << horse[i] << ' ';
    cout<<"가보자\n";*/
    dfs(cnt + 1, horse, score + arr[horse[i]]);
    horse[i] = tmp;
  }
  //cout<<"돌아가\n";
}

void solve() {
  int horse[4] = {0, 0, 0, 0};
  dfs(0, horse, 0);
  cout << ans;
}

int main() {
  input();
  solve();
  return 0;
}

// 1 2 3 4 1 2 3 4 1 2
// 1 2 2 2 1 2 1 1 2 1