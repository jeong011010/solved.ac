#include<iostream>
#include<stack>
using namespace std;

string s, answer;
stack<char> flag;
bool open = false;

void solve(){
    cin>>s;
    for(int i=0;i<s.size();i++){
        if(s[i] >= 'A' && s[i] <= 'Z'){
            answer+=s[i];
        }
        else{
            if(s[i] == '('){
                flag.push('(');
            }
            else if(s[i] == '*' || s[i] == '/'){
                while(!flag.empty()&&(flag.top()=='*'||flag.top()=='/')){
                    answer+=flag.top();
                    flag.pop();
                }
                flag.push(s[i]);
            }
            else if(s[i] == '+' || s[i] == '-'){
                while(!flag.empty() && flag.top() != '('){
                    answer+=flag.top();
                    flag.pop();
                }
                flag.push(s[i]);
            }
            else if(s[i] == ')'){
                while(!flag.empty() && flag.top()!='('){
                    answer+=flag.top();
                    flag.pop();
                }
                flag.pop();
            }
        }
    }
    while(!flag.empty()){
        answer+=flag.top();
        flag.pop();
    }
    cout<<answer<<'\n';
}

int main(){
    solve();
    return 0;
}