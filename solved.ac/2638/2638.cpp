#include<iostream>
#include<queue>
using namespace std;

bool arr[100][100];
int N,M;

void input(){
    cin>>N>>M;
    for(int i=0;i<N;i++)
        for(int j=0;j<M;j++)
            cin>>arr[i][j];
}

void f(){

}

void solve(){
    input();
    f();
}

int main(){
    solve();
    return 0;
}