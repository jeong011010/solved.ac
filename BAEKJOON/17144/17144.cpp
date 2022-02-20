#include<iostream>
#include<stack>
#include<algorithm>
using namespace std;

int house[53][53];
int air_p; // 공기청정기의 아랫부분 위치
int Xmove[4] = {1,0,-1,0};
int Ymove[4] = {0,-1,0,1};

int R,C,T,ans=0;

void input(){
    cin>>R>>C>>T;
    int tmp;
    for(int i=1;i<=R;i++)
        for(int j=1;j<=C;j++){
            cin>>tmp;
            house[i][j] = tmp;
            if(tmp==-1) air_p=i;
        }
    for(int i=0;i<=R+1;i++)house[i][0]=house[i][C+1]=-1;
    for(int i=0;i<=C+1;i++)house[0][i]=house[R+1][i]=-1;    
}

void down(int a, int b, int y){
    for(int i=a;i>b;i--){
        if(house[i][y]==-1)
            house[i-1][y]=0;
        else
            house[i][y]=house[i-1][y];
    }
}
void left(int a, int b, int x){
    for(int i=a;i<b;i++){
        house[x][i]=house[x][i+1];
    }
}
void up(int a, int b, int y){
    for(int i=a;i<b;i++){
        if(house[i][y]==-1)
            house[i+1][y]=0;
        else
            house[i][y]=house[i+1][y];
    }
}
void right(int a, int b, int x){
    for(int i=a;i>b;i--){
        house[x][i]=house[x][i-1];
    }
    house[x][b]=0;
}

void AirMove(){
    //위
    int x=air_p-1;
    down(x,1,1);
    left(1,C,1);
    up(1,x,C);
    right(C,2,x);

    //아래
    x=air_p;
    up(x,R,1);
    left(1,C,R);
    down(R,x,C);
    right(C,2,x);
}

void DustMove(){
    int tmp[53][53]={0,};
    for(int X=1;X<=R;X++)
        for(int Y=1;Y<=C;Y++){    
            if(house[X][Y]>4){
                int cnt=0;
                int dustw = house[X][Y]/5;
                for(int i=0;i<4;i++){
                    int dX=X+Xmove[i], dY=Y+Ymove[i];
                    if(house[dX][dY]!=-1){
                        tmp[dX][dY]+=dustw;
                        cnt++;
                    }
                    
                }
                tmp[X][Y]+=house[X][Y]-(dustw*cnt);
            }
            else if(house[X][Y]<5)
                tmp[X][Y]+=house[X][Y];
        }
    for(int i=1;i<=R;i++)
        for(int j=1;j<=C;j++)
            house[i][j]=tmp[i][j];
    
}

void print(){
    ans=0;
    for(int i=0;i<=R+1;i++){
        for(int j=0;j<=C+1;j++){
            if(house[i][j]>0) ans+=house[i][j];
            //cout<<house[i][j]<<' ';
        }
        //cout<<'\n';
    }
    cout<<ans<<'\n';
}

void solve(){
    input();
    for(int i=0;i<T;i++){
        DustMove();
        AirMove();
    }
    print();
}

int main(){
    solve();
    return 0;
}