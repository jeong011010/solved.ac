#include <iostream>
#define INF 1e9
using namespace std;

bool dp[2502][2502];
string str=" ";

void input(){
  string tmp;
  cin>>tmp;
  str+=tmp;
}


void solve(){
  int n = str.size();
  for (int i = 1; i < n; i++)
    dp[i][i] = 1;

  for (int i = 1; i < n; i++) 
    if (str[i] == str[i + 1]) 
      dp[i][i + 1] = 1;

  for(int i=2;i<n;i++){
    for(int j=1;j<n-i;j++){
      if(str[j]==str[j+i]&&dp[j+1][j+i-1]){
        dp[j][j+i]=1;

      }
    }
  }

  int src[2500];
  src[0]=0;

  for(int i=1;i<n;i++){
    src[i]=INF;
    for(int j=1;j<=i;j++){
      if(dp[j][i]){
        src[i]=min(src[i],src[j-1]+1);
      }
    }
  }
  cout<<src[n-1];
}

int main()
{
  input();
  solve();

  return 0;
}