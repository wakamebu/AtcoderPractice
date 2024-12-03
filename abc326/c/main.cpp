#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using ll = long long;
using P = pair<int,int>;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main() {
  ll n,m;
  cin >> n >> m;
  vector<int> a(n);
  rep(i,n)cin >> a[i];
  sort(a.begin(),a.end());

  int ans = 0;
  int r = 0;
  rep(l,n){
    while(r < n and a[r]<a[l]+m){r++;
      ans = max(ans,r-l);
    }
  }
    cout << ans << endl;
  return 0;
}