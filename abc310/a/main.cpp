#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using ll = long long;
using P = pair<int,int>;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main() {
  int n,p,d;
  cin >> n >> p >>d;

  vector<int> dk(n);

  rep(i,n)cin >> dk[i];

  int ans = p;
  rep(i,n){
    ans = min(ans,dk[i]+d);
  }

  cout << ans << endl;
  return 0;
}