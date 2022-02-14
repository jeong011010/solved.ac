#include<iostream>
using namespace std;
#define INF 1e9+7

int N,M;
int weight_arr[100][100];

void input(){
    cin>>N>>M;
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++) 
            weight_arr[i][j]=INF;
    }
    int a,b,c;
    for(int i=0;i<M;i++) {
        cin>>a>>b>>c;
        if(weight_arr[a-1][b-1]>c)
            weight_arr[a-1][b-1]=c;
    }
}

void Floyd_Warshall(){
    for(int k=0;k<N;k++)
        for(int i=0;i<N;i++)
            for(int j=0;j<N;j++)
                if(weight_arr[i][k] + weight_arr[k][j] < weight_arr[i][j])
                    weight_arr[i][j] = weight_arr[i][k] + weight_arr[k][j];
}

void print(){
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            if(weight_arr[i][j]==INF||i==j)
                cout<<"0 ";
            else
                cout<<weight_arr[i][j]<<' ';
            }
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