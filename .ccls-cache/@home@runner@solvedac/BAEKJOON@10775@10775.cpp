// 시작 16:53 끝 17:22
#include<iostream>
using namespace std;

int G,P;
int parent[100001];

int find(int x){
  if(parent[x]==x) return x;
  parent[x]=find(parent[x]);
  return parent[x];
}

void uf(int a, int b){

  parent[find(a)]=find(b);

}

void input(){
  cin>>G>>P;
  int p;
  for(int i=0;i<=G;i++) parent[i]=i;
  for(int i=0;i<P;i++){
    cin>>p;

    if(find(p)!=0)
      uf(find(p), find(p)-1);
    else {
      cout<<i;
      return;
    }
  }
  cout<<G;
}

void solve(){

}

int main(){
  input();
  solve();
  return 0;
}