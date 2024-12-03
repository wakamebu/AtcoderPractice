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

  vector<string> s(n);
  rep(i,n) cin >> s[i];

  bool can = false;

  rep(i,n){
    rep(j,n){
    string t = "";
    t += s[i];
      if(i == j)continue;
      t+=s[j];
      string c = t;
      reverse(c.begin(),c.end());
      if(c == t) can = true;
    }
  }

  cout << (can ? "Yes":"No") << endl;
  return 0;
}