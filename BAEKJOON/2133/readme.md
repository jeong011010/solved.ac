# 2133 타일 채우기
------------
### 문제

>3×N 크기의 벽을 2×1, 1×2 크기의 타일로 채우는 경우의 수를 구해보자.

### 아이디어 
----------
위 문제는 DP 문제이다.

타일의 개수가 꽉 찰 때는 N이 2의 배수일 때다.  
조합은 N이 2칸일 때 3개씩 되므로 3의 (N/2)승을 해주면 되지만, N이 4 이상일 때 부터 중간에 조합이 섞일 수 있게 된다.  
해당 조합은 칸마다 2가지가 생긴다.

그러므로 점화식은
```
DP[i]=(DP[i-2]*DP[2])+(DP[i-4]*2)+(DP[i-6]*2)+...(DP[0]*2)
```
이다.

### 오답노트
----------
어렵다.