#include<iostream>
using namespace std;

int arr[1025][1025];
int dp[1025][1025];
int N,M;

void input(){
    cin>>N>>M;
    for(int i=1;i<=N;i++)
        for(int j=1;j<=N;j++){
            cin>>arr[i][j];
            dp[i][j] = dp[i-1][j] + dp[i][j-1] - dp[i-1][j-1] + arr[i][j];
        }
}

void solve(){
    input();
    int x1,x2,y1,y2;
    for(int i=0;i<M;i++){
        cin>>x1>>y1>>x2>>y2;
        int ans = dp[x2][y2] - dp[x1-1][y2] - dp[x2][y1-1] + dp[x1-1][y1-1];
        cout<<ans<<'\n';
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    solve();
    return 0;
}