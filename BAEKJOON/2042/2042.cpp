// 시작 15:50 끝 16:35

#include<iostream>
#include<vector>
typedef long long ll;
using namespace std;

int N,M,K;
ll arr[1000001];
vector<ll> tree;

void input(){
  cin>>N>>M>>K;
  for(int i=0;i<N;i++)
    cin>>arr[i];
  tree.resize(N*4,0);
}

ll init(int n, int s, int e){
  if(s==e) return tree[n]=arr[s]; // 자기자신일경우
  int m=(s+e)/2;
  return tree[n]=init(n*2,s,m)+init(n*2+1,m+1,e);
}

ll sum(int n, int s, int e, int l, int r){
  if(l>e||r<s) return 0; // 범위 이탈
  if(l<=s&&r>=e) return tree[n]; // 범위 내

  int m=(s+e)/2;
  return sum(n*2,s,m,l,r)+sum(n*2+1,m+1,e,l,r);
}

void update(int n, int s, int e, int idx, ll diff){
  if(idx<s||e<idx) return;
  tree[n]+=diff;
  if(s!=e){
    int m=(s+e)/2;
    update(n*2,s,m,idx,diff);
    update(n*2+1,m+1,e,idx,diff);
  }
}


void solve(){
  init(1,0,N-1); //세그먼트 트리 제작
  ll a,b,c;
  for(int i=0;i<M+K;i++){
    cin>>a>>b>>c;
    if(a==1){ // update
      ll diff = c-arr[b-1];
      arr[b-1]=c;
      update(1,0,N-1,b-1,diff);
    }
    else{ // cout sum
      cout<<sum(1,0,N-1,b-1,c-1)<<'\n';
    }
  }
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  input();
  solve();
  return 0;
}