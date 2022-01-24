# 9663 N-Queen
------------
### 문제

>N-Queen 문제는 크기가 N × N인 체스판 위에 퀸 N개를 서로 공격할 수 없게 놓는 문제이다.  
> 
>N이 주어졌을 때, 퀸을 놓는 방법의 수를 구하는 프로그램을 작성하시오.
>
>첫째 줄에 N이 주어진다. (1 ≤ N < 15)

### 아이디어
----------
위 문제는 Brute Force 알고리즘을 사용하여 풀 수 있다.

아래 기술하는 문제 풀이는 [여기](https://ko.wikipedia.org/wiki/%EC%97%AC%EB%8D%9F_%ED%80%B8_%EB%AC%B8%EC%A0%9C)를 참고했다.

1. board 배열을 선언하여, index를 행 값을 열로 취급한다.  
2. check(int y) 함수(해당 문서에서는 path())를 선언한다.  
    - y(현재 배치된 퀸 개수)가 n과 같다면 보드를 꽉 채운것으로 정답 경우 ans++를 해준다.  
    - 이중 포문을 돌리는데 i는 열, j(y보다 적을 때 까지)는 행을 뜻한다.  
        - board[j]가 i와 같다면 이미 해당 열에 퀸이 있으므로 break  
        - 또는 y-j가 i-board[j]와 같다면 대각선에 퀸이 있으므로 break  
    - 위 포문을 전부 통과한다면 board[y]=i; check(y+1);를 해준다.
3. 이후 ans를 출력한다.

2번의 이중 포문은 다음과 같다.
```c++
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
```

### 오답노트
----------
코드는 매우 간단하게 짤 수 있는 프로그램인데 설계가 굉장히 어려웠다.
이런 수학적 문제가 코테에 나왔을 때 과연 내가 시간안에 풀 수 있을까..?
brute-force, dynamic-programming 다양하게 문제를 풀어봐야한다.