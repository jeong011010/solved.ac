#include<iostream>
#include<queue>
#include<vector>
using namespace std;
#define INF 10000000

vector<pair<int,int>> v[1001];
vector<int> Dist;
int N,M,Start,End;

void input(){
    int s,e,w;
    cin>>N>>M;
    for(int i=0;i<M;i++){
        cin>>s>>e>>w;
        v[s].push_back(make_pair(e,w));
    }
    cin>>Start>>End;
}

void Dijkstra(){
    Dist.clear();
    Dist.resize(N+1,INF);
    Dist[Start]=0;
    priority_queue<pair<int,int>> pq;
    pq.push(make_pair(0,Start));
    while(!pq.empty()){
        int cost = -pq.top().first;
        int cur = pq.top().second;
        pq.pop();
        if (Dist[cur] < cost) continue; 
        for(int i=0;i<v[cur].size();i++){
            int next = v[cur][i].first;
            int nCost = v[cur][i].second + cost;
            if(Dist[next] > nCost){
                Dist[next] = nCost;
                pq.push(make_pair(-Dist[next],next));
            }

        }
    }
}

void solve(){
    input();
    Dijkstra();
    cout<<Dist[End];
}

int main(){
    solve();
    return 0;
}