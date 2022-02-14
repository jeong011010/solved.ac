#include<iostream>
using namespace std;



int N, ans=0;
bool arr[18][18];

void input(){
    cin>>N;
    for(int i=1;i<=N;i++)
        for(int j=1;j<=N;j++)
            cin>>arr[i][j];
}

void dfs(int x, int y, int form){
    if(x==N&&y==N){
        ans++;
        return;
    }
    switch (form)
    {
    case 0:
        if(arr[x][y+1] == 0 && y+1<=N)
            dfs(x,y+1,0);
        break;
    case 1:
        if(arr[x+1][y] == 0 && x+1<=N)
            dfs(x+1,y,1);
        break;
    case 2:
        if(arr[x][y+1] == 0 && y+1<=N)
            dfs(x,y+1,0);
        if(arr[x+1][y] == 0 && x+1<=N)
            dfs(x+1,y,1);
        break;
    }
    if(arr[x+1][y+1]==0 && arr[x][y+1] == 0 && arr[x+1][y] == 0 && x+1<=N && y+1<=N)
        dfs(x+1,y+1,2);
}

void solve(){
    input();
    dfs(1,2,0);
    cout<<ans;
}

int main(){
    solve();
    return 0;
}