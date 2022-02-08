#include<iostream>
#include<queue>
#include<vector>
#include<stack>
#include<cmath>
#include<algorithm>
using namespace std;

int N,M;
int arr[52][52];
int m_x[4]={-1,1,0,0};
int m_y[4]={0,0,-1,1};
vector<pair<int,int>> house, Chouse;

void input(){
    cin>>N>>M;
    for(int i=1;i<=N;i++)
        for(int j=1;j<=N;j++){
            cin>>arr[i][j]; 
            if(arr[i][j]==1)house.push_back({i,j});
            else if(arr[i][j]==2)Chouse.push_back({i,j});}
    for(int i=0;i<=N+1;i++)
        arr[0][i]=arr[N+1][i]=arr[i][0]=arr[i][N+1]=3;
}

class space{
public:    
    int x,y;
    int cnt;
};

void bfs(int tmp[52][52]){
    int cnt=0;

    space s;
    for(int i=0;i<house.size();i++){
        queue<space> q;
        s = {house[i].first,house[i].second,1};
        q.push(s);
    
        while(!q.empty()){
            bool find=false;
            s = q.front();
            q.pop();
            for(int i=0;i<4;i++){
                int a = s.x+m_x[i];
                int b = s.y+m_y[i];
                int n = tmp[a][b];
                if(n==2){
                    find=true;
                    cnt+=s.cnt;
                    break;
                }
                else if(n==0||n==1)
                    q.push({a,b,s.cnt+1});
            }
            if(find) break;
        }
    }
    cout<<cnt;
}

void f(){
    int tmp[52][52];
    copy(&arr[0][0],&arr[0][0]+2704,&tmp[0][0]);
    int n=ceil((double)Chouse.size()/2);
    if(M>n){
        n=M-n;
    }

}

void solve(){
    input();
}

int main(){
    solve();
    return 0;
}