# 1967번 트리의 지름
------------
### 문제

>트리(tree)는 사이클이 없는 무방향 그래프이다. 트리에서는 어떤 두 노드를 선택해도 둘 사이에 경로가 항상 하나만 존재하게 된다. 트리에서 어떤 두 노드를 선택해서 양쪽으로 쫙 당길 때, 가장 길게 늘어나는 경우가 있을 것이다. 이럴 때 트리의 모든 노드들은 이 두 노드를 지름의 끝 점으로 하는 원 안에 들어가게 된다.
>
><img width="40%" src="https://www.acmicpc.net/JudgeOnline/upload/201007/ttrrtrtr.png"/>
>
>이런 두 노드 사이의 경로의 길이를 트리의 지름이라고 한다. 정확히 정의하자면 트리에 존재하는 모든 경로들 중에서 가장 긴 것의 길이를 말한다. 
>
>입력으로 루트가 있는 트리를 가중치가 있는 간선들로 줄 때, 트리의 지름을 구해서 출력하는 프로그램을 작성하시오. 아래와 같은 트리가 주어진다면 트리의 지름은 45가 된다.
>
><img width="40%" src="https://www.acmicpc.net/JudgeOnline/upload/201007/tttttt.png"/>
>
>트리의 노드는 1부터 n까지 번호가 매겨져 있다.

### 아이디어
----------
위 문제는 DFS 알고리즘을 이용하여 푸는 문제이다. 트리의 정점과 정점의 길이가 가장 큰 것을 찾는 문제이다.

해당 문제를 DFS로 풀다가 다익스트라가 훨씬 간편할 것 같아서 Dijkstra 연습하는김에 구현하였다.

다익스트라를 통해 문제를 푸는 방법이다.
1. Dijkstra 함수를 정점 1에서 시작한 뒤, 가장 길이가 큰 정점을 구한다.
2. 해당 정점에서 Dijkstra를 다시 한번 실행한다.
3. 2에서 나온 길이가 정답이다.

### 오답노트
----------
- 없다. 원트요^^
- DFS로도 풀어봐야겠다. 근데 어케푸냐