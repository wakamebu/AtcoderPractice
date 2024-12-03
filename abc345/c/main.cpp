#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using ll = long long;
using P = pair<int,int>;
#define rep(i,n) for(int i = 0; i < (n); i++)

ll c2(ll n){
  return n*(n-1)/2;
}


int main() {
  string s;
  cin >> s;
  int n = s.size();

  ll same = 0;
  map<char,int> cnt;
  for (char c : s)cnt[c]++;
  for (auto p : cnt){
    int m = p.second;
    same += c2(m);
  }

  ll diff = c2(n) - same;

  ll ans = diff;
  if(same) ans ++;

  cout << ans << endl;
  return 0;
}