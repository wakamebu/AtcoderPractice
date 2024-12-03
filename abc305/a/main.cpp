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

  int res = n % 5;
  if(res == 0){cout << n << endl; return 0;}
  else if(res >2)res = 5- res;
  else if(res<3){cout << n- res << endl;return 0;}
  int ans = n + res;

  cout << ans << endl;

  return 0;
}