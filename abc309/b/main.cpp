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

  vector<string> a(n);
  rep(i,n) cin >> a[i];

  vector<P> ps;
  rep(i,n-1) ps.emplace_back(0,i);
  rep(i,n-1) ps.emplace_back(i,n-1);
  rep(i,n-1) ps.emplace_back(n-1,n-1-i);
  rep(i,n-1) ps.emplace_back(n-1-i,0);

  vector<string> b = a;
  int m = ps.size();
  rep(mi,m){
    auto [i,j] = ps[mi];
    auto[ni,nj] = ps[(mi+1)%m];
    b[ni][nj] = a[i][j];
  }
  
  rep(i,n) cout << b[i] << endl;
  return 0;
}