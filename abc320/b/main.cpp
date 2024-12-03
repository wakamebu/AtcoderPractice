#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using ll = long long;
using P = pair<int,int>;
#define rep(i,n) for(int i = 0; i < (n); i++)

bool circ(string s){
  string t = s;
  reverse(t.begin(),t.end());
  return s == t;
}

int main() {
  string s;
  cin >> s;

  int ans = 0;
  int n = s.size();
  rep(r,n)rep(l,r+1){
    string ns = s.substr(l,r-l+1);
    if(circ(ns)) ans = max(ans,r-l+1);
  }

  cout << ans << endl;
  return 0;
}