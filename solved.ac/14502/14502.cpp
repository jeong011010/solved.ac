#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int N, M, ans=0;
int arr[10][10];
int tmp[10][10];
vector<pair<int,int>> virus;

void input(){
    cin>>N>>M;
    for(int i=1;i<=N;i++)
        for(int j=1;j<=M;j++){
            cin>>arr[i][j];
            if(arr[i][j]==2) virus.push_back({i,j});
            }
}

void bfs(){
    queue<pair<int,int>> q;
    for(int i=0;i<virus.size();i++) q.push(virus[i]);
    while(!q.empty()){
        
    }

}

void solve(){
    input();
}

int main(){
    solve();
    return 0;
}