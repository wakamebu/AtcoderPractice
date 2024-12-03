#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using ll = long long;
using P = pair<int,int>;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main() {
  string s;
  cin >> s;

  set<string> ans;

  rep(i,s.size()){
    string B;
    rep(j,s.size()){
      B = s.substr(i,j);
      ans.insert(B);
    }
  }

  cout << ans.size() << endl;
  return 0;
}