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
  vector<int> a(7*n);
  vector<int> ans(n);

  rep(i,7*n){
    cin >> a[i];
  }
  rep(i,n){
    rep(j,7){
      ans[i] += a[j+(i*7)];
    }
  }

  for(auto x : ans)cout << x  << " ";

  cout <<endl;
  return 0;
}