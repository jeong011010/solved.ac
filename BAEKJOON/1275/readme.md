# 1275 커피숍2
------------
### 문제

>모두 알다시피 동호는 커피숍의 마담이다. (마담이 무엇인지는 본인에게 물어보도록 하자.)
>
>어느 날 커피숍의 손님 A씨가 동호에게 게임을 하자고 했다.
>
>그 게임은 다음과 같은 규칙을 갖는다.
>
>N개의 정수가 있으면, 동호는 다음과 같이 말한다. “3~7번째 수의 합은 무엇이죠?” 그러면 상대방은 “그 답은 000입니다. 그리고 8번째 수를 2로 고치도록 하죠” 그러면 동호는 “네 알겠습니다.”라고 한 뒤에 다시 상대방이 동호가 했던 것처럼 “8~9번째 수의 합은 무엇이죠?”라고 묻게된다. 이 것을 번갈아 가면서 반복하는 게임이다.
>
>당신은 이 게임의 심판 역을 맡았다. 요컨대, 질문에 대한 답들을 미리 알아야 한다는 것이다.
>
>당신의 머리가 출중하다면 10만개 가량 되는 정수와 10만턴 정도 되는 게임을 기억할 수 있을 것이다. 몇판 이 게임을 즐기던 동호는 많은 사람들이 이 게임을 하기를 바라게 되었고, 당신에게 심판 프로그램을 구현해달라고 요청했다.
>
>입력
>첫째 줄에 수의 개수 N과 턴의 개수 Q가 주어진다.(1 ≤ N, Q ≤ 100,000) 둘째 줄에는 처음 배열에 들어가 있는 정수 N개가 주어진다. 세 번째 줄에서 Q+2번째 줄까지는 x y a b의 형식으로 x~y까지의 합을 구하여라, a번째 수를 b로 바꾸어라 라는 뜻의 데이터가 주어진다.
>
>입력되는 모든 수는 -231보다 크거나 같고, 231-1보다 작거나 같은 정수이다.
>
>출력
한 턴마다 구한 합을 한 줄마다 한 개씩 출력한다.



### 아이디어 
----------
세그먼트 트리 문제.

세그먼트 트리란 부분수열의 합을 구할 때 가장 빠르게 구할 수 있는 알고리즘이다.
수의 합을 트리로 구현해둔건데,

n번 노드가 a~b번의 합이라면

n*2 노드는 a ~ (a+b)/2의 합이고

n*2+1 노드는 (a+b)/2+1 ~ b의 합이다

이렇게 하면 원하는 부분수열의 합을 구하기 쉬운데,
세그먼트 트리를 만들어주는 init함수,
합을 구해주는 sum함수
값을 갱신해주는 update 함수를 전부 구현할 수 있어야한다.


### 오답노트
----------

합의 값이 int범위를 초과할 수 있는데 longlong으로 바꾼줄 알고있었다.
그리고 시간초과나서 \n이랑 cintie처리 다해줬다.