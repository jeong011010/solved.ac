#include<iostream>
using namespace std;

int arr[3]; // 메모리 제한 4MB를 피하기 위한 sliding window 사용
int dp1[2][3], dp2[2][3];
int N;

void input(){
    for(int i=0;i<3;i++)
        cin>>arr[i];
}

void f(){ // sliding window
    input();
    dp1[1][0] = arr[0] + max(dp1[0][0],dp1[0][1]);
    dp2[1][0] = arr[0] + min(dp2[0][0],dp2[0][1]);
    dp1[1][1] = arr[1] + max(max(dp1[0][0],dp1[0][1]),dp1[0][2]);
    dp2[1][1] = arr[1] + min(min(dp2[0][0],dp2[0][1]),dp2[0][2]);
    dp1[1][2] = arr[2] + max(dp1[0][1],dp1[0][2]);
    dp2[1][2] = arr[2] + min(dp2[0][1],dp2[0][2]);
    for(int i=0;i<3;i++){
        dp1[0][i] = dp1[1][i]; // 배열 밀기
        dp2[0][i] = dp2[1][i];        
    }
}

void solve(){
    cin>>N;
    for(int i=0;i<3;i++){
        dp1[1][i] = 0;
        dp2[1][i] = 0;
    }
    if(N>0)
        for(int i=0;i<3;i++){
            cin>>arr[i];
            dp1[0][i] = arr[i];
            dp2[0][i] = arr[i];
        }
    for(int i=1;i<N;i++)
        f();
    int ans1 = 0, ans2 = 1e9+7;
    for(int i=0;i<3;i++){
        ans1 = max(ans1,dp1[0][i]);
        ans2 = min(ans2,dp2[0][i]);
    }
    cout<<ans1<<' '<<ans2<<'\n';
}

int main(){
    solve();
    return 0;
}