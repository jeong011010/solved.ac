#include <iostream>
#include <queue>
#include <vector>
using namespace std;
#define INF 1000

int N,M,X;
vector <pair<int,int>> v[1001]; // vec_end, cost
vector <int> Dist;
int res [1001];

int max(int a, int b){return a>b?a:b;}

void input(){
    cin>>N>>M>>X;
    int s,e,t;
    for(int i=0;i<M;i++){
        cin>>s>>e>>t;
        v[s].push_back(make_pair(e,t));
    }
}

void Dijstra(int Start){
    priority_queue<pair<int,int>> pq; // cost, cur
    pq.push(make_pair(0, Start));
    Dist.clear();
    Dist.resize(N+1,INF);

    Dist[Start] = 0;
    while(!pq.empty()){
        int cost = -pq.top().first;
        int cur = pq.top().second;
        pq.pop();
        for(int i=0;i<v[cur].size();i++){
            int next = v[cur][i].first;
            int ncost = v[cur][i].second + cost;

            if(Dist[next] > ncost){
                Dist[next] = ncost;
                pq.push(make_pair(-Dist[next],next));
            }
        }
    }
}

void f(){
    int max_n=0;
    for(int i=1;i<=N;i++){
        Dijstra(i);
        res[i]=Dist[X];
    }
    res[X]=0;
    Dijstra(X);
    Dist[X]=0;
    for(int i=1;i<=N;i++){
        res[i] += Dist[i];
        max_n = max(max_n,res[i]);
    }
    cout<<max_n;
}

void solve(){
    input();
    f();
}

int main(){
    solve();
    return 0;
}