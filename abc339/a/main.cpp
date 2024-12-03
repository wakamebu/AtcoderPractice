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

  int res = 0;
  rep(i,s.size()){
    if(s[i] =='.'){
      res = i+1;
    }
  }

  cout << s.substr(res) << endl;
  return 0;
}