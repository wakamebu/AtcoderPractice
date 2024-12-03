#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using ll = long long;
using P = pair<int,int>;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main() {
  int n,d,p;
  cin >> n >> d >> p;

  vector<int> f(n);
  rep(i,n) cin >> f[i];
  sort(f.begin(),f.end());

  vector<ll> sum(n+1);
  sum[0] = 0;
  rep(i,n){
    sum[i+1] = sum[i] + f[i];
  }

  ll ans = 1e18;
  rep(i,1e9){
    int r =max(0,n-i*d);
    ll now = sum[r] + (ll)p*i;
    ans = min(ans,now);
    if (r == 0)break;
  }
  cout << ans << endl;
  return 0;
}