//시작 19:10 끝 19:59

#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int arr[101][101];
int r,c,k,row=3,col=3;

void input(){
  cin>>r>>c>>k;
  for(int i=0;i<3;i++){
    for(int j=0;j<3;j++){
      cin>>arr[i][j];
    }
  }
}

void def(bool n){
  int a=0;
  if(n){
    //cout<<"R~\n";
    for(int i=0;i<row;i++){
      int tmp[101]={0,};
      vector<pair<int,int>> check;
      for(int j=0;j<col;j++){
        tmp[arr[i][j]]++;
      }
      for(int j=1;j<101;j++){
        if(tmp[j]>0){
          check.push_back({tmp[j],j});
        }

      }
      sort(check.begin(), check.end());
      int cs = check.size();
      //for(int j=0;j<cs;j++) cout<<check[j].second<<' '<<check[j].first<<endl;
      for(int j=0;j<101;j++) arr[i][j]=0;
      for(int j=0;j<cs;j++){
        arr[i][j*2]=check[j].second;
        arr[i][j*2+1]=check[j].first;
      }
      //cout<<endl<<cs<<endl;
      a = max(a, cs*2);
    }
    col=a;
  }
  else {
    //cout<<"C~\n";
    for(int i=0;i<col;i++){
      int tmp[101]={0,};
      vector<pair<int,int>> check;
      for(int j=0;j<row;j++){
        tmp[arr[j][i]]++;
      }
      for(int j=1;j<101;j++){
        if(tmp[j]>0)
          check.push_back({tmp[j],j});
      }
      sort(check.begin(), check.end());
      int cs = check.size();
      for(int j=0;j<101;j++) arr[j][i]=0;
      for(int j=0;j<cs;j++){
        arr[j*2][i]=check[j].second;
        arr[j*2+1][i]=check[j].first;
      }
      a = max(a, cs*2);
    }
    row=a;
  }
  /*
  for(int i=0;i<row;i++){
    for(int j=0;j<col;j++){
      cout<<arr[i][j]<<' ';
    }
    cout<<endl;
  }
  cout<<endl;
  */
}

void solve(){
  int timer=0;
  while(arr[r-1][c-1]!=k&&timer<101){
    if(row>=col) def(1);
    else def(0);
    timer++;
  }
  if(timer>100) cout<<-1;
  else cout<<timer;
}

int main(){
  input();
  solve();
  return 0;
}