//시작 18:14  끝 19:13

#include<iostream>
#include<string>
#include<stack>
using namespace std;

string S;
int N, M;
stack<char> Left, Right;

void input(){
  cin>>S;
  for(int i=0;i<S.length();i++)
    Left.push(S[i]);
  cin>>M;
}

void L(){
  if(!Left.empty()) { // 좌측 문자을 우측 문자열에 추가
    Right.push(Left.top()); 
    Left.pop();
  }
}

void D(){
  if(!Right.empty()) { // 우측 문자을 좌측 문자열에 추가
    Left.push(Right.top()); 
    Right.pop();
  }
}

void B(){
  if(!Left.empty())
    Left.pop();
}

void P(char s){
  Left.push(s);
}

void solve(){

  for(int i=0;i<M;i++){
    char cmd, c;
    cin>>cmd;
    switch(cmd){
      case 'L':
        L();
        break;
      case 'D':
        D();
        break;
      case 'B':
        B();
        break;
      case 'P':
        cin>>c;
        P(c);
        break;
    }
  }
  int ls=Left.size();
  for(int i=0;i<ls;i++){
    Right.push(Left.top());
    Left.pop();
  }
  int rs=Right.size();
  for(int i=0;i<rs;i++){
    cout<<Right.top();
    Right.pop();
  }
}

int main(){
  input();
  solve();
  return 0;
}