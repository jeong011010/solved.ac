#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int n;
int b[11][10];
int v[11][10]={0};
int result=0;
int r[2]={0};

int dx[4]={1,1,-1,-1};
int dy[4]={-1,1,1,-1};

//-1 비숍
//0 빈자리
//1 못놓는자리

bool check(int x, int y, int res[][10]){
    for(int i=1; i<n; i++){
        for(int j=0; j<4; j++){
            int nx = x + dx[j]*i;
            int ny = y + dy[j]*i;
            if(nx>=0 && ny>=0 && nx < n && ny < n){
                if(res[nx][ny]==-1){
                    return false;
                }
            }
        }
    }
    return true;
}

void bt(int x, int y, int res[][10], int c, int k, vector<pair<int, int>> a){
    if(x==n){ // x가 최대라면
        r[k] = max(r[k], c);
        return ;
    }
    if(y==n-1) bt(x+1,0,res,c,k,a);
    else bt(x,y+1,res,c,k,a);


    if(res[x][y]==0) return ;
    if(v[x][y]==k) return ;

    if(check(x,y,res)){
        res[x][y]=-1;
        a.push_back({x,y});
        if(y==n-1) bt(x+1,0,res,c+1,k,a);
        else bt(x,y+1,res,c+1,k,a);
        res[x][y]=1;
        a.pop_back();
    }
    return ;
}

int main()
{
    cin >> n;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin>>b[i][j]; //0은 검은칸
            if((i+j)%2==0) v[i][j]=1; //1은 흰칸
        }
    }
    vector<pair<int, int>> a;
    bt(0,0,b,0,0,a);
    bt(0,0,b,0,1,a);
    cout << r[0]+r[1];
    return 0;
}