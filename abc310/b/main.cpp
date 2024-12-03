#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using ll = long long;
using P = pair<int,int>;
#define rep(i,n) for(int i = 0; i < (n); i++)

struct M{
  int p;
  int c;
  vector<int> f;
};

bool compare(const M& a, const M& b) {
  if (a.p != b.p) return a.p < b.p;  // 価格が異なる場合、価格で昇順にソート
  return a.c < b.c;                  // 価格が同じ場合、機能数で昇順にソート
}

int main() {
  int n,m;
  cin >> n >> m;

  vector<M> mc(n);

  rep(i, n) {
    cin >> mc[i].p >> mc[i].c;
    mc[i].f.resize(mc[i].c);
    rep(j, mc[i].c) {
      cin >> mc[i].f[j];
    }
  }

  sort(mc.begin(), mc.end(), compare);  // 商品リストをソート

  bool found = false;

  rep(i,n){
    rep(j,n){
      if (i == j) continue;
      if(mc[i].p < mc[j].p)continue;
      if(includes(mc[j].f.begin(),mc[j].f.end(),mc[i].f.begin(),mc[i].f.end())){
        if(mc[i].p > mc[j].p || (mc[i].p == mc[j].p and mc[i].c<mc[j].c)){
          found = true;
          break;
        }
      }
    }
    if (found) break;
  }


  cout << (found ? "Yes" : "No") << endl;
  return 0;
}