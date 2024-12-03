#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using ll = long long;
using P = pair<int,int>;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main() {
  string ans = "3.1415926535897932384626433832795028841971693993751058209749445923078164062862089986280348253421170679";

  int n;
  cin >> n;

  cout << ans.substr(0, n + 2) << endl;
  return 0;
}
