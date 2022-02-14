#include<iostream>
#include<stack>
using namespace std;

int N, ans=0;
int board[15];

void check(int y){
    int ko;
    if(y==N){
        ans++;
        return;
    }
    for(int i=0;i<N;i++){
        ko=1;
        for(int j=0;j<y;j++){
            if(board[j]==i||abs(y-j)==abs(i-board[j])){
                ko=0;
                break;
            }
        }
        if(ko){
            board[y]=i;
            check(y+1);
        }
    }

}

void solve(){
    cin>>N;
    check(0);
    cout<<ans;
}

int main(){
    solve();
    return 0;
}