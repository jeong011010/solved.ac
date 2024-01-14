// 시작 20:54 끝 21:11

#include<iostream>
#include<stack>
using namespace std;

int N;
int ans[1000001];
int tmp[1000001];
stack<int> s;

void input(){
  cin>>N;
  for(int i=0;i<N;i++){
    cin>>tmp[i];
  }
}

void solve(){
  for(int i=N-1;i>=0;i--){
    while(!s.empty() && s.top()<=tmp[i])
      s.pop();

    if(s.empty()) ans[i]=-1;
    else ans[i]=s.top();

    s.push(tmp[i]);
  }
  for(int i=0;i<N;i++)
    cout<<ans[i]<<' ';
}


int main(){
  input();
  solve();
  return 0;
}