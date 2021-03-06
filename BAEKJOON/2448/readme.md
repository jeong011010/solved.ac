# 2448 별 찍기 - 11
------------
### 문제

>예제를 보고 규칙을 유추한 뒤에 별을 찍어 보세요.
>
>첫째 줄에 N이 주어진다. N은 항상 3×2k 수이다. (3, 6, 12, 24, 48, ...) (0 ≤ k ≤ 10, k는 정수)
>
>```
>24
>
>                       *                        
>                      * *                       
>                     *****                      
>                    *     *                     
>                   * *   * *                    
>                  ***** *****                   
>                 *           *                  
>                * *         * *                 
>               *****       *****                
>              *     *     *     *               
>             * *   * *   * *   * *              
>            ***** ***** ***** *****             
>           *                       *            
>          * *                     * *           
>         *****                   *****          
>        *     *                 *     *         
>       * *   * *               * *   * *        
>      ***** *****             ***** *****       
>     *           *           *           *      
>    * *         * *         * *         * *     
>   *****       *****       *****       *****    
>  *     *     *     *     *     *     *     *   
> * *   * *   * *   * *   * *   * *   * *   * *  
>***** ***** ***** ***** ***** ***** ***** *****
>```
### 아이디어
----------
위 문제는 분할 정복을 이용하는 근본적인 문제이다.
재귀 함수로 분할 정복 알고리즘을 구현하여 문제를 풀 수 있다.

재귀 함수 구현은 다음과 같이 할 수 있었다.
- 변의 길이 (3,6,12,,,), 행, 열을 매개변수로 가지는 triangle 재귀 함수를 선언한다.
- 변의 길이가 최소(3)라면 해당 꼭지점에 draw 함수를 호출한다.
- 그렇지 않으면 세개의 꼭지점으로 나누어 triangle 함수를 세번 호출한다.

재귀 triangle 함수는 다음과 같다
```
void triangle(int len, int r, int l){
    if(len == 3){
        draw(r,l);
        return;
    }
    triangle(len/2,r,l);
    triangle(len/2,r+len/2,l-len/2);
    triangle(len/2,r+len/2,l+len/2);
}
```

### 오답노트
----------
- 재귀 함수를 구현하는데 오래걸렸다.
- [참고 블로그](https://ansohxxn.github.io/boj/2448/)