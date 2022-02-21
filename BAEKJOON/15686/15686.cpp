#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

#define INF 1e9+7

int ans=INF;
int N,M;
int arr[50][50];
bool visited[13];

vector<pair<int,int>> house, chicken;

void input(){
    cin>>N>>M;
    for(int i=0;i<N;i++)
        for(int j=0;j<N;j++){
            cin>>arr[i][j];
            if(arr[i][j]==1) house.push_back({i,j});
            if(arr[i][j]==2) chicken.push_back({i,j});
        }
}

int distance(pair<int,int> a, pair<int,int> b){
    return abs(a.first - b.first)+ abs(a.second - b.second);
}

void dfs(int cnt, int n){
    
    if(cnt==M){
        int tmp = 0;
        for (int i = 0; i < house.size(); i++)
            {
                int dist = INF;
                for (int j = 0; j < chicken.size(); j++)
                    if (visited[j]){
                        dist = min(dist, distance(house[i], chicken[j]));
                    }
                tmp += dist;
            }
        ans = min(ans, tmp);
        return;
    }

    if(n==chicken.size()) return;

    visited[n]=true;
    dfs(cnt+1, n+1);
    visited[n]=false;
    dfs(cnt, n+1);
}

void solve(){
    input();
    dfs(0,0);
    cout<<ans;
}

int main(){
    solve();
    return 0;
}