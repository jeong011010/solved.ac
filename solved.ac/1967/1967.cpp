#include<iostream>
#include<vector>
#include<queue>
using namespace std;
#define INF 1e9+7

int n, len;
vector<pair<int,int>> v[10001];
vector<int> Dist;
int m,m_cur;
int MAX(int a,int b){return a>b?a:b;}

void input(){
    cin>>n;
    int s,e,w;
    for(int i=0;i<n-1;i++){
        cin>>s>>e>>w;
        v[s].push_back(make_pair(e,w));
        v[e].push_back(make_pair(s,w));
    }
}

void Dijkstra(int Start){
    m=0;
    Dist.clear();
    Dist.resize(n+1,INF);
    Dist[Start] = 0;
    priority_queue<pair<int,int>> pq;
    pq.push(make_pair(0,Start));
    while(!pq.empty()){
        int Cost = -pq.top().first;
        int Cur = pq.top().second;
        pq.pop();

        for(int i=0;i<v[Cur].size();i++){
            int nCost = Cost + v[Cur][i].second;
            int Next = v[Cur][i].first;
            if(Dist[Next]>nCost){
                Dist[Next] = nCost;
                if(m<=Dist[Next]){
                    m=Dist[Next];
                    m_cur = Next;
                }
                pq.push(make_pair(-Dist[Next],Next));
            }
        }
    }
}

void f(){
    Dijkstra(1);
    Dijkstra(m_cur);
    cout<<m;
}

void solve(){
    input();
    f();
}

int main(){
    solve();
    return 0;
}