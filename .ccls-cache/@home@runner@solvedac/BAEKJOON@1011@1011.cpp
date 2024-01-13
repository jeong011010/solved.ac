#include<iostream>
using namespace std;
int main() {
  long long int T, x, y, distance, m, n, count = 0;


  cin >> T;
  for (int i = 0; i < T; i++) {
    cin >> x >> y;
    distance = y - x;
    m = 1;
    n = 1;

    while (1) {
      if (distance <= m * n) {
        count = m + n - 1;
        break;
      }
      else {
        if (m < n)
          m++;
        else
          n++;
      }	
    }

    cout << count << "\n";
  }
}

/* 메모리초과 dp코드
#include<iostream>
#include<cmath>
#include<vector>
using namespace std;

int T;
void input(){
  cin>>T;
}

void def(long long x, long long y){
  vector<pair<long long,long long>> dp;
  y-= x;
  x=0;
  dp.push_back({1,1});
  dp.push_back({2,1});
  dp.push_back({3,1});
  for(long long i=4;i<y+1;i++){
    long long tmp=sqrt(i);
    long long a=dp[i-2].first, b=dp[i-2].second;
    if(dp[i-2].second != dp[i-3].second)
      a++;
    if(i==pow(tmp, 2)) b++;
    dp.push_back({a,b});
  }
  cout<<dp[y-1].first<<endl;

}


void solve(){
  long long x,y;
  for(int i=0;i<T;i++){
    cin>>x>>y;
    def(x,y);
  }  
}

int main(){
  input();
  solve();
  return 0;
}
*/