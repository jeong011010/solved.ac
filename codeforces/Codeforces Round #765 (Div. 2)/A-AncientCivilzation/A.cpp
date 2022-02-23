#include<iostream>
#include<vector>
#include<bitset>
#include<string>

using namespace std;

vector<int> num[100];
int tc,n,l;

void input(){
    cin>>n>>l;
    int x;
    for(int i=0;i<n;i++){
        num[i].clear();
        cin>>x;
        bitset<30> bs(x);
        string s=bs.to_string();
        for(int j=0;j<l;j++){
            num[i].push_back(((int)s[30-l+j])-48);
        }
    }

}

void f(){
    int answer=0,tmp=0,pow=1;
    for(int i=0;i<l;i++){
        answer*=10;
        int n_0=0,n_1=0;
        for(int j=0;j<n;j++){
            if(num[j][i]==0) n_0++;
            else n_1++;
        }
        answer += (n_1>n_0?1:0);   
    }
    for(int i=0;answer>=1;i++){
        tmp+=(answer%10)*pow;
        pow*=2;
        answer/=10;
    }
    cout<<tmp<<'\n';
}

void solve(){
    cin>>tc;
    for(int i=0;i<tc;i++){
        input();
        f();
    }
}

int main(){
    solve();
    return 0;
}