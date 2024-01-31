//시작 14:32 끝 15:45
#include<iostream>
#include<stack>
#include<vector>
using namespace std;

typedef struct fish{
  int n; // num
  int m; // move
}f;

int ym[8]={-1,-1,0,1,1,1,0,-1};
int xm[8]={0,-1,-1,-1,0,1,1,1}; // 상 좌상 좌 좌하 하 우하 우 우상

f map[4][4];

int ans=0;

void input(){
  f tmp;
  for(int i=0;i<4;i++){
    for(int j=0;j<4;j++){
      cin>>tmp.n>>tmp.m;
      tmp.m--;
      map[i][j]=tmp;
    }
  }
}

void dfs(int y, int x, int cnt, f arr[4][4], int sum){
  f tmpArr[4][4];
  for(int i=0;i<4;i++){
    for(int j=0;j<4;j++){
      tmpArr[i][j]=arr[i][j];
    }
  }
  //cout<<cnt<<endl;

  int m = tmpArr[y][x].m;
  sum += tmpArr[y][x].n; // 잡아먹은만큼 더해주기
  tmpArr[y][x].n=0, tmpArr[y][x].m=0; // 잡아먹히면 초기화



  for(int k=1;k<=16;k++){ // 물고기 이동
    bool isMove=false;
    if(!isMove)
      for(int i=0;i<4;i++){
        for(int j=0;j<4;j++){
          if(tmpArr[i][j].n==k && !isMove){ // 물고기가 살아있으면
            for(int l=0;l<8;l++){
              int ny=i+ym[(tmpArr[i][j].m+l)%8];
              int nx=j+xm[(tmpArr[i][j].m+l)%8];
              //cout<<"("<<ny<<","<<nx<<") "<<endl;
              if((ny==y&&nx==x)||nx<0||ny<0||ny>3||nx>3)//상어가 있거나 맵 밖이라면
                continue;
              // 물고기가 갈 수 있으면
              tmpArr[i][j].m=(tmpArr[i][j].m+l)%8; // 방향 변경
              swap(tmpArr[i][j],tmpArr[ny][nx]); // 서로 자리이동
              isMove=true;
              break;

            }
          }
        }
      }
  }
  /*for(int i=0;i<4;i++){
    for(int j=0;j<4;j++){
      cout<<"("<<tmpArr[i][j].n<<','<<tmpArr[i][j].m<<") ";
    }
    cout<<endl;
  }
  cout<<endl;*/
  int tmpy=y+ym[m];
  int tmpx=x+xm[m];
  //cout<<"이건데;"<<ym[m]<<' '<<xm[m]<<endl;
  while(tmpy<4&&tmpx<4&&tmpy>=0&&tmpx>=0){ // 상어이동
    if(tmpArr[tmpy][tmpx].n!=0){ // 비어있지 않으면
      //cout<<tmpy<<' '<<tmpx<<"로 이동할게요~\n";
      dfs(tmpy,tmpx,cnt+1,tmpArr, sum);
    }
    tmpy+=ym[m];
    tmpx+=xm[m];
  }
  ans=max(ans,sum);
  //cout<<"돌아갑니다~"<<endl;

  return;
}

void solve(){
  f tmpArr[4][4];
  for(int i=0;i<4;i++)
    for(int j=0;j<4;j++)
      tmpArr[i][j]=map[i][j]; // 임시 맵 초기화
  dfs(0,0,0, tmpArr, 0);
  cout<<ans;
}

int main(){
  input();
  solve();
  return 0;
}