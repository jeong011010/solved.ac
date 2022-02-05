#include<iostream>
#include<vector>
#include<stack>
using namespace std;

vector<int> node[100001];
int root[100001];
int N;

void input(){
    cin>>N;
    int a,b;
    for(int i=0;i<N-1;i++){
        cin>>a>>b;
        node[a].push_back(b);
        node[b].push_back(a);
    }
}

void tree(){
    stack<int> s;
    s.push(1);
    while(!s.empty()){
        int n = s.top();
        s.pop();
        for(int i=0;i<node[n].size();i++)
            if(root[node[n][i]]==0){
                s.push(node[n][i]);
                root[node[n][i]]=n;
                //cout<<node[n][i]<<' '<<root[node[n][i]]<<'\n';
            }
    }
    for(int i=2;i<=N;i++)
        cout<<root[i]<<'\n';
}

void solve(){
    input();
    tree();
}

int main(){
    solve();
    return 0;
}