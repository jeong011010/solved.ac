#include<iostream>
using namespace std;

int N;
int arr[100001][2];
int index[100001];

void input(){
    cin>>N;
    for(int i=1;i<=N;i++){
        cin>>arr[i][0];
        index[arr[i][0]]=i;
    }
    for(int i=1;i<=N;i++)
        cin>>arr[i][1];
}

void dac(int start, int end, int poststart, int postend){
    

    int tmp = arr[end][1];
    if(start>end||poststart>postend){return;}
    int rooti = index[arr[postend][1]];
    int left = rooti - start;
    int right = end - rooti;
    cout<<arr[rooti][0]<<' ';
    dac(start,rooti-1,poststart,poststart+left-1);
    dac(rooti+1,end,poststart+left,postend-1);
}

void solve(){
    input();
    dac(1,N,1,N);
}

int main(){
    solve();
    return 0;
}