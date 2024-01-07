#include<iostream>
#include<vector>
#include<string>
using namespace std;

int T;
vector<pair<pair<bool, bool>,pair<bool,bool>>> mbti[100001];

void input(){
  int N;
  cin>>T;
  for(int i=0;i<T;i++){
    cin>>N;
    for(int j=0;j<N;j++){
      string tmp;
      bool tmpB[4];
      cin>>tmp;
      if(tmp[0]=='E') tmpB[0]=0;
      else tmpB[0]=1;
      if(tmp[1]=='S') tmpB[1]=0;
      else tmpB[1]=1;
      if(tmp[2]=='T') tmpB[2]=0;
      else tmpB[2]=1;
      if(tmp[3]=='J') tmpB[3]=0;
      else tmpB[3]=1;
      mbti[i].push_back(make_pair(make_pair(tmpB[0],tmpB[1]),make_pair(tmpB[2],tmpB[3])));
    }
  }
}

int distance(int t){
  int ans=20;
  int size=mbti[t].size();
  for(int i=0;i<size-2;i++){
    for(int j=i+1;j<size-1;j++){
      for(int k=j+1;k<size;k++){
        int sum=0;
        if(!(mbti[t][i].first.first==mbti[t][j].first.first)) sum++;
        if(!(mbti[t][i].first.second==mbti[t][j].first.second)) sum++;
        if(!(mbti[t][i].second.first==mbti[t][j].second.first)) sum++;
        if(!(mbti[t][i].second.second==mbti[t][j].second.second)) sum++;
        if(!(mbti[t][i].first.first==mbti[t][k].first.first)) sum++;
        if(!(mbti[t][i].first.second==mbti[t][k].first.second)) sum++;
        if(!(mbti[t][i].second.first==mbti[t][k].second.first)) sum++; 
        if(!(mbti[t][i].second.second==mbti[t][k].second.second)) sum++; 
        if(!(mbti[t][k].first.first==mbti[t][j].first.first)) sum++;
        if(!(mbti[t][k].first.second==mbti[t][j].first.second)) sum++;
        if(!(mbti[t][k].second.first==mbti[t][j].second.first)) sum++;
        if(!(mbti[t][k].second.second==mbti[t][j].second.second)) sum++; 
        if (sum<ans) ans=sum;
        if (sum==0) return 0;
      }
    }
  }
  return ans;
}

void solve(){
  for(int i=0;i<T;i++){
    cout << distance(i) <<endl;
  }

}

int main()
{
  input();
  solve();

  return 0;
}