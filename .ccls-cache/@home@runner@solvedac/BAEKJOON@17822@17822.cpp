//시작 19:10 끝 20:04
#include<iostream>
#include<deque>
using namespace std;

int N,M,T;
deque<int> dq[52];

void input(){
  cin>>N>>M>>T;
  for(int i=1;i<=N;i++){
    int tmp;
    for(int j=0;j<M;j++){
      cin>>tmp;
      dq[i].push_back(tmp);
    }
  }
}

void turn(int n, bool p, int k){
  for(int i=0;i<k;i++){
    int tmp;
    if(!p) { // 시계방향
      dq[n].push_front(dq[n].back());
      dq[n].pop_back();
    }
    else{ // 반시계방향
      dq[n].push_back(dq[n].front());
      dq[n].pop_front();
    }
  }
}

void erase(){
  bool check[52][51]={0,};
  for(int i=1;i<=N;i++){
    for(int j=0;j<M;j++){
      if(dq[i][j]!=0){ // 삭제된 수가 아니라면
        // 좌우에서 같은 수 찾기
        int a=j, b=j+1; 
        if(j==M-1)
          b=0;
        if(dq[i][a]==dq[i][b])
            check[i][a]=check[i][b]=true;

        // 위아래에서 같은 수 찾기
        a=i, b=i+1;
        if(dq[a][j]==dq[b][j])
          check[a][j]=check[b][j]=true;
      }
    }
  }
  float sum=0, cnt=0;
  bool isCheck=false;
  for(int i=1;i<=N;i++){
    for(int j=0;j<M;j++){
      sum+=dq[i][j];
      if(dq[i][j]>0)
        cnt++;
      if(check[i][j]){
        isCheck=true;
        dq[i][j]=0; // 삭제!
      }
    }
  }
  float ave = sum/cnt;
  //cout<<ave<<' '<<sum<<' '<<cnt<<endl;
  if(!isCheck){ // 아무것도 삭제 안됐어?
    for(int i=1;i<=N;i++){
      for(int j=0;j<M;j++){
        if(dq[i][j]!=0){
          if(dq[i][j]>ave) dq[i][j]--;
          else if(dq[i][j]<ave) dq[i][j]++;
        }
      }
    }
  }
}

void solve(){
  int x,d,k;
  for(int i=0;i<T;i++){
    cin>>x>>d>>k;
    for(int j=x;j<=N;j+=x){
      turn(j,d,k); 
    }
    erase();
  }
  int sum=0;
  for(int i=1;i<=N;i++){
    for(int j=0;j<M;j++){
      sum+=dq[i][j];
    }
  }
  cout<<sum;
}

int main(){
  input();
  solve();
  return 0;
}