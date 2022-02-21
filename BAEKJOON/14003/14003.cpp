#include<iostream>
#include<vector>
using namespace std;

int N;
vector<long long> A, idx, ans;


void f(){
    int cnt=0;
    for(int i=0;i<N;i++){
        cin>>A[i];
        
        auto pos = lower_bound(ans[1], ans[cnt+1], A[i]);
        *pos = A[i];
        idx[i] = distance(A, pos);
    }
}

void solve(){
    cin>>N;
    
}

int main(){
    return 0;
}