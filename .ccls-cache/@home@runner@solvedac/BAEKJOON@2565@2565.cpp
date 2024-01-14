//14:35 시작 15:06 끝
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int N;
vector<pair<int,int>> Line;
int DP[501];

void input(){
  cin>>N;
  int A,B;
  for(int i=0;i<N;i++){
    cin>>A>>B;
    Line.push_back({A,B});
  }
  sort(Line.begin(),Line.end());
}

void solve(){
  int tmp=0;
  for(int i=0;i<N;i++){
    DP[i]=1;
    for(int j=0;j<i;j++){
      if(Line[j].second<Line[i].second){
        DP[i]=max(DP[i],DP[j]+1);
      }
    }
    tmp=max(tmp,DP[i]);
  }
  cout<<N-tmp;
}

int main(){
  input();
  solve();
  return 0;
}