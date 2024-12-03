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

  rep(i,s.size()-2){
    string b = s.substr(i,3);
    if(b == "ABC"){
      cout << i+1 << endl;
      return 0;
    }
  }

  int ans = -1;

  cout << ans << endl;
  return 0;
}