#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using ll = long long;
using P = pair<int,int>;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main() {
  int n,k;
  cin >> n >> k;
  vector<int> s(k);
  vector<int> pre(k+1),suf(k+1);

  rep(i,n) cin >> s[i];

// 前方累積和の計算
  for (int i = 1; i <= k; i++) {
        pre[i] = pre[i - 1];
        if (i % 2 == 0) pre[i] += s[i - 1] - s[i - 2];
    }
// 後方累積和の計算
  for (int i = k-1; i >=0; i--) {
        suf[i] = suf[i + 1];
        if ((k - i) % 2 == 0) suf[i] += s[i + 1] - s[i];
    }
  
  int ans = 1e9;
  for (int i = 0; i <= k; i += 2) {
        ans = min(ans, pre[i] + suf[i]);
    }
  cout << ans << endl;
  return 0;
}