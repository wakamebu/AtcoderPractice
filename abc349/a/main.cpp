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

  int ans=0;
  rep(i,n){
  int j = 0;
    cin >> j;
    ans += j;
  }

  ans = -1*ans;

  cout << ans << endl;
  return 0;
}