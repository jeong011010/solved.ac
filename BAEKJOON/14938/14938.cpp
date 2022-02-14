#include<iostream>
#include<vector>
#include<queue>
using namespace std;
#define INF 1e9+7

int n, m, r;
vector<int> item;
vector<pair<int,int>> v[100];
vector<int> dist;

void input(){
    cin>>n>>m>>r;
    int t, a, b, l;
    for(int i=0;i<n;i++) {cin>>t; item.push_back(t);}
    for(int i=0;i<r;i++) {cin>>a>>b>>l; v[a-1].push_back({b-1,l}); v[b-1].push_back({a-1,l});}
}

int Dijkstra(int start){
    int cnt=item[start];
    priority_queue<pair<int,int>> pq;
    dist.clear();
    dist.resize(n+1,INF);
    dist[start] = 0;
    pq.push({0,start});
    while(!pq.empty()){
        int cost = -pq.top().first;
        int node = pq.top().second;
        pq.pop();
        for(int i=0;i<v[node].size();i++){
            int next = v[node][i].first;
            int ncost = v[node][i].second + cost;
            if(ncost<dist[next] && ncost<=m){
                if(dist[next]==INF) cnt+=item[next];
                dist[next]=ncost;
                pq.push({-ncost,next});
            }
        }
    }
    return cnt;
}

void f(){
    int ans=0;
    for(int i=0;i<n;i++) ans = max(ans,Dijkstra(i));
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