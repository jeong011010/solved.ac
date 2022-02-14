#include<iostream>
#include<vector>
using namespace std;

vector<int> Arr[5], tmp[5];
int N,B;
int A[5][5];

void input(){
    cin>>N>>B;
    for(int i=0;i<N;i++)
        for(int j=0;j<N;j++)
            cin>>A[i][j];
}

void mul(vector<int> X[5], vector<int> Y[5]){
    vector<int> tmp[5];
    for(int i=0;i<N;i++)
        for(int j=0;j<N;j++){
            tmp[i][j]=0;
            for(int k=0;k<N;k++)
                tmp[i][j] += (X[i][k]*Y[k][j]);
            tmp[i][j] %= 1000;
        }
}

vector<int> fpow(vector<int> C, int n){
    if(n==1) return C;
    vector<int> x = fpow(C,n/2);
    if(n%2==0) return;
    else return;
}

void solve(){
    input();
    for(int i=0;i<B;i++){

    }
}

int main(){
    solve();
    return 0;
}