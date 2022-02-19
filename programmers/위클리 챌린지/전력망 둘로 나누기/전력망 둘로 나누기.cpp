#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <cstdlib>
using namespace std;

vector<int> edge[101];

int dfs(int start, int cut_s, int cut_e){
    bool visited[101]={false};
    int cnt=1;
    stack<int> s;
    s.push(start);
    while(!s.empty()){
        int e = s.top();
        s.pop();
        visited[e]=true;
        for(int i=0;i<edge[e].size();i++){
            if(!visited[edge[e][i]] && !((e==cut_s&&edge[e][i]==cut_e) || (e==cut_e&&edge[e][i]==cut_s))){
                visited[edge[e][i]]=true;
                cnt++;
                s.push(edge[e][i]);
            }
        }
    }
    return cnt;
}

int solution(int n, vector<vector<int>> wires) {
    int answer = 100;
    for(int i=0;i<wires.size();i++){
        int x=wires[i][0]; int y=wires[i][1];
        edge[x].push_back(y); edge[y].push_back(x);
    }
    
    for(int i=0;i<wires.size();i++){
        int x=wires[i][0]; int y=wires[i][1];
        int tmp = abs(dfs(x,x,y) - dfs(y,x,y));
        answer = min(answer,tmp);
    }
    
    return answer;
}