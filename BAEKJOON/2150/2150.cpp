#include <algorithm>
#include <iostream>
#include <map>
#include <stack>
#include <vector>
using namespace std;

int V, E; //정점, 간선
vector<int> v[10001];
map<vector<int>, int> SCC;
int ans = 0;

void input() {
  cin >> V >> E;
  int A, B;
  for (int i = 0; i < E; i++) {
    cin >> A >> B;
    v[A].push_back(B);
  }
}

void dfs(int s, int P[]) {
  bool isSCC[10001] = {
      false,
  };
  stack<int> st;
  int k = 0;
  P[s] = s; // 부모 자기자신으로 설정
  st.push(s);

  int parent = P[s];

  while (!st.empty()) {
    int n = st.top();
    parent = n;
    st.pop();

    if (v[n].size() == 0) { //자식노드가 없는 정점
      vector<int> scc;
      scc.push_back(n);
      SCC.insert(pair<vector<int>, int>(scc, 1));
      isSCC[n] = true;
      k++;
    }
    for (int i = 0; i < v[n].size(); i++) { // dfs
      if (P[v[n][i]] == 0) { // 부모없는 정점(방문안한 정점)
        st.push(v[n][i]);
        P[v[n][i]] = parent;
        // parent=v[n][i]; //부모 업데이트
      } else if (!isSCC[v[n][i]]) { //부모 있음 (방문한 정점)
        vector<int> scc;
        int tmp = n;
        while (P[tmp] !=
               v[n][i]) { // 자식을 부모로 만날때까지 거슬러올라가며 scc에 추가
          // cout<<"P[tmp]:"<<P[tmp]<<" v[n][i]:"<<v[n][i]<<endl;
          scc.push_back(tmp);
          isSCC[tmp] = true;
          tmp = P[tmp];
        }
        isSCC[tmp] = true;
        isSCC[P[tmp]] = true;
        scc.push_back(tmp);
        scc.push_back(P[tmp]);
        sort(scc.begin(), scc.end());
        SCC.insert(pair<vector<int>, int>(scc, 1));
        k++;
      }
    }
  }
  ans = max(ans, k);
}

void solve() {
  for (int i = 1; i <= V; i++) {
    int P[10001] = {
        0,
    };
    dfs(i, P);
  }
  cout << ans << endl;
  for (auto iter = SCC.begin(); iter != SCC.end(); iter++) {
    for (int i = 0; i < (iter->first).size(); i++) {
      cout << (iter->first)[i] << " ";
    }
    cout << "-1" << endl;
  }
}

int main() {
  input();
  solve();
  return 0;
}

//그림 예제
/*
8 13
1 2
2 3
3 4
4 3
2 5
2 6
5 1
5 6
3 7
4 8
6 7
7 6
7 8
*/