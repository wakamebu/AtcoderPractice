#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using ll = long long;
using P = pair<int,int>;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main() {
  int n,m;
  cin >> n >> m;
  vector<vector<int>> to(n);

  vector<int> A(m);
  vector<int> B(m);

  rep(i,m)cin >>A[i] ,A[i]--;
  rep(i,m)cin >> B[i],B[i]--;

  rep(i,m) to[A[i]].push_back(B[i]);
  rep(i,m) to[B[i]].push_back(A[i]);

  vector<int> color(n,-1);
  auto dfs = [&](auto dfs,int v,int c=0) -> bool {
      if(color[v] != -1) return color[v] == c;
      color[v] = c;
      for(int u :to[v]){//隣接にcとは逆の色を書き込む
        if(!dfs(dfs,u,c^1)) return false;
      }
      return true;
    };

    rep(v,n) if (color[v] == -1){
      if(!dfs(dfs,v)){
        cout << "No" <<endl;
        return 0;
      }
    }

  cout << "Yes"<< endl;
  return 0;
}