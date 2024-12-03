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

  string s;
  cin >> s;
  string t = "";

  rep(i,n){
    rep(j,2){
      t += s[i];
    }
  }

  cout << t << endl;
  return 0;
}