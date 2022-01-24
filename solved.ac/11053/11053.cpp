#include<iostream>
#include<vector>
#include<map>
using namespace std;

int N, ans=1;
vector<int> v;
int DP[1001];

void input(){
    cin >> N;
    int tmp;
    for(int i=0;i<N;i++) {
        cin>>tmp;
        v.push_back(tmp);
    }
}

void f(){
    DP[0]=1;
    for(int i=1;i<N;i++){
        for(int j=0;j<i;j++){
            if(v[j]<v[i]){
                DP[i]=max(DP[i],DP[j]);
            }
        }
        DP[i]++;
        ans=max(ans,DP[i]);
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