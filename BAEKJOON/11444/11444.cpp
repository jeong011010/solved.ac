#include<iostream>
using namespace std;

int arr[3];
long long n;

void solve(){
    cin>>n;
    arr[0]=0;
    arr[1]=1;
    for(long long i=1;i<n;i++){
        arr[2]=(arr[0]+arr[1])%1000000007;
        arr[0]=arr[1];
        arr[1]=arr[2];
    }
    cout<<arr[2];
}

int main(){
    solve();
    return 0;
}