#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using ll = long long;
using P = pair<int,int>;
#define rep(i,n) for(int i = 0; i < (n); i++)


ll floor(ll x, ll m) {
    ll r = (x % m + m) % m;
    return (x - r) / m;
}

int main() {
  ll a,m,l,r;
  cin >> a >> m >> l >> r;
  l -= a, r -= a; //全体をAだけずらすことで、Aを原点に持ってくる
  cout << floor(r, m) - floor(l - 1, m) << endl;//OからRまでを求めて、そこからOからL-1までを引く
  return 0;
}