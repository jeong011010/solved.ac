//시작 20:14 끝 20:42

#include<iostream>
#include<vector>
using namespace std;

int N;
vector<pair<int,int>> v; 
long long DP[1500001];

void input(){
  int T,P;
  cin>>N;
  for(int i=0;i<N;i++){
    cin>>T>>P;
    v.push_back({T,P});
  }
}

void solve(){
  DP[0]=0;
  for(int i=1;i<=N;i++){
    int T=v[i-1].first;
    int P=v[i-1].second;
    DP[i]=max(DP[i-1],DP[i]);
    if(i+T<=N+1){ // 퇴사 전에 상담이 가능하면
      DP[i+T]=max(DP[i]+P,DP[i+T]);
    }
    DP[i]=max(DP[i-1],DP[i]);
  }
  DP[N+1]=max(DP[N],DP[N+1]);

  cout<<DP[N+1];
}

int main(){
  input();
  solve();
  return 0;
}