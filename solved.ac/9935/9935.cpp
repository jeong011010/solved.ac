#include<iostream>
using namespace std;

string s,es,ans="";

void f(){
    for(int i=0;i<s.length();i++){
        ans += s[i];
        if(ans[ans.length()-1]==es[es.length()-1]){
            bool b=true;
            for(int i=0;i<es.length();i++)
                if(ans[ans.length()-1-i]!=es[es.length()-1-i]) {b=false;break;}
            if(b)
                for(int i=0;i<es.length();i++) ans.pop_back();           
        }
    }
}

void solve(){
    cin>>s>>es;
    f();
    cout<<(ans!=""?ans:"FRULA");
}

int main(){
    solve();
    return 0;
}