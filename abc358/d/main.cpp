#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int,int>;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main() {
  int n, m;
  cin >> n >> m;
  vector<ll> A(n);
  vector<ll> B(m);

  rep(i, n) cin >> A[i];
  rep(i, m) cin >> B[i];

  sort(A.begin(), A.end());
  sort(B.begin(), B.end());

  unordered_map<ll, ll> ans;
  vector<bool> used(n, false);

  ll sum = 0;
  int it = 0;
  rep(i, m) {
    while (it < n && (A[it] < B[i] || used[it])) {
      ++it;
    }
    if (it < n) {
      ans[B[i]] = A[it];
      sum += A[it];
      used[it] = true; 
    } else {
      ans[B[i]] = -1;
    }
  }

  for (auto x : ans) {
    if (x.second == -1) {
      cout << "-1" << endl;
      return 0;
    }
  }

  cout << sum << endl;
  return 0;
}
