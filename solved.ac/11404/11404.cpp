#include<iostream>
using namespace std;
#define INF 1e9+7

int N,M;
int weight_arr[100][100];

void input(){
    cin>>N>>M;
    int a,b,c;
    for(int i=0;i<M;i++) {
        cin>>a>>b>>c;
        if(weight_arr[a-1][b-1]>0)
            weight_arr[a-1][b-1]=min(c,weight_arr[a-1][b-1]);
        else weight_arr[a-1][b-1]=c;
    }
}

void init(){
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++) 
            if(weight_arr[i][j]==0&&i!=j) weight_arr[i][j]=INF;
    }
}

void Floyd_Warshall(){
    init();
    for(int k=0;k<N;k++)
        for(int i=0;i<N;i++)
            for(int j=0;j<N;j++)
                if(weight_arr[i][k] + weight_arr[k][j] < weight_arr[i][j])
                    weight_arr[i][j] = weight_arr[i][k] + weight_arr[k][j];
}

void print(){
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++)
            cout<<weight_arr[i][j]<<' ';
        cout<<'\n';
    }
}

void solve(){
    input();
    Floyd_Warshall();
    print();
}

int main(){
    solve();
    return 0;
}