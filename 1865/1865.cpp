#include<iostream>
#include<vector>
using namespace std;
#define INF 10000000

struct Edge{
    int Start,End,Time;
};

int TC, N,M,W,e=0;
vector<int> TIME;

bool Bellman_Ford(vector<Edge> v){
    TIME.clear();
    TIME.resize(N+1,INF);
    TIME[1] = 0;
    for(int i=0;i<N;i++){
        for(int j=0;j<v.size();j++){
            int s = v[j].Start;
            int e = v[j].End;
            int t = v[j].Time;
            if(TIME[s] + t < TIME[e])
                TIME[e] = TIME[s] + t;
        }
    }
    for (int i=0;i<v.size();i++){
            int s = v[i].Start;
            int e = v[i].End;
            int t = v[i].Time;
            if(TIME[s] + t < TIME[e])
                return true;
    }
    return false;
}

void f(){

}

void solve(){
    cin>>TC;
    for(int i=0;i<TC;i++){
        vector<Edge> v;
        int S,E,T;
        cin>>N>>M>>W;
        for(int i=0;i<M;i++){
            cin>>S>>E>>T;
            v.push_back({S,E,T});
            v.push_back({E,S,T});
        }
        for(int i=0;i<W;i++){
            cin>>S>>E>>T;
            v.push_back({S,E,-T});
        }
        if(Bellman_Ford(v)) cout<<"YES"<<"\n";
        else cout<<"NO"<<"\n";
    }
}

int main(){
    solve();
    return 0;
}