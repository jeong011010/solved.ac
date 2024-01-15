// 시작 18:23 끝 19:13
#include<iostream>
#include<string>
using namespace std;

string pw;
int dp[5001], s;

void input(){
  cin>>pw;
  s=pw.length();
  for(int i=1;i<=s;i++)
    dp[i]=0;
}

void solve(){
  dp[0]=1;
  for(int i=1;i<=s;i++){
    int tmp = pw[i-1]-'0';
    if(tmp>0){
      dp[i]+=dp[i-1]%1000000;

    }
    if(i>1){
      int tmp2 = (pw[i-2]-'0')*10;
      if(tmp2+tmp<=26&&tmp2+tmp>9)
        dp[i]+=dp[i-2]%1000000;
    }
  }
  cout<<dp[s]%1000000;
}

int main(){
  input();
  solve();
  return 0;
}