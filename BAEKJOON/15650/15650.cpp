#include<iostream>
using namespace std;

int N,M;
int arr[9];
bool check[9];

void f(int n, int cnt){
    if(cnt == M)
    {
        for(int i=0;i<M;i++)
            cout<<arr[i]<<' ';
        cout<<'\n';
        return;
    }
    for(int i=n;i<=N;i++){
        if(!check[i]){
            check[i]=true;
            arr[cnt] = i;
            f(i+1,cnt+1);
            check[i]=false;
        }
    }
}

void solve(){
    cin>>N>>M;
    f(1,0);
}

int main(){
    solve();
    return 0;
}