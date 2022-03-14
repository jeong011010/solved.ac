# 1987 알파벳
------------
### 문제

>세로 R칸, 가로 C칸으로 된 표 모양의 보드가 있다. 보드의 각 칸에는 대문자 알파벳이 하나씩 적혀 있고, 좌측 상단 칸 (1행 1열) 에는 말이 놓여 있다.
>
>말은 상하좌우로 인접한 네 칸 중의 한 칸으로 이동할 수 있는데, 새로 이동한 칸에 적혀 있는 알파벳은 지금까지 지나온 모든 칸에 적혀 있는 알파벳과는 달라야 한다. 즉, 같은 알파벳이 적힌 칸을 두 번 지날 수 없다.
>
>좌측 상단에서 시작해서, 말이 최대한 몇 칸을 지날 수 있는지를 구하는 프로그램을 작성하시오. 말이 지나는 칸은 좌측 상단의 칸도 포함된다.

### 아이디어 
----------
위 문제는 dfs로 풀 수 있었다.

문제에서 원하는 것은 시작지점에서 갈 수 있는 최대한의 거리이기 때문에 전부 탐색해야 한다. 그러므로 bfs가 아닌 dfs를 사용했다.

재귀 함수와 bool 배열 매개변수를 이용하여 방문하지 않은 곳이라면 체크하고 재귀호출 하는 방향으로 구현하였다.

### 오답노트
----------