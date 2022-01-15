#include<iostream>
#include<vector>
using namespace std;

typedef struct tree{
    bool check;
    char key;
    int left, right;
}tree;
tree t[27];

int N;

void input(){
    cin>>N;
    char n,l,r;
    for(int i=0;i<N;i++){
        cin>>n>>l>>r;
        t[n-65].key = n;
        if(l=='.')
            t[n-65].left = 0;
        else
            t[n-65].left = l-65;
        if(r=='.')
            t[n-65].right = 0;
        else
            t[n-65].right = r-65;
    }
}

void OrderTraversal(int n, int mode){
    if(!t[n].check){
        if(mode==1)cout<<t[n].key;
        t[n].check = true;
        if(t[n].left!=0) OrderTraversal(t[n].left, mode);
        if(mode==2)cout<<t[n].key;
        if(t[n].right!=0) OrderTraversal(t[n].right, mode);    
        if(mode==3)cout<<t[n].key;    
    }
    return;
}

void f(){
    for(int i=1;i<4;i++){
        for(int i=0;i<27;i++) t[i].check=false;
        OrderTraversal(0,i);
        cout<<'\n';
    }
}

void solve(){
    input();
    f();
}

int main(){
    solve();
    return 0;
}