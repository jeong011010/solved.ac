#include<iostream>
using namespace std;

int N, arr[129][129], ans_w=0, ans_b=0;


void input() {
  cin>>N;
  for(int i=0;i<N;i++) {
    for(int j=0;j<N;j++) {
      cin>>arr[i][j];
    }
  }
}

void isfull(int i, int j, int n) {
  for(int a=i;a<i+n;a++) {
    for(int b=j;b<j+n;b++) {
      if(arr[a][b]!=arr[i][j]) {
        isfull(i,j,n/2);
        isfull(i+n/2,j,n/2);
        isfull(i,j+n/2,n/2);
        isfull(i+n/2,j+n/2,n/2);
        return;
      }
    }
  }
    if(arr[i][j]==1) {ans_b++;}
    else {ans_w++;}
}

int main(){
  input();
  isfull(0,0,N);
  cout<<ans_w<<"\n"<<ans_b;
}

