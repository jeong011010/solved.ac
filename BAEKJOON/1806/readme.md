# 1806 부분합
------------
### 문제

>10,000 이하의 자연수로 이루어진 길이 N짜리 수열이 주어진다. 이 수열에서 연속된 수들의 부분합 중에 그 합이 S 이상이 되는 것 중, 가장 짧은 것의 길이를 구하는 프로그램을 작성하시오.

### 아이디어 
----------
위 문제는 two point algorithm을 이용하여 풀 수 있었다.

연속된 부분합을 찾을 때는 two pointer를 사용하면 쉽게 풀 수 있다.

- 두개의 포인터 s,e 를 선언한다.
- 사이의 합이 S보다 작으면 e 위치의 값을 더해주고 e를 뒤로 옮긴다.
- 사이의 합이 S보다 크면 문제의 조건에 부합하므로 e-s+1과 ans를 비교하여 최솟값을 저장해준다. 이후 s 위치의 값을 빼주고 s를 뒤로 옮긴다.

해당 알고리즘을 s가 끝에 도달하거나 합이 S보다 작은데 e가 끝에 도달할 때 까지 반복해준다.

### 오답노트
----------

__합이 S보다 작은데 e가 끝에 도달할 때 까지 반복해준다.__ 를 안해줘서 e가 없는 값을 참조하는 outofBounds 에러가 났었다.