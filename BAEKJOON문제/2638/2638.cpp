#include<iostream>
#include<queue>
#include<stack>
using namespace std;

int arr[101][101];
int N,M,count=0;


int xMove[4] = {-1,1,0,0};
int yMove[4] = {0,0,-1,1};



void input(){
    cin>>N>>M;
    for(int i=1;i<=N;i++)
        for(int j=1;j<=M;j++)
            cin>>arr[i][j];
    for(int i=0;i<=N+1;i++)
        arr[i][0] = arr[i][M+1] = -1;
    for(int i=0;i<=M+1;i++)
        arr[0][i] = arr[N+1][i] = -1;
}

bool check(){
    bool e = true;
    for(int i=1;i<=N;i++){
        for(int j=1;j<=M;j++){
            if(arr[i][j]>2) {arr[i][j]=0;}
            else if(arr[i][j]>0) {arr[i][j]=1;e=false;}
            //cout<<arr[i][j];
        }
        //cout<<'\n';
    }
    //cout<<'\n';
    return e;
}

void dfs(){
    bool check[101][101] = {false};
    
    stack<pair<int,int>> s;
    s.push(make_pair(1,1));

    while(!s.empty()){       
        int y=s.top().first;
        int x=s.top().second;
        s.pop();
        if(check[y][x]==false){        
            check[y][x]=true;

            for(int i=0;i<4;i++){
                int my = y+yMove[i];
                int mx = x+xMove[i];
                if(!check[my][mx]){
                    if(arr[my][mx]==0){
                        s.push(make_pair(my,mx));
                    }
                    else if(arr[my][mx]>0){
                        arr[my][mx]++;
                    }
                }
            }
        }
    }  
    count++;
}

void f(){
    while(!check()){
        dfs();}
    /*for(int i=0;i<1;i++){
        dfs();
        check();
    }*/
    cout<<count;
}

void solve(){
    input();
    f();
}

int main(){
    solve();
    return 0;
}