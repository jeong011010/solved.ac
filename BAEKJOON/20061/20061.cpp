// 시작 13:15 끝 20:49

#include<iostream>
using namespace std;

bool arr_green[7][4];
bool arr_blue[4][7];
int N, score=0;

void block(int t, int y, int x){
  int tmpx=0;
  int tmpy=0;
  if(t==1){ // 블럭 1x1
    // green area
    while(!arr_green[tmpy][x] && tmpy<6){ // 블럭을 만날 때 까지 내려가기
      tmpy++;
    }
    arr_green[tmpy-1][x]=true;
    //blue area
    while(!arr_blue[y][tmpx] && tmpx<6){ // 블럭을 만날 때 까지 내려가기
      tmpx++;
    }
    arr_blue[y][tmpx-1]=true;
  }
  else if(t==2){
    while(!arr_green[tmpy][x] && !arr_green[tmpy][x+1] && tmpy<6){ // 블럭을 만날 때 까지 내려가기
      tmpy++;
    }
    arr_green[tmpy-1][x]=arr_green[tmpy-1][x+1]=true;
    while(!arr_blue[y][tmpx+1] && tmpx+1<6){ // 블럭을 만날 때 까지 내려가기
      tmpx++;
    }
    arr_blue[y][tmpx-1]=arr_blue[y][tmpx]=true;
  }
  else if(t==3){
    while(!arr_green[tmpy+1][x] && tmpy+1<6){ // 블럭을 만날 때 까지 내려가기
      tmpy++;
    }
    arr_green[tmpy-1][x]=arr_green[tmpy][x]=true;
    while(!arr_blue[y][tmpx] && !arr_blue[y+1][tmpx] && tmpx<6){ // 블럭을 만날 때 까지 내려가기
      tmpx++;
    }
    arr_blue[y][tmpx-1]=arr_blue[y+1][tmpx-1]=true;
  }
  //cout<<"tmpy:"<<tmpy<<" tmpx:"<<tmpx<<endl;
  // green area 추가 동작

  int check=0, check2=0; // 꽉찼는지 체크
  for(int i=0;i<4;i++){
    if(arr_green[tmpy][i]) check++;
    if(arr_green[tmpy-1][i]) check2++;
  }

  //cout<<check<<' '<<check2<<endl;

  if(check==4) {
    check=0;
    score++; // 행 삭제후 점수 획득
    if(check2==4) { 
      check2=0;
      score++; // 행 삭제후 점수 획득
      for(int i=tmpy;i>0;i--){
        for(int j=0;j<4;j++){
          arr_green[i][j]=arr_green[i-1][j]; // 한칸씩 내리기
        }
      }
    }
    for(int i=tmpy;i>0;i--){
      for(int j=0;j<4;j++){
        arr_green[i][j]=arr_green[i-1][j]; // 한칸씩 내리기
      }
    }
  }
  if(check2==4) { 
    score++; // 행 삭제후 점수 획득
    for(int i=tmpy-1;i>0;i--){
      for(int j=0;j<4;j++){
        arr_green[i][j]=arr_green[i-1][j]; // 한칸씩 내리기
      }
    }
  }

  int tmp=0;
  for(int i=0;i<4;i++){
    if(arr_green[0][i]) {tmp=2; break;}
    if(arr_green[1][i]) tmp=1;
  } // 연한칸만큼 행 삭제
  for(int k=0;k<tmp;k++){
    for(int i=5;i>0;i--){
      for(int j=0;j<4;j++){
        arr_green[i][j]=arr_green[i-1][j];
        if(tmp==2&&i==1) arr_green[i-1][j]=0;
      }
    }
  }

  // blue area 추가 동작

  check=0, check2=0; // 꽉찼는지 체크
  for(int i=0;i<4;i++){
    if(arr_blue[i][tmpx]) check++;
    if(arr_blue[i][tmpx-1]) check2++;
  }

  //cout<<check<<' '<<check2<<endl;

  if(check==4) {
    check=0;
    score++; // 행 삭제후 점수 획득
    if(check2==4) { 
      check2=0;
      score++; // 행 삭제후 점수 획득
      for(int i=tmpx;i>0;i--){
        for(int j=0;j<4;j++){
          arr_blue[j][i]=arr_blue[j][i-1]; // 한칸씩 내리기
        }
      }
    }
    for(int i=tmpx;i>0;i--){
      for(int j=0;j<4;j++){
        arr_blue[j][i]=arr_blue[j][i-1]; // 한칸씩 내리기
      }
    }
  }
  if(check2==4) { 
    score++; // 행 삭제후 점수 획득
    for(int i=tmpx-1;i>0;i--){
      for(int j=0;j<4;j++){
        arr_blue[j][i]=arr_blue[j][i-1]; // 한칸씩 내리기
      }
    }
  }

  tmp=0;
  for(int i=0;i<4;i++){
    if(arr_blue[i][0]) {tmp=2; break;}
    if(arr_blue[i][1]) tmp=1;
  } // 연한칸만큼 행 삭제
  for(int k=0;k<tmp;k++){
    for(int i=5;i>0;i--){
      for(int j=0;j<4;j++){
        arr_blue[j][i]=arr_blue[j][i-1];
        if(tmp==2&&i==1) arr_blue[j][i-1]=0;
      }
    }
  }

  /*
  cout<<endl;
  for(int i=0;i<4;i++){
    cout<<"0 0 0 0 ";
    for(int j=0;j<6;j++){
      cout<<arr_blue[i][j]<<' ';
    }
    cout<<endl;
  }
  for(int i=0;i<6;i++){
    for(int j=0;j<4;j++){
      cout<<arr_green[i][j]<<' ';
    }
    cout<<endl;
  }
  */
}

void solve(){
  cin>>N;
  int t,y,x;
  for(int i=0;i<N;i++){
    cin>>t>>y>>x;
    block(t,y,x);
  }
  int check=0;
  for(int i=2;i<6;i++){
    for(int j=0;j<4;j++){
      if(arr_green[i][j]) check++;
      if(arr_blue[j][i]) check++;
    }
  }
  cout<<score<<endl<<check;

}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  solve();
  return 0;
}