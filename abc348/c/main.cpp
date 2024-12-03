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

  vector<P> beans(n);

  rep(i,n){
    int A , C;
    cin >> A >> C;
    beans[i] = make_pair(C,A);
  }

  sort (beans.begin(),beans.end());
  map<int,int> ans;

  int it = 0;
  while (it < n) {
    int color = beans[it].first;
    int minAb = beans[it].second;

    // 同じ色の豆の中で最小値を見つける
    while (it < n && beans[it].first == color) {
      minAb = min(minAb, beans[it].second);
      it++;
    }

    ans[color] = minAb;
  }

  int ma = 0;
  for (auto p : ans) {
    if(ma < p.second){
      ma = p.second;
    }
  }
  cout<< ma << endl;

  return 0;
}