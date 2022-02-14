#include <iostream>
#include <string>
#include <vector>
#include <queue>
using namespace std;

int arr[51][51], cX, cY, iX, iY;
int Xmove[4]={0,1,0,-1};
int Ymove[4]={-1,0,1,0};
vector<vector<int>> r;

void setpoint(int x, int y){
    if(arr[x][y]==0)
        arr[x][y]=1;
    else if(arr[x][y]==1)
        arr[x][y]=2;
}

void setmap(){
    for(int i=0;i<r.size();i++){
        for(int j=r[i][0]+1;j<r[i][2];j++)
            for(int k=r[i][1]+1;k<r[i][3];k++)
                arr[k][j]=9;
        
        if(arr[r[i][1]][r[i][0]]!=9) arr[r[i][1]][r[i][0]]=2;
        if(arr[r[i][1]][r[i][2]]!=9) arr[r[i][1]][r[i][2]]=2;
        if(arr[r[i][3]][r[i][0]]!=9) arr[r[i][3]][r[i][0]]=2;
        if(arr[r[i][3]][r[i][2]]!=9) arr[r[i][3]][r[i][2]]=2;
        
        
        for(int j=r[i][0];j<=r[i][2];j++){
            setpoint(r[i][1],j);
            setpoint(r[i][3],j);
        }
        for(int j=r[i][1];j<=r[i][3];j++){
            setpoint(j,r[i][0]);
            setpoint(j,r[i][2]);
        }            
    }
    arr[cY][cX]=3;
    for(int i=0;i<20;i++){
        for(int j=0;j<20;j++){
            cout<<arr[i][j];
        }
        cout<<'\n';
    }
}

typedef struct point{
   int y,x,m,c; 
}p;

int bfs(){
    queue<p> q;
    q.push({cY,cX,0,0});
    while(!q.empty()){
        p tmp = q.front();
        
        q.pop();
        if(tmp.x==iX&&tmp.y==iY){
            return tmp.c;
        }
        switch (arr[tmp.y][tmp.x]){
            case 1:
                q.push({tmp.y+Ymove[tmp.m],tmp.x+Xmove[tmp.m],tmp.m,tmp.c+1});
                break;
            case 2:
                if(tmp.m==0||tmp.m==2){
                    for(int i=0;i<2;i++){
                        if(arr[tmp.y+Ymove[i*2+1]][tmp.x+Xmove[i*2+1]]!=9){
                            q.push({tmp.y+Ymove[i*2+1],tmp.x+Xmove[i*2+1],i*2+1,tmp.c+1});
                        }
                    }
                }
                if(tmp.m==1||tmp.m==3){
                    for(int i=0;i<2;i++){
                        if(arr[tmp.y+Ymove[i*2]][tmp.x+Xmove[i*2]]!=9){
                            q.push({tmp.y+Ymove[i*2],tmp.x+Xmove[i*2],i*2,tmp.c+1});
                        }
                    }
                }
                break;
            case 3:
                for(int i=0;i<4;i++){
                    if(arr[tmp.y+Ymove[i]][tmp.x+Xmove[i]]!=9){
                        q.push({tmp.y+Ymove[i],tmp.x+Xmove[i],i,tmp.c+1});
                    }
                }
                break;
        }
    }
}


int solution(vector<vector<int>> rectangle, int characterX, int characterY, int itemX, int itemY) {
    cY=characterY;
    cX=characterX;
    iX=itemX;
    iY=itemY;
    r=rectangle;
    setmap();
    return bfs();
}