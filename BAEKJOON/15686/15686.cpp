#include<iostream>
#include<queue>
#include<vector>
#include<stack>
#include<cmath>
#include<algorithm>
using namespace std;

int ans=1e9+7;
int N,M;
int arr[52][52];
int m_x[4]={-1,0,1,0};
int m_y[4]={0,1,0,-1};
vector<pair<int,int>> house, Chouse, V;

void input(){
    cin>>N>>M;
    for(int i=1;i<=N;i++)
        for(int j=1;j<=N;j++){
            cin>>arr[i][j]; 
    for(int i=0;i<=N+1;i++)
        arr[0][i]=arr[N+1][i]=arr[i][0]=arr[i][N+1]=3;
}

void bfs(){
    int cnt=0;

    for(int i=0;i<house.size();i++){
        int x = house[i].first;
        int y = house[i].second;
        int d = 1e9+7;

        for(int j=0;j<V.size();j++){
            int xx = V[j].first;
            int yy = V[j].second;
            int Dist = abs(xx - x) + abs(yy - y);
            d = min(d,Dist);
        }
        cnt += d;
    }

    /*space s;
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
    }*/
    //cout<<cnt<<'\n';


    ans=min(ans,cnt);
}

void r(int cnt, int n, int tmp[52][52]){
    if(cnt==n){
        bfs(tmp);
        return;
    }
    else{
        for(int i=n;i<Chouse.size()-M+1+n;i++){
            //tmp[Chouse[i].first][Chouse[i].second] = 2;
            V.push_back(Chouse[i]);
            r(cnt,n+1,tmp);
            //[Chouse[i].first][Chouse[i].second] = 0;
            V.pop_back();
        }
    }
}

void f(){
    /*int tmp[52][52];
    copy(&arr[0][0],&arr[0][0]+2704,&tmp[0][0]);*/
    int n=ceil((double)Chouse.size()/2);

    r(M,0,arr);
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