#include<iostream>

using namespace std;

int ans=0;
int s;
int arr[1001][1001];
string s1, s2;

void input(){
    cin>>s1>>s2;
    s = max(s1.size(),s2.size());
}

void f(){
    for(int i=1;i<=s2.size();i++){
        for(int j=1;j<=s1.size();j++){
            if(s2[i-1]==s1[j-1]) arr[i][j]=arr[i-1][j-1]+1;
            else arr[i][j]=max(arr[i-1][j],arr[i][j-1]);
            ans = max(ans,arr[i][j]);
        }
    }
    for(int i=0;i<=s2.size();i++){
        for(int j=0;j<=s1.size();j++){
            cout<<arr[i][j]<<' ';
        }
        cout<<'\n';
    }
    cout<<ans;
}

void solve(){
    input();
    f();
}

int main(){
    solve();
    return 0;
}