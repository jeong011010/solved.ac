// 시작 20:34 끝 20:50

#include<iostream>
#include<deque>
#include<queue>
#include<vector>
using namespace std;

int N,M;
vector<int> v;
deque<int> dq;

void input(){
  cin>>N>>M;
  for(int i=1;i<=N;i++) dq.push_back(i);
  for(int i=0;i<M;i++){
    int p;
    cin>>p;
    v.push_back(p);
  }
}

void solve(){
  int ans=0;
  for(int i=0;i<M;i++){
    while(dq.front()!=v[i]){
      int cnt=0;
      for(int j=0;j<dq.size();j++){
        if(dq[j]==v[i])
          cnt=j;
      }
      if(dq.size()-cnt>cnt){//앞쪽이라면
        dq.push_back(dq.front());
        dq.pop_front(); //2번 연산
      }
      else{
        dq.push_front(dq.back());
        dq.pop_back(); //3번 연산
      }
      ans++;
    }
    dq.pop_front(); //1번 연산
  }
  cout<<ans;
}

int main(){
  input();
  solve();
  return 0;
}

// 1 2 3 4 5 6 7
// 4를 뽑아야한다면
// 