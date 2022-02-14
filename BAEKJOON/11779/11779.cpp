#include<iostream>
#include<vector>
#include<queue>
using namespace std;
#define INF 1e9+7

vector<pair<int,int>> v[1001];
vector<int> Route_V;
int Dist[1001];
int Route[1001];
int n,m,S,E;


void input(){
    cin>>n>>m;
    int s,e,w;
    for(int i=1;i<=n;i++) Dist[i] = INF;
    for(int i=0;i<m;i++){
        cin>>s>>e>>w;
        v[s].push_back(make_pair(e,w));
    }
    cin>>S>>E;
}

void Dijkstra(){
    priority_queue<pair<int,int>> pq;
    pq.push(make_pair(0,S));
    Dist[S]=0;
    while(!pq.empty()){
        int cost = -pq.top().first;
        int node = pq.top().second;
        pq.pop();
        if(Dist[node]<cost) continue;
        for(int i=0;i<v[node].size();i++){
            int next = v[node][i].first;
            int nCost = v[node][i].second + cost;
            if(nCost<Dist[next]){
                Dist[next] = nCost;
                pq.push(make_pair(-nCost,next));
                Route[next] = node;
            }

        }
    }
    cout<<Dist[E]<<'\n';
    int tmp = E;
    while(tmp){
        Route_V.push_back(tmp);
        tmp = Route[tmp];
    }
    cout<<Route_V.size()<<'\n';
    for(int i=Route_V.size()-1;i>=0;i--)
        cout<<Route_V[i]<<' ';
}

void solve(){
    input();
    Dijkstra();
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
 
    solve();
    return 0;
}