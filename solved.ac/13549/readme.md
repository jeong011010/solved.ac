# 13549 숨바꼭질 3
------------
### 문제

>수빈이는 동생과 숨바꼭질을 하고 있다. 수빈이는 현재 점 N(0 ≤ N ≤ 100,000)에 있고, 동생은 점 K(0 ≤ K ≤ 100,000)에 있다. 수빈이는 걷거나 순간이동을 할 수 있다. 만약, 수빈이의 위치가 X일 때 걷는다면 1초 후에 X-1 또는 X+1로 이동하게 된다. 순간이동을 하는 경우에는 0초 후에 2*X의 위치로 이동하게 된다.
>
>수빈이와 동생의 위치가 주어졌을 때, 수빈이가 동생을 찾을 수 있는 가장 빠른 시간이 몇 초 후인지 구하는 프로그램을 작성하시오.

### 아이디어
----------
위 문제는 dfs로 간단하게 풀 수 있었다.

N에서 K로 가는 과정 중 1(+,-) 또는 0(*2)를 사용하여 가장 적게 드는 과정을 찾는 문제다.
그렇기 때문에 queue<pair<현재 위치, 소모 값>>으로 선언한다. (q<pair<x,t>>)

이후 bfs를 실행한다.
bfs는 아래와 같이 구현하였다.

> 우선 q에 시작지점 N과 0을 push 후 q가 빌때까지 while문을 실행한다.
>
> q<pair<x,t>>했을 때.
> 
> 시간복잡도를 줄이기 위해 bool배열을 선언하여 check[x] = true를 해준다. 
> 
> x가 k보다 클 경우 빼기 이외의 연산은 쓸모 없으므로 빼기만 실행해준다.
> 모든 +,-,* 연산은 check[x+1,-1,*2] 확인과, 답이 한번 나왔는지 체크하는 bool 함수를 확인한다.
>> 답이 한번 나왔는지 체크하는 이유는, 답이 나오자마자 while문을 멈출 시 더 적은 값이 나오지 않을 수 있다.
>> ex) 1,2 의 경우 1+1(1초)과 1*2(0초)인데 1초가 나오는 경우가 생김
>> 그렇기 때문에 답이 나왔을 때 남은 queue까지만 돌리고 더이상 push하지 않는 방향으로 구현 하였다.

### 오답노트
----------
처음에는 q가 빌때까지 실행하게 하였더니 모든 배열 index (100001)를 전부 확인하고나서야 프로그램이 끝나는 대참사가 벌어졌다.

그래서 if(x==K)일 때 바로 출력 후 return을 했더니

ex) 1,2 의 경우 1+1(1초)과 1*2(0초)인데 1초가 나오는 경우가 생겼다.

그래서 생각해낸 해결책으로 답이 나왔을 때의 queue에 저장된 값 까지만 계산하고 더이상 push하지 않는 방향으로 구현하였더니 성공하였다.