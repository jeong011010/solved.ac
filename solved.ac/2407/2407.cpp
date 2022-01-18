#include<iostream>
#include<string>
using namespace std;

double N,M;
__uint128_t DP[100];

void input(){
    cin>>N>>M;
    int tmp;
    if(M>N/2) {
        tmp=N-M;
        M=tmp;
    }
}

void print(){
    __uint128_t tmp=DP[(int)M-1];
    string s="";
    while(tmp>0){
        s+= tmp%10;
        tmp/=10;
    }
    for(int i=s.size();i>=0;i--)
        cout<<s[i];
}

void f(){
    DP[0]=N/M;
    for(int i=1;i<M;i++){
        DP[i]=DP[i-1]*((N-i)/(M-i));
    }
    cout<<(long long)DP[(int)M-1]<<'\n';
}

void solve(){
    input();
    f();
}

int main(){
    solve();
    return 0;
}