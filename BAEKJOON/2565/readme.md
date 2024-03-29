# 2565 전깃줄
------------
### 문제

>두 전봇대 A와 B 사이에 하나 둘씩 전깃줄을 추가하다 보니 전깃줄이 서로 교차하는 경우가 발생하였다. 합선의 위험이 있어 이들 중 몇 개의 전깃줄을 없애 전깃줄이 교차하지 않도록 만들려고 한다.
>
>예를 들어, < 그림 1 >과 같이 전깃줄이 연결되어 있는 경우 A의 1번 위치와 B의 8번 위치를 잇는 전깃줄, A의 3번 위치와 B의 9번 위치를 잇는 전깃줄, A의 4번 위치와 B의 1번 위치를 잇는 전깃줄을 없애면 남아있는 모든 전깃줄이 서로 교차하지 않게 된다
>
>
>
>전깃줄이 전봇대에 연결되는 위치는 전봇대 위에서부터 차례대로 번호가 매겨진다. 전깃줄의 개수와 전깃줄들이 두 전봇대에 연결되는 위치의 번호가 주어질 때, 남아있는 모든 전깃줄이 서로 교차하지 않게 하기 위해 없애야 하는 전깃줄의 최소 개수를 구하는 프로그램을 작성하시오
>
>입력
첫째 줄에는 두 전봇대 사이의 전깃줄의 개수가 주어진다. 전깃줄의 개수는 100 이하의 자연수이다. 둘째 줄부터 한 줄에 하나씩 전깃줄이 A전봇대와 연결되는 위치의 번호와 B전봇대와 연결되는 위치의 번호가 차례로 주어진다. 위치의 번호는 500 이하의 자연수이고, 같은 위치에 두 개 이상의 전깃줄이 연결될 수 없다
>
>출력
첫째 줄에 남아있는 모든 전깃줄이 서로 교차하지 않게 하기 위해 없애야 하는 전깃줄의 최소 개수를 출력한다
>
### 아이디어 
----------
dp 문제이다.
생각을 많이 해봐야 풀 수 있는 문제이다.

점화식을 어떻게 구상해야 할 지 굉장히 어려운 문제이다.
우측 전봇대에 연결된 전깃줄을 봤을 때, 좌측 전봇대에 연결된 순서대로
우측 전봇대에 연결된 공간을 정렬해주면 대충 감이 온다.

생각을 해보자.
만약 겹쳐있지 않으려면 좌측 전봇대 순서대로 정렬을 했을 때
우측 전봇대에서도 정렬이 될 것이다. 겹치지 않으니까.

근데 겹쳐있으면 정렬이 안되겠지?

그래서 좌측 전봇대 기준으로 우측 전봇대를 정렬했을 때 가장 많은 수가 정렬되는 전깃줄의 개수를 총 전깃줄의 개수에서 빼주면
빼줘야 하는 전깃줄의 개수가 나온다.

vector<pair<int,int>> Line에 좌측 우측으로 전깃줄을 넣어주고
sort를 해주면 좌측 전깃줄 기준으로 정렬이 된다.

dp[i]를 전부 1로 초기화해주고,
for문을 돌리면서 j에서 i까지 Line[i].second보다 작은 Line[j].second가 있다면
dp[i]와 dp[j]+1중 큰것을 dp[i]에 넣어준다.

이후 n에서 dp[]중 최댓값을 빼준다.

### 오답노트
----------