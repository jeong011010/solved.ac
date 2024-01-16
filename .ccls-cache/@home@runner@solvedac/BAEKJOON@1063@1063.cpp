// 시작 19:08 끝 19:39

#include <iostream>
#include <string>
using namespace std;

int Ky, Kx, Sy, Sx, N;

void input() {
  string K, S;
  cin >> K >> S >> N;
  Ky = K[1] - '0' - 1, Kx = K[0] - 'A';
  Sy = S[1] - '0' - 1, Sx = S[0] - 'A';
}

void Move(int i, int j) {
  if (Ky + i < 0 || Ky + i > 7 || Kx + j < 0 || Kx + j > 7)
    return;
  if (Ky + i == Sy && Kx + j == Sx) {
    if (Sy + i < 0 || Sy + i > 7 || Sx + j < 0 || Sx + j > 7)
      return;
    Sy += i, Sx += j;
  }
  Ky += i;
  Kx += j;
}

void solve() {
  string cmd;
  for (int i = 0; i < N; i++) {
    cin >> cmd;
    if (cmd == "R")
      Move(0, 1);
    else if (cmd == "L")
      Move(0, -1);
    else if (cmd == "B")
      Move(-1, 0);
    else if (cmd == "T")
      Move(1, 0);
    else if (cmd == "RT")
      Move(1, 1);
    else if (cmd == "LT")
      Move(1, -1);
    else if (cmd == "RB")
      Move(-1, 1);
    else if (cmd == "LB")
      Move(-1, -1);
  }
  cout << char(Kx + 'A') << Ky + 1 << endl;
  cout << char(Sx + 'A') << Sy + 1 << endl;
}

int main() {
  input();
  solve();
  return 0;
}