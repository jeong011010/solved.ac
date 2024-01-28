//시작 15:45 끝 17:25
#include<iostream>
#include<queue>
using namespace std;

int R,C,N;
bool arr[100][100];
bool check[100][100];
int ym[4]={0,1,0,-1};
int xm[4]={1,0,-1,0};//우 하 좌 상

void input(){
  cin>>R>>C;
  char tmp;
  for(int i=0;i<R;i++){
    for(int j=0;j<C;j++){
      cin>>tmp;
      if(tmp=='.') arr[i][j]=0;
      else arr[i][j]=1;
    }
  }
  cin>>N;
}

vector<pair<int,int>> dfs(int a, int b){
  bool isBottom = false;
  vector<pair<int,int>> cst;
  vector<pair<int,int>> tmp; // 빈거
  queue<pair<int,int>> q;
  q.push({a,b});
  cst.push_back({a,b});
  check[a][b]=true; // 방문
  while(!q.empty()){
    int y=q.front().first;
    int x=q.front().second;
    if(y==R-1) {
      isBottom=true;
    }
    //cout<<y<<' '<<x<<endl;
    q.pop();
    for(int i=0;i<4;i++){
      int ny=y+ym[i];
      int nx=x+xm[i];
      if(ny<0||nx<0||ny>=R||nx>=C||check[ny][nx]||!arr[ny][nx]) // 범위 이탈, 방문했을시, 빈공간일시
        continue;
      q.push({ny,nx});
      cst.push_back({ny,nx});
      check[ny][nx]=true; // 방문
    }
  }
  if(!isBottom) {return cst;}
  else {return tmp;}
}

void fall(int a, int b, vector<pair<int,int>> cst){
  for(int i=0;i<cst.size();i++){
    int y=cst[i].first;
    int x=cst[i].second;
    arr[y][x]=0; // 떨어질 크리스탈 원래 자리 빈공간으로 초기화
  }
  bool isMerge = false;
  while(!isMerge){
    for(int i=0;i<cst.size();i++){
      cst[i].first++; // 한칸 떨어지기
      int y=cst[i].first;
      int x=cst[i].second;
      if(arr[y+1][x] || y+1==R){ // 크리스탈 어느 한 부분이라도 밑에 바닥이나 새로운 클러스터가 있다면
        isMerge=true;
      }
    }
  }
  for(int i=0;i<cst.size();i++){
    arr[cst[i].first][cst[i].second]=1; // 크리스탈 병합
  }
}

void stick(int h, int t){
  int p=-1;
  if(t==0) // 왼쪽
    for(int i=0;i<C;i++){
      if(arr[h][i]){
        p=i;
        arr[h][p]=0; // 크리스탈 파괴
        break;
      }
    }
  else // 오른쪽
    for(int i=C-1;i>=0;i--){
      if(arr[h][i]){
        p=i;
        arr[h][p]=0; // 크리스탈 파괴
        break;
      }
    }

  if(p==-1) return; // 맞은 크리스탈 없음

  for(int i=0;i<R;i++)
    for(int j=0;j<C;j++)
      check[i][j]=0; // 방문배열 초기화
  int x,y;

  for(int i=0;i<4;i++){
    vector<pair<int,int>> cst;
    int ny = h+ym[i];
    int nx = p+xm[i];
    if(ny<0||nx<0||ny>=R||nx>=C||check[ny][nx])
      continue;
    if(arr[ny][nx]){
      cst = dfs(ny,nx);
      if(cst.size()>0){//공중에 떠있는 크리스탈 발견!
        fall(ny,nx,cst); // 떨어뜨리기
      }
    }

  }
}

void solve(){
  int h;
  for(int i=0;i<N;i++){
    cin>>h;
    stick(R-h,i%2);

  }
  for(int i=0;i<R;i++){
    for(int j=0;j<C;j++){
      if(arr[i][j]) cout<<'x';
      else cout<<'.';
    }
    cout<<'\n';
  }
}

int main(){
  input();
  solve();
  return 0;
}