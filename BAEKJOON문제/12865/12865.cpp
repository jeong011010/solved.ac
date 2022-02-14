#include<iostream>
#include<queue>
using namespace std;

int N,K;
int DP[101][100001];
priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;

void input(){
    cin>>N>>K;
    int W,V;
    for(int i=0;i<N;i++){
        cin>>W>>V;
        pq.push(make_pair(W,V));
    }
}

void f(){
    for(int i=1;i<=N;i++){
        int W=pq.top().first;
        int V=pq.top().second;
        pq.pop();

        for(int j=1;j<=K;j++){
            if(W<=j){
                if(V + DP[i-1][j-W] > DP[i-1][j])
                    DP[i][j] = V + DP[i-1][j-W];
                else DP[i][j] = DP[i-1][j];
            }
            else
                DP[i][j] = DP[i-1][j];
        }
    }
    /*for(int i=1;i<=K;i++){
        for(int j=1;j<=N;j++){
            cout<<DP[j][i]<<' ';}
        cout<<'\n';
        }*/
    cout<<DP[N][K];
}

void solve(){
    input();
    f();
}

int main(){
    solve();
    return 0;
}