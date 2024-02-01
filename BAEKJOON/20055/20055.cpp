//시작 20:10 끝 21:05
#include<iostream>
#include<deque>
using namespace std;

int N,K;

deque<pair<int,bool>> dq;

void input(){
  cin>>N>>K;
  for(int i=0;i<N*2;i++){
    int A;
    cin>>A;
    if(A==0) K--;
    dq.push_back({A,0});
  }
}

void solve(){
  if(K<=0){ // 처음부터 내구도0인 벨트가 K만큼 있는경우
    cout<<1;
    return;
  }
  int k=0;
  int cnt=0;
  while(K>k){

    if(dq[N-1].second) // 내리는칸에 로봇 있으면
      dq[N-1].second=false; // 그즉시 하차

    // 1번
    int A = dq.back().first;
    bool isRbt = dq.back().second;
    dq.pop_back();
    dq.push_front({A,isRbt}); // 회전
    if(dq[N-1].second) // 내리는칸에 로봇 있으면
      dq[N-1].second=false; // 그즉시 하차

    // 2번
    for(int i=N-1;i>0;i--){
      if(dq[i].second && !dq[i+1].second && dq[i+1].first>0){ // 로봇이 있고, 앞칸에 로봇이 없고 앞칸 내구도가 1이상이라면
        dq[i].second=false;
        dq[i+1].second=true; // 로봇 한칸 이동
        dq[i+1].first--; // 이동한 칸 내구도 -1
        if(dq[i+1].first==0) k++;
      }  
    }

    if(dq[N-1].second) // 내리는칸에 로봇 있으면
      dq[N-1].second=false; // 그즉시 하차

    // 3번
    if(dq[0].first!=0 && !dq[0].second){
      dq[0].second=true; // 로봇올리기
      dq[0].first--; // 로봇 올린 칸 내구도 -1
      if(dq[0].first==0) k++;
    }
    /*
    for(int i=0;i<N;i++){
      cout<<dq[i].second<<' ';
    }
    cout<<endl;
    for(int i=0;i<N*2;i++){
      cout<<dq[i].first<<' ';
    }
    cout<<endl;
    cout<<endl;*/

    cnt++;
  }
  cout<<cnt;
}

int main(){
  input();
  solve();
  return 0;
}