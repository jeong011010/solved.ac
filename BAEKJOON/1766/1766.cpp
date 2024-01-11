#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int N, M;
priority_queue<int, vector<int>, greater<int>> pq;
int isDone[32001] = {0,};
vector<int> better[32001];

void input(){
  cin>>N>>M;
  int a,b;
  for(int i=0;i<M;i++){
    cin>>a>>b;
    isDone[b]++;
    better[a].push_back(b);
  }
}

void solve(){

  for(int i=1;i<=N; i++){
    if(isDone[i] == 0)
      pq.push(i);
  }

  while(!pq.empty()){
    int tmp = pq.top();
    pq.pop();

    cout<<tmp<<" ";

    for(int i=0;i<better[tmp].size();i++){
      int next = better[tmp][i];
      isDone[next]--;
      if(isDone[next] == 0)
        pq.push(next);
    }
  }
}

int main(){
  input();
  solve();
  return 0;
}