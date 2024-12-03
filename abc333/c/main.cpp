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

  vector<ll> lep;
  for(ll i = 1; i < 1e12; i= i*10+1) {
    lep.push_back(i);
  }

  set<ll> s;

  for(ll a :lep){
    for(ll b : lep){
      for(ll c : lep){
        s.insert(a+b+c);
      }
    }
  }
  
  vector<ll> ans;
  for(ll x :s) ans.push_back(x);

  cout << ans[n-1] << endl;
  return 0;
}