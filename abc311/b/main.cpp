#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using ll = long long;
using P = pair<int,int>;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main() {
  int n, d;
  cin >> n >> d;

  vector<string> sc(n);  // 入力の格納場所を修正
  rep(i, n) {
    cin >> sc[i];
  }

  vector<vector<int>> sd(n, vector<int>(d));
  rep(i, n) {
    rep(j, d) {
      if (sc[i][j] == 'o') {
        sd[i][j] = 1;
      } else {
        sd[i][j] = 0;
      }
    }
  }

  vector<int> sum(d, 0);  // sum 配列のサイズを修正
  rep(i, n) {
    rep(j, d) {
      sum[j] += sd[i][j];
    }
  }

  int ans = 0;
  int res = 0;
  rep(j, d) {
    if (sum[j] == n) {
      res++;
      ans = max(ans, res);
    } else {
      res = 0;
    }
  }

  cout << ans << endl;
  return 0;
}
