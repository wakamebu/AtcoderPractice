#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using ll = long long;
using P = pair<int,int>;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main() {
  int n , x;
  cin >> n >> x;

  int ans = 0;
  int res;
  rep(i,n){
    cin >> res;
    if(res <= x)  ans += res;
  }

  cout << ans << endl;
  return 0;
}