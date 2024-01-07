#include<iostream>
#include<queue>
using namespace std;

int N,M, a,b;
int my[4]= {1,-1,0,0};
int mx[4]= {0,0,-1,1};
int map[601][601];
bool visited[601][601]={0,};
int ans=0;

void input(){
  cin>>N>>M;
  for(int i=0;i<N;i++){
    for(int j=0;j<M;j++){
      char tmp;
      cin>>tmp;
      if(tmp=='O') map[i][j]=0; //빈칸
      else if(tmp=='X') {map[i][j]=1; visited[i][j]=true;} //벽
      else if(tmp=='I') {map[i][j]=2;a=i,b=j;} //도연
      else map[i][j]=3; //사람
    }
  } 
}

void solve(){
  queue<pair<int,int>> q;
  q.push({a,b});
  visited[a][b]=true;
  while(!q.empty()){
    int y=q.front().first;
    int x=q.front().second;
    q.pop();
    for(int i=0;i<4;i++){
      int ny=y+my[i];
      int nx=x+mx[i];
      if(ny<0||nx<0||ny>=N||nx>=M||visited[ny][nx]) continue;
      if(map[ny][nx]==3) ans++;
      if(map[ny][nx]==0||map[ny][nx]==3){
        q.push({ny,nx});
        visited[ny][nx]=true;
      }
    }
  }
  if(ans==0) cout<<"TT";
  else cout<<ans;
}


int main(){
  input();
  solve();
  return 0;
}