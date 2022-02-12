#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int ans=0;

typedef struct Sclass{
    int cnt,k;
    bool check[8]={0,};
}Sclass;

void dfs(int k, vector<vector<int>> d){
    stack<Sclass> s;
    for(int i=0;i<d.size();i++){
        if(d[i][0]<=k){
            Sclass tmp;
            tmp.cnt=1; tmp.k=k-d[i][1]; tmp.check[i]=1;
            s.push(tmp);
        }
        while(!s.empty()){
            Sclass data = s.top();
            s.pop();

            for(int j=0;j<d.size();j++){
                if(!data.check[j] && d[j][0]<=data.k){
                    Sclass tmp = data;
                    tmp.check[j]=true;
                    tmp.k-=d[j][1];
                    tmp.cnt++;
                    s.push(tmp);
                }
            }
            ans = max(ans,data.cnt);
        }
    }
}

int solution(int k, vector<vector<int>> dungeons) {
    dfs(k, dungeons);
    return ans;
}