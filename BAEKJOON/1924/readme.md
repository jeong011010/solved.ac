# 1924 2007년
------------
### 문제

>오늘은 2007년 1월 1일 월요일이다. 그렇다면 2007년 x월 y일은 무슨 요일일까? 이를 알아내는 프로그램을 작성하시오.

### 아이디어
----------
위 문제는 단순 구현문제였다.

2007년 1월 1일이 __월요일__일 때, x월 y일은 무슨 요일인지 구하면 된다.

순서대로 30,31 더해주려고 했는데, 2월도 있고 7월-8월이 연속 31일일이여서 배열로 월별 일 개수를 선언해줬다.  
또한, 요일(MON~SUN)을 string 배열로 선언해줬다.

이후 월만큼 for문으로 월별 일 개수를 더해준 뒤, 일 수를 더하여 7로 나눈 나머지를 배열에 넣으면 답이다.  

### 오답노트
----------
