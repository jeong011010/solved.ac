#include<iostream>
#include<queue>
#include<vector>
using namespace std;

int n;
vector<int> v, DP;

void input(){
    cin>>n;
    int x;
    for(int i=0;i<n;i++){
        for(int j=0;j<i+1;j++){
            cin>>x;
            v.push_back(x);
        }
    }
}

int MAX(int a,int b){return a>b?a:b;}

void dp(){
    priority_queue<int> pq;
    int x=1,tmp=2,n=0;
    DP.push_back(v[0]);
    pq.push(DP[0]);
    for(int i=1;i<v.size();i++){
        if(x==1){DP.push_back(DP[n]+v[i]);n++;}
        else if(x==tmp){DP.push_back(DP[n-1]+v[i]);x=0;tmp++;}
        else{DP.push_back(MAX(DP[n-1],DP[n])+v[i]);n++;}
        pq.push(DP[i]);
        x++;
    }
    cout<<pq.top();
}

void solve(){
    input();
    dp();
}

int main(){
    solve();
    return 0;
}