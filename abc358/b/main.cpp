#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using ll = long long;
using P = pair<int,int>;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main() {
  int n,a;
  cin >> n >> a;
  vector<int> time(n);
  rep(i,n)cin >> time[i];

  vector<int> ans(n);
  int current=0;

  rep(i,n){
    int t = time[i];
    current = max(current,t) + a;
    ans[i] = current;
  }

  rep(i,n)cout << ans[i] << endl;

  return 0;
}