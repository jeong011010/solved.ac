//시작 19:49

#include<iostream>
#include<vector>
using namespace std;

int N,Q;
vector<long long> arr, tree;

long long init(int node, int start, int end){
  if(start == end)
    return tree[node] = arr[start];

  int mid = (start+end)/2;

  return tree[node]=init(node*2,start,mid)+init(node*2+1,mid+1,end);
}

long long sum(int node, int start, int end, int left, int right){
  if(left>end || right<start) return 0; // 범위를 벗어난경우 탈출
  if(left<=start&&right>=end) return tree[node]; // 딱맞는 범위라면 해당 노드 return

  int mid = (start+end)/2;
  return sum(node*2, start, mid, left, right)+sum(node*2+1, mid+1, end, left, right);
}

void update(int node, int start, int end, int idx, long long diff){
  if(idx>end || idx<start) return;
  tree[node] += diff;

  if(start != end){
    int mid = (start + end) / 2;
    update(node*2, start, mid, idx, diff);
    update(node*2+1, mid+1, end, idx, diff);
  }
}

void input(){
  cin>>N>>Q;
  long long tmp;
  for(int i=0;i<N;i++){
    cin>>tmp;
    arr.push_back(tmp);
  }
  tree.resize(N*4, 0);
  init(1,0,N-1);
}

void solve(){
  int x,y,a,b;
  for(int i=0;i<Q;i++){
    cin>>x>>y>>a>>b;

    long long diff = b - arr[a-1];
    arr[a-1]=b;

    if(x>y) swap(x,y);
    cout<<sum(1,0,N-1,x-1,y-1)<<'\n';

    update(1,0,N-1,a-1,diff);
  }
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  input();
  solve();
  return 0;
}