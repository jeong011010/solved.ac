# 7562 나이트의 이동
------------
### 문제

>체스판 위에 한 나이트가 놓여져 있다. 나이트가 한 번에 이동할 수 있는 칸은 아래 그림에 나와있다. 나이트가 이동하려고 하는 칸이 주어진다. 나이트는 몇 번 움직이면 이 칸으로 이동할 수 있을까?
> <img src="https://www.acmicpc.net/upload/images/knight.png" width="30%"/>

### 아이디어 
----------
위 문제는 bfs 알고리즘을 이용하여 풀 수 있었다.

시작지점에서 나이트의 특성을 통해 목적지로 갈 수 있는 최소거리를 구하는 문제이다.  
그렇기에 dfs가 아닌 bfs를 사용하는것이 효율적이다.  

시작지점을 queue에 넣은 뒤, bfs를 돌리며 목적지와 좌표가 동일하다면 해당 queue에 들어있는 인수인 cnt를 출력해준다.  
bfs를 진행하며 push가 될 때 마다 해당 cnt 인수에 +1를 해준다.

### 오답노트
----------