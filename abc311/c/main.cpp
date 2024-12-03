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
  vector<int> to(n+1);

  rep(i,n){cin >> to[i+1];
  }

  int v = 1;
  rep(i,n) v= to[v];
  int sv = v;
  vector<int> ans;
  do {
    ans.push_back(v);
    v = to[v];
  } while(v != sv);

cout << ans.size() << endl;
for(int v: ans)cout << v << ' ';
cout << endl;

  return 0;
}