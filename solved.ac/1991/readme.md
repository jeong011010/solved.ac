# 1991번 트리 순회
------------
### 문제

>이진 트리를 입력받아 전위 순회(preorder traversal), 중위 순회(inorder traversal), 후위 순회(postorder traversal)한 결과를 출력하는 프로그램을 작성하시오.  
>
><img width="40%" src="https://www.acmicpc.net/JudgeOnline/upload/201007/trtr.png"/>
>
>예를 들어 위와 같은 이진 트리가 입력되면,  
> - 전위 순회한 결과 : ABDCEFG // (루트) (왼쪽 자식) (오른쪽 자식)  
> - 중위 순회한 결과 : DBAECFG // (왼쪽 자식) (루트) (오른쪽 자식)  
> - 후위 순회한 결과 : DBEGFCA // (왼쪽 자식) (오른쪽 자식) (루트)  
> 가 된다.

### 아이디어
----------
위 문제는 트리를 구현한 뒤, 트리 순회 함수를 재귀 함수로 구현하는 문제이다.
특징은 전위, 중위, 후위 순회 모두 실행해야한다.
c에서 포인터 구조체로 죽도록 해봤지만 c++에서는 처음 구현해봐서 포인터 구조체 말고 구조체 vector 배열을 사용하여 효율은 좋지 않지만 간단하게 설계했다.
```
typedef struct tree{
    bool check;
    char key;
    int left, right;
}tree;
tree t[27];
```
위와 같이 tree 구조체를 구현하였으며, left와 right에는 알파벳을 (ASCII 코드 - 65)로 넣고, '.'이 들어올 시 0을 넣어줬다.

### 오답노트
----------
- c++에서 구조체 포인터를 구현할 이유는 없다고 생각해서 vector stl을 이용한 배열을 사용하였다.
- 한번에 풀었긴 했다.