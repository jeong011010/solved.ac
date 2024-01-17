//시작 13:53 끝 14:22

#include<iostream>
#include<vector>

using namespace std;

int N,M;
int parent[201];
vector<int> plan;

int find(int x){
  if(parent[x]==x)return x;
  return parent[x] = find(parent[x]);
}

void uf(int a, int b){
  a=find(a);
  b=find(b);
  if(a<b) parent[b] = a;
  else parent[a] = b;
}

void inputSolve(){
  cin>>N>>M;

  for(int i=1;i<=N;i++)
    parent[i]=i; // 부모 노드 자기자신

  bool cango;
  for(int i=1;i<=N;i++)
    for(int j=1;j<=N;j++){
      cin>>cango;
      if(cango)
        uf(i,j); // 부모노드 찾아주기
    }

  int tmp, start;
  cango = true;
  for(int i=0;i<M;i++){
    cin>>tmp;
    if(i==0) start = find(tmp);
    else{
      if(find(tmp)!=start) cango=false;
    }
  }
  if(cango) cout<<"YES";
  else cout<<"NO";
}

int main(){
  inputSolve();
}