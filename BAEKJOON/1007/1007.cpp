#include<iostream>
#include<vector>
#include<cmath>
using namespace std;

int T,N,sum_x,sum_y, q;
vector<pair<int,int>> v;
vector<int> select(20,0);
bool use[20];
double ans=0, tmp;

void f(int n, int R){
    if(R==0){
        int sum_x_tmp = sum_x;
        int sum_y_tmp = sum_y;
        for(int i=0;i<q;i++){
            sum_x_tmp-=2*v[select[i]].first;
            sum_y_tmp-=2*v[select[i]].second;
        }
        tmp = sqrt(pow(sum_x_tmp,2)+pow(sum_y_tmp,2));
        if(tmp<ans) ans=tmp;
    }
    else if(n<R) return;
    else{
        select[R-1]=(n-1);
        f(n-1,R-1);
        f(n-1,R);
    }
}

void solve(){
    int a,b;
    cin>>T;
    while(T--){
        sum_x=sum_y=0;
        ans=LLONG_MAX;
        cin>>N;
        for(int i=0;i<N;i++){
            cin>>a>>b;
            v.push_back({a,b});
            sum_x+=a;
            sum_y+=b;
        }
        q=N/2;
        f(N,N/2);
        printf("%.12f\n",ans);

    }
}

int main(){
    solve();
    return 0;
}