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
  vector<int> dt(n);
  rep(i,n)cin >>dt[i];

  int ans = 0;
    for (int m = 1; m <= n; ++m) {
        string month = to_string(m);
        for (int d = 1; d <= dt[m - 1]; ++d) {
            string date = month + to_string(d);
            if (size(set<char>(date.begin(), date.end())) == 1)
                ++ans;
        }
    }
    cout << ans << endl;

  return 0;
}