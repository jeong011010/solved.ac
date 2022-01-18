#include<iostream>
using namespace std;

char arr[3072][6143];
int N;

void draw(int r, int l){
    arr[r][l]='*';
    arr[r+1][l-1]=arr[r+1][l+1]='*';
    for(int i=0;i<5;i++)
        arr[r+2][l-2+i]='*';
}

void triangle(int len, int r, int l){
    if(len == 3){
        draw(r,l);
        return;
    }
    triangle(len/2,r,l);
    triangle(len/2,r+len/2,l-len/2);
    triangle(len/2,r+len/2,l+len/2);
}

void solve(){
    cin>>N;
    for(int i=0;i<N;i++)
        for(int j=0;j<2*N-1;j++)
            arr[i][j]=' ';
    triangle(N,0,N-1);
    for(int i=0;i<N;i++){
        for(int j=0;j<2*N-1;j++){
            cout<<arr[i][j];
        }
        cout<<'\n';
    }
}

int main(){
    solve();
    return 0;
}