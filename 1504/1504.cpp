#include<iostream>
#include<vector>
#include<queue>
using namespace std;
#define INF 1e9+7

vector<pair<int,int>> v[801];
int N,E,v1,v2;
vector<int> Dist;

void input(){
    int a,b,c;
    cin>>N>>E;
    for(int i=0;i<E;i++){
        cin>>a>>b>>c;
        v[a].push_back(make_pair(b,c));
        v[b].push_back(make_pair(a,c));
    }
    cin>>v1>>v2;
}

void Dijkstra(int Start){
    priority_queue<pair<int,int>> pq;
    pq.push(make_pair(0,Start));
    Dist.clear();
    Dist.resize(N+1, INF);

    Dist[Start] = 0;
    while(!pq.empty()){
        int Cost = -pq.top().first;
        int Cur = pq.top().second;
        pq.pop();
        for(int i=0;i<v[Cur].size();i++){
            int next = v[Cur][i].first;
            int nCost = v[Cur][i].second + Cost;

            if(Dist[next]>nCost){
                Dist[next] = nCost;
                pq.push(make_pair(-Dist[next],next));
            }
        }
    }
}

void f(){
    int case_1=0,case_2=0;
    Dijkstra(1);
    case_1 += Dist[v1];
    case_2 += Dist[v2];
    cout<<case_1<<' '<<case_1<<'\n';
    Dijkstra(v1);
    case_1 += Dist[v2];
    case_2 += Dist[N];
    cout<<case_1<<' '<<case_1<<'\n';
    Dijkstra(v2);
    case_1 += Dist[N];
    case_2 += Dist[v1];
    cout<<case_1<<' '<<case_1<<'\n';
    int ans = (case_1<case_2?case_1:case_2);
    if(ans>100000000 || ans<0) cout<<-1;
    else cout<<ans;
}

void solve(){
    input();
    f();
}

int main(){
    solve();
    return 0;
}