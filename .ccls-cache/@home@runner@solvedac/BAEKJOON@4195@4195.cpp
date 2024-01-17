// 시작 14:30 끝 15:29

#include<iostream>
#include<map>
using namespace std;

int T;
int p[200002], v[200002];

map<string, int> name;

int find(int x){
  if(p[x]==x) {
    return x;
  }
  else return find(p[x]);
}

void uf(int a, int b){
  int tmpa=a, tmpb=b;
  a=find(a);
  b=find(b);
  if(a==b) return;
  if(a>b) {p[a]=b; v[b]+=v[a];}
  else {p[b]=a; v[a]+=v[b];}


}

void input(){
  int F, cnt=0;
  string a, b;
  cin>>F;
  for(int i=0;i<F*2;i++) {
    p[i]=i; v[i]=1;
  }// 부모노드 자기자신으로 초기화, 친구개수
  for(int i=0;i<F;i++){
    cin>>a>>b;
    if(name.find(a)==name.end()){
      name.insert({a,cnt++});
    }

    if(name.find(b)==name.end()){
      name.insert({b,cnt++});
    }

    uf(name[a],name[b]);

    cout<<v[find(name[a])]<<'\n';
  }

}

void solve(){
  cin>>T;
  for(int i=0;i<T;i++){
    name.clear(); // 친구관계 초기화
    input();

  }
}

int main(){

  ios::sync_with_stdio(false);
  cin.tie(NULL);
  solve();
  return 0;
}