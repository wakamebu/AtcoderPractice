#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using ll = long long;
using P = pair<int,int>;
#define rep(i,n) for(int i = 0; i < (n); i++)


int main() {
  int n;
  cin >> n;

//隣接リスト
  vector<vector<int>> to(n);
  rep(i,n-1){
    int a,b;
    cin >> a>> b;
    a--;b--;
    to[a].push_back(b);
    to[b].push_back(a);
  }

  int ans = n;
  for(int v :to[0]){
    auto f = [&](auto f,int v,int p=-1) -> int {
      int res = 1;
      for(int u :to[v]){
        if(u == p) continue;
        res += f(f,u,v);
      }
      return res;
    };
    int now = n-f(f,v,0);
    ans = min(ans,now);
  }

  cout << ans << endl;

  return 0;
}