# 2331 반복수열
------------
### 문제

>다음과 같이 정의된 수열이 있다.
>
>- D[1] = A
>- D[n] = D[n-1]의 각 자리의 숫자를 P번 곱한 수들의 합
>예를 들어 A=57, P=2일 때, 수열 D는 [57, 74(=52+72=25+49), 65, 61, 37, 58, 89, 145, 42, 20, 4, 16, 37, …]이 된다. 그 뒤에는 앞서 나온 수들(57부터가 아니라 58부터)이 반복된다.
>
>이와 같은 수열을 계속 구하다 보면 언젠가 이와 같은 반복수열이 된다. 이때, 반복되는 부분을 제외했을 때, 수열에 남게 되는 수들의 개수를 구하는 프로그램을 작성하시오. 위의 예에서는 [57, 74, 65, 61]의 네 개의 수가 남게 된다.

### 아이디어 
----------
위 문제는 간단한 구현 문제인 것 같긴 하다.

나는 배열 하나 만들어서 문제에서 주어진 계산한 뒤에 해당 결과값을 idx에 넣어서 그걸 반복하다가, 해당 배열에 0이 없으면 반복이 끝난것이므로 그 배열에 들어있는 값을 출력하는 방법을 사용했다.

근데 계속 틀렸다고 떠서 다른 사람의 아이디어를 훔쳐왔다 ㅋㅋ  
배열에 1씩 더해주다가 3 되면 한 구간이 반복된거니까 재귀로 돌아와준다.  
이후 전부 탐색하며 1인부분은 반복된게 아니니까 1인 것의 개수만 더해주면 정답이다.

### 오답노트
----------
