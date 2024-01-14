//15:43 시작 16:15 끝
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int N;
int DP[1001], arr[1001];
vector<int> v[1001];

void input(){
  cin>>N;
  for(int i=0;i<N;i++)
    cin>>arr[i];
}

void solve(){
  int ans=1, num=0;
  for(int i=0;i<N;i++){
    DP[i]=1; // 수열개수 자기자신 추가
    v[i].push_back(arr[i]); // 수열에 자기자신 추가
    int tmp=-1;
    for(int j=0;j<i;j++){
      if(arr[j]<arr[i]){ // 자신보다 작은 수 찾았다면
        if(DP[i]<DP[j]+1) tmp=j; // 자기보다 작으며, 긴 수열의 위치
        DP[i] = max(DP[i], DP[j]+1); // 수열개수 DP 갱신
        if(ans<DP[i]){ //현재 수열개수 최댓값보다 수열개수가 크다면 갱신
          ans=DP[i];
          num=i; // 가장 길었던 수열의 위치 저장
        }
      }
    }
    if(tmp!=-1)
      for(int j=0;j<DP[tmp];j++){ // 긴 수열의 위치에 있던 수열들을 현재 수열에 추가
        v[i].push_back(v[tmp][j]);
      }
  }
  sort(v[num].begin(),v[num].end());
  cout<<ans<<endl;
  for(int i=0;i<v[num].size();i++){
    cout<<v[num][i]<<' ';
  }
}

int main(){
  input();
  solve();
  return 0;
}