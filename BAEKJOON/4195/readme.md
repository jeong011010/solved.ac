# 4195 친구 네트워크
------------
### 문제

>민혁이는 소셜 네트워크 사이트에서 친구를 만드는 것을 좋아하는 친구이다. 우표를 모으는 취미가 있듯이, 민혁이는 소셜 네트워크 사이트에서 친구를 모으는 것이 취미이다.
>
>어떤 사이트의 친구 관계가 생긴 순서대로 주어졌을 때, 두 사람의 친구 네트워크에 몇 명이 있는지 구하는 프로그램을 작성하시오.
>
>친구 네트워크란 친구 관계만으로 이동할 수 있는 사이를 말한다.
>
>입력
>첫째 줄에 테스트 케이스의 개수가 주어진다. 각 테스트 케이스의 첫째 줄에는 친구 관계의 수 F가 주어지며, 이 값은 100,000을 넘지 않는다. 다음 F개의 줄에는 친구 관계가 생긴 순서대로 주어진다. 친구 관계는 두 사용자의 아이디로 이루어져 있으며, 알파벳 대문자 또는 소문자로만 이루어진 길이 20 이하의 문자열이다.
>
>출력
친구 관계가 생길 때마다, 두 사람의 친구 네트워크에 몇 명이 있는지 구하는 프로그램을 작성하시오.

### 아이디어 
----------
union find 문제.
좀 빡셌다.

친구 이름이 중복적으로 나올 수 있으므로 map을 사용해주고,
해당 친구 이름을 순서대로 숫자로 표시하기 위해

이름 입력을 받은 경우 find로 중복을 찾아주고,
중복이 아니라면 map에 name과 cnt++를 넣어준다.

이름 두개를 받은 뒤, union-find를 돌려준다.
두 이름의 부모를 찾아주며 둘 중 번호가 작은곳이 부모를 한다.

여기서 많이 헷갈려서 고전했는데,
출력에서 친구 관계가 생길 때마다, 두 사람의 친구 네트워크에 몇 명이 있는지 구하라고 했다.
그니까 입력받은 두명의 친구 기준으로 친구가 몇명 있냐는건데

나는 처음에 민혁이 친구가 몇명이냐고 물어보는줄 알았다.
근데 또 민혁이는 입력에 안넣으니까 이해가 안갔음.

결국에 나중에 반례 찾아보다가 찾은게
3 나오다가 2가 나오니까 어 이럴수가 있나? 하고 문제를 다시봤는데 보이더라..
그래서 입력받은 이름중 하나의 부모를 찾아준 뒤,
그 부모의 친구 개수를 출력했다.


### 오답노트
----------
진짜 개같은 문제였음.
심지어 시간초과 나서 설마하고
ios::sync_with_stdio(false);
cin.tie(NULL);
넣어주니까 시간초과 안나더라 이런 망할.