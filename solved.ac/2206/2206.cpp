#include<iostream>
#include<queue>
using namespace std;

int arr[1002][1002];
bool visited[1002][1002][2];
int N,M;
int arr_x[4] = {0,0,-1,1};
int arr_y[4] = {-1,1,0,0};
typedef struct tile{
    int n,m;
    int count;
    bool wall;
}tile;
queue<tile> q;

void input(){
    string s;
    cin>>N>>M;
    for(int i=1;i<=N;i++){
        cin>>s;
        for(int j=1;j<=M;j++)
            arr[i][j] = s[j-1]-48;
            
    }
    for(int i=0;i<=N+1;i++) arr[i][0]=arr[i][M+1]=2;
    for(int i=0;i<=M+1;i++) arr[0][i]=arr[N+1][i]=2;
}

void search(tile t){
    tile tmp;
    for(int i=0;i<4;i++){
        tmp=t;
        tmp.n+=arr_y[i];
        tmp.m+=arr_x[i];
        tmp.count++;
        if(arr[tmp.n][tmp.m]==0 && !visited[tmp.n][tmp.m][tmp.wall]){
            q.push(tmp); 
            visited[tmp.n][tmp.m][tmp.wall]=true;
        }
        if(arr[tmp.n][tmp.m]==1 && !tmp.wall)
        {
            tmp.wall=1;
            q.push(tmp);
            visited[tmp.n][tmp.m][tmp.wall]=true;            
        }
    }
}
void print(){
    for(int i=1;i<=N;i++){
        for(int j=1;j<=M;j++)
            cout<<visited[i][j][0];
        cout<<'\n';
    }
    cout<<'\n';
    for(int i=1;i<=N;i++){
        for(int j=1;j<=M;j++)
            cout<<visited[i][j][1];
        cout<<'\n';
    }
    cout<<'\n';
}

void f(){
    int c;
    q.push({1,1,1,0});
    //visited[1][1][0]=true;
    tile t;
    bool clear=0;
    while(!q.empty()){
        t = q.front();
        q.pop();
        c++;
        if(t.n==N&&t.m==M){
            clear=1;
            break;
        }
        search(t);
    }
    cout<<(clear?t.count:-1);
}

void solve(){
    input();
    f();
}

int main(){
    solve();
    return 0;
}