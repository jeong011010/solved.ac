#include <string>
#include <vector>
#include <queue>
using namespace std;

int arr[51][51], cX, cY, iX, iY, ans=0;
int Xmove[4]={-1,1,0,0};
int Ymove[4]={0,0,-1,1};
vector<vector<int>> r;

void setmap(){
    for(int i=0;i<r.size();i++){
        for(int j=r[i][0]+1;j<r[i][2]-1;j++)
            for(int k=r[i][1]+1;k<r[i][3]-1;k++)
                arr[k][j]=2;
        for(int j=r[i][0];j<r[i][2];j++){
            if(arr[r[i][1]][j]!=2)
                arr[r[i][1]][j]=1;
            if(arr[r[i][3]][j]!=2)
                arr[r[i][3]][j]=1;
        }
        for(int j=r[i][1];j<r[i][3];j++){
            if(arr[j][r[i][1]]!=2)
                arr[j][r[i][1]]=1;
            if(arr[j][r[i][3]]!=2)
                arr[j][r[i][3]]=1;
        }
            
    }
    arr[cY][cX]=3;
}

void bfs(){
    queue<pair<int,int>> q;
    q.push({cY,cX});
    while(!q.empty()){
        int y=q.front().first;
        int x=q.front().second;
        q.pop();
        if(x==iX&&y==iY){
            return;
        }
        for(int i=0;i<4;i++){
            if(arr[y+Ymove[i]][x+Xmove[i]]==1){
                arr[y][x]=3;
                q.push({y+Ymove[i],x+Xmove[i]});
            }
        }
        ans++;
        
    }
}


int solution(vector<vector<int>> rectangle, int characterX, int characterY, int itemX, int itemY) {
    r=rectangle;
    setmap();
    bfs();
    return ans/2;
    
}