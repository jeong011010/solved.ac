#include<iostream>
using namespace std;

int DP1[1001], DP2[1001];
int arr[1001];
int N;

void input(){
    cin>>N;
    for(int i=0;i<N;i++)
        cin>>arr[i];
}

void f(){
    for(int i=0;i<N;i++){
        DP1[i]=1;
        for(int j=0;j<=i;j++)
            if(arr[j]<arr[i]&&DP1[i]<=DP1[j])
                DP1[i]++;
    }
    for(int i=N;i>=0;i--){
        DP2[i]=1;
        for(int j=N;j>=i;j--)
            if(arr[j]<arr[i]&&DP2[i]<=DP2[j])
                DP2[i]++;
        DP1[i]+=DP2[i];
    }
    int ans=0;
    for(int i=0;i<N;i++) ans=max(ans,DP1[i]);
    cout<<ans-2;
}

void solve(){
    input();
    f();
}

int main(){
    solve();
    return 0;
}