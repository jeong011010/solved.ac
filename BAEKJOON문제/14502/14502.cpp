#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;

int N, M, ans=0;
int arr[10][10];
int tmp[10][10];
int m_x[4]={-1,1,0,0};
int m_y[4]={0,0,-1,1};
vector<pair<int,int>> virus,wall;

void input(){
    cin>>N>>M;
    for(int i=1;i<=N;i++)
        for(int j=1;j<=M;j++){
            cin>>arr[i][j];
            if(arr[i][j]==2) virus.push_back({i,j});
            if(arr[i][j]==0) wall.push_back({i,j});
            }
    for(int i=0;i<=N+1;i++) arr[i][0]=arr[i][M+1]=1;
    for(int i=0;i<=M+1;i++) arr[0][i]=arr[N+1][i]=1;
}

void bfs(int a, int b, int c){
    //int size= (N+2)*(M+2);
    copy(&arr[0][0],&arr[0][0]+100,&tmp[0][0]);

    tmp[wall[a].first][wall[a].second] = 1;
    tmp[wall[b].first][wall[b].second] = 1;
    tmp[wall[c].first][wall[c].second] = 1;        

    queue<pair<int,int>> q;
    for(int i=0;i<virus.size();i++) q.push(virus[i]);

    /*for(int i=0;i<=N+1;i++){
        for(int j=0;j<=M+1;j++)
            cout<<tmp[i][j]<<' ';
        cout<<'\n';   
    }*/

    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        for(int i=0;i<4;i++){
            if(tmp[x+m_x[i]][y+m_y[i]]==0){
                //cout<<x<<'+'<<m_x[i]<<','<<y<<'+'<<m_y[i]<<'\n';
                q.push({x+m_x[i],y+m_y[i]});
                tmp[x+m_x[i]][y+m_y[i]]=2;
            }
        }
    }
    int cnt=0;
    for(int i=1;i<=N;i++)
        for(int j=1;j<=M;j++)
            if(tmp[i][j]==0) cnt++;
    ans = max(ans,cnt);
}

void setup(){
    int s = wall.size();
    for(int i=0;i<s;i++){
        for(int j=i+1;j<s;j++){
            for(int k=j+1;k<s;k++){
                bfs(i,j,k);
            }
        }
    }
}

void solve(){
    input();
    setup();
    cout<<ans;
}

int main(){
    solve();
    return 0;
}