#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using ll = long long;
using P = pair<int,int>;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main() {
  ll n,ans = 0;
  cin >> n;
  for(ll i = 1;i*i*i<=n;i++){
    ll x = i * i * i;
    string s = to_string(x);
    if(s == string(s.rbegin(),s.rend())){
      ans = i* i* i;
    }
  }


  cout << ans << endl;
  return 0;
}