# 14002 가장 긴 증가하는 부분 수열 4
------------
### 문제

>수열 A가 주어졌을 때, 가장 긴 증가하는 부분 수열을 구하는 프로그램을 작성하시오.
>
>예를 들어, 수열 A = {10, 20, 10, 30, 20, 50} 인 경우에 가장 긴 증가하는 부분 수열은 A = {10, 20, 10, 30, 20, 50} 이고, 길이는 4이다.
>
>입력
첫째 줄에 수열 A의 크기 N (1 ≤ N ≤ 1,000)이 주어진다.
>
>둘째 줄에는 수열 A를 이루고 있는 Ai가 주어진다. (1 ≤ Ai ≤ 1,000)
>
>출력
첫째 줄에 수열 A의 가장 긴 증가하는 부분 수열의 길이를 출력한다.
>
>둘째 줄에는 가장 긴 증가하는 부분 수열을 출력한다. 그러한 수열이 여러가지인 경우 아무거나 출력한다.

### 아이디어 
----------
dp 문제이다.
아까 풀었던 전깃줄 연결 문제에서 사용한 가장 긴 증가하는 부분 수열을 구하는 문제인데,

그 문제랑 다른 점이라면 수열을 출력하라는 것이다.

그래서 vector[n]마다 저장해주고,
최댓값을 가졌던 수열의 위치와 최댓값을 저장했다가

최댓값과 vector[최댓값을 가졌던 수열의 위치]를 출력해준다.

### 오답노트
----------