//시작 15:50 종료 17:00 시작 19:50 끝 20:20

#include<iostream>
#include<stack>
#include<vector>
#include<queue>
using namespace std;

int N;
int arr[22][22];
int happy[22][22];
int my[4] = {-1,0,0,1}; // 상 좌 우 하
int mx[4] = {0,-1,1,0};
vector<pair<int,pair<pair<int,int>,pair<int,int>>>> v;

void check(int n){
  int a = v[n].second.first.first;
  int b = v[n].second.first.second;
  int c = v[n].second.second.first;
  int d = v[n].second.second.second;
  int love[4]={a,b,c,d};

  int px=2,py=2;
  int h=0;
  int check[22][22]={0,};
  bool isLove = 0;
  for(int i=1;i<=N;i++){ // 선호학생이 있는경우 조사
    for(int j=1;j<=N;j++){
      for(int k=0;k<4;k++){
        if(arr[i][j]==love[k]){
          for(int l=0;l<4;l++){
            if(i+my[l]<1||j+mx[l]<1||i+my[l]>N||j+mx[l]>N||arr[i+my[l]][j+mx[l]]!=0) // 범위벗어나거나 비어있지 않은 칸은 패스
              continue;
            check[i+my[l]][j+mx[l]]++;
            isLove=true;
          }
        }
      }
    }
  }
  int hv=0;
  for(int i=1;i<=N;i++){
    for(int j=1;j<=N;j++){
      hv=max(hv,check[i][j]);
    }
  }

  for(int i=1;i<=N;i++){ // 빈공간 조사
    for(int j=1;j<=N;j++){
      if(check[i][j]==hv || !isLove){
        for(int l=0;l<4;l++){
          if(i+my[l]<1||j+mx[l]<1||i+my[l]>N||j+mx[l]>N||arr[i][j]!=0)
            continue;
          if(arr[i+my[l]][j+mx[l]]==0){
            check[i][j]++;
          }
        }
      }
    }
  }
  int m=-1;
  for(int i=1;i<=N;i++){
    for(int j=1;j<=N;j++){
      //cout<<check[i][j]<<' ';
      if(m<check[i][j]&&arr[i][j]==0){
        m=check[i][j];
        py=i, px=j;
      }
    }
    //cout<<endl;
  }
  //cout<<endl;
  arr[py][px]=v[n].first;
  /*for(int i=1;i<=N;i++){
    for(int j=1;j<=N;j++){
      cout<<arr[i][j]<<' ';
    }
    cout<<endl;
  }
  cout<<endl<<py<<' '<<px<<endl<<endl;*/
}

void happySum(){

  for(int n=0;n<N*N;n++){
    int a = v[n].second.first.first;
    int b = v[n].second.first.second;
    int c = v[n].second.second.first;
    int d = v[n].second.second.second;
    int love[4]={a,b,c,d};
    for(int i=1;i<=N;i++){
      for(int j=1;j<=N;j++){
        if(arr[i][j]==v[n].first){
          for(int k=0;k<4;k++){
            for(int l=0;l<4;l++){
              if(arr[i+my[l]][j+mx[l]]==love[k])
                happy[i][j]++;
            }
          }
        }
      }
    }
  }
}

void input(){
  cin>>N;
  for(int i=0;i<N*N;i++){
    int n,a,b,c,d;
    cin>>n>>a>>b>>c>>d;
    v.push_back({n,{{a,b},{c,d}}});
  }
}

void solve(){
  for(int i=0;i<N*N;i++){
    check(i);
  }
  happySum();
  int ans=0;
  for(int i=1;i<=N;i++){
    for(int j=1;j<=N;j++){
      int tmp=happy[i][j];
      if(tmp==0) ans+=0;
      else if(tmp==1) ans+=1;
      else if(tmp==2) ans+=10;
      else if(tmp==3) ans+=100;
      else if(tmp==4) ans+=1000;
    }
  }
  cout<<ans;
}

int main(){
  input();
  solve();
  return 0;
}