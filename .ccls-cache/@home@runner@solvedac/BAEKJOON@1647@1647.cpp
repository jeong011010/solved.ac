#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

int parent[100001];
vector<pair<int,pair<int,int>>> edges;
int N,M;

int find(int n){
  if(n==parent[n]) return n;
  return parent[n]=find(parent[n]);
}

void unite(int a,int b){
  a=find(a); b=find(b);
  if(a==b) return;
  parent[a]=b;
}

void input(){
  cin>>N>>M;
  int A,B,C;
  for(int i=0;i<M;i++){
    cin>>A>>B>>C;
    edges.push_back({C,{A,B}});
  }
  sort(edges.begin(),edges.end());

}

void solve(){
  for(int i=0;i<N;i++){
    parent[i]=i;
  }

  int sum=0;
  int max_cost=0;


  for(int i=0;i<M;i++){
    int cost=edges[i].first;
    int a=edges[i].second.first;
    int b=edges[i].second.second;

    if(find(a) == find(b)) continue;
    sum+=cost;
    max_cost=max(max_cost,cost);
    unite(a,b);
  }

  sum-=max_cost;
  cout<<sum<<endl;
}

int main(){
  input();
  solve();
  return 0;
}