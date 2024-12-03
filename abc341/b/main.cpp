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

  ll total = 0;
  vector<ll> yen(n);
  rep(i,n)cin >> yen[i];
  rep(i,n)total += yen[i];

  rep(i,n-1){
    ll s,t = 0;
    cin >> s >> t;
    ll times = yen[i]/s;
    ll change = t * times;
    ll m = s - t;
    ll lose = m * times;
    total -= yen[i] % s;
    total -= lose;
    yen[i+1] += change;
  }



  cout << yen.back() << endl;
  return 0;
}