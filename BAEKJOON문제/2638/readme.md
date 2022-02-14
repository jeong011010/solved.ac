# 2638 치즈
------------
### 문제

>N×M (5≤N, M≤100)의 모눈종이 위에 아주 얇은 치즈가 <그림 1>과 같이 표시되어 있다. 단, N 은 세로 격자의 수이고, M 은 가로 격자의 수이다. 이 치즈는 냉동 보관을 해야만 하는데 실내온도에 내어놓으면 공기와 접촉하여 천천히 녹는다. 그런데 이러한 모눈종이 모양의 치즈에서 각 치즈 격자(작 은 정사각형 모양)의 4변 중에서 적어도 2변 이상이 실내온도의 공기와 접촉한 것은 정확히 한시간만에 녹아 없어져 버린다. 따라서 아래 <그림 1> 모양과 같은 치즈(회색으로 표시된 부분)라면 C로 표시된 모든 치즈 격자는 한 시간 후에 사라진다.
>
><img width="60%" src="https://upload.acmicpc.net/a4998beb-104c-4e37-b3d7-fd91cd81464a/-/preview/"/>
><그림 1>
> 
><그림 2>와 같이 치즈 내부에 있는 공간은 치즈 외부 공기와 접촉하지 않는 것으로 가정한다. 그러므 로 이 공간에 접촉한 치즈 격자는 녹지 않고 C로 표시된 치즈 격자만 사라진다. 그러나 한 시간 후, 이 공간으로 외부공기가 유입되면 <그림 3>에서와 같이 C로 표시된 치즈 격자들이 사라지게 된다.
>
><img width="60%" src="https://upload.acmicpc.net/e5d519ee-53ea-40a6-b970-710cca0db128/-/preview/"/>
><그림 2>
><img width="60%" src="https://upload.acmicpc.net/a00b876a-86dc-4a82-a030-603a9b1593cc/-/preview/"/>
><그림 3>
> 
>모눈종이의 맨 가장자리에는 치즈가 놓이지 않는 것으로 가정한다. 입력으로 주어진 치즈가 모두 녹아 없어지는데 걸리는 정확한 시간을 구하는 프로그램을 작성하시오.
### 아이디어
----------
위 문제는 DFS를 사용하여 풀 수 있었다.
내가 구현한 DFS 함수 구조는 다음과 같다.

- 우선 모눈종이의 맨 가장자리에 치즈가 놓이지 않는 점을 착안하여 1,1은 항상 0이므로 dfs함수 stack의 시작을 1,1로 잡았다.
- 현재 위치의 상하좌우를 살피므로 배열 범위 외의 index를 조회 시 오류가 발생할 수 있으므로 테두리를 -1로 둘렀다.
- stack이 비어있을 때 까지 아래 내용을 반복해준다.
    1. 현재 노드를 방문하지 않았을 시 방문 체크를 한 뒤, 2번으로 간다. 아닐 시 continue;
    2. 상하좌우를 봐준다.
        1. 0일 시 stack에 push 해준다.
        2. 1일 시 1을 더해준다. (공기에 몇 면이 닿았는지 확인하기 위함)
- 이후 count를 더해주고 check를 초기화해준다.

또한 arr 배열 상황을 체크하는 check() 함수도 구현하였다

- 값에 1이 있을 시 0으로 만든다.
- 값에 2 이상이 있을 시 1로 만들고 false 반환
- 아닐 시 true 반환.

하여 while(!check()) dfs();
로 dfs 함수를 실행해준다.

아래는 구현한 dfs 함수와 check 함수이다.

dfs()
```c++
void dfs(){
    bool check[101][101] = {false};
    
    stack<pair<int,int>> s;
    s.push(make_pair(1,1));

    while(!s.empty()){       
        int y=s.top().first;
        int x=s.top().second;
        s.pop();
        if(check[y][x]==false){        
            check[y][x]=true;

            for(int i=0;i<4;i++){
                int my = y+yMove[i];
                int mx = x+xMove[i];
                if(!check[my][mx]){
                    if(arr[my][mx]==0){
                        s.push(make_pair(my,mx));
                    }
                    else if(arr[my][mx]>0){
                        arr[my][mx]++;
                    }
                }
            }
        }
    }  
    count++;
}
```

check()
```c++
bool check(){
    bool e = true;
    for(int i=1;i<=N;i++){
        for(int j=1;j<=M;j++){
            if(arr[i][j]>2) {arr[i][j]=0;}
            else if(arr[i][j]>0) {arr[i][j]=1;e=false;}
            //cout<<arr[i][j];
        }
        //cout<<'\n';
    }
    //cout<<'\n';
    return e;
}
```

### 오답노트
----------
없다. 원트에 성공