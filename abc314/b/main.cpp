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

    vector bet(n, vector<int>{});
    for(auto& A : bet) {
        int C;
        cin >> C;
        A.resize(C);
        for(int& a : A) cin >> a;
    }
    int X;
    cin >> X;
  set<int> ans;

    for(auto xi : r){
      if (find(xi.second.begin(), xi.second.end(), x) != xi.second.end()){
        ans.insert(xi.first);
      }
    }
  

  cout << ans.size() << endl;
  for(auto d :ans){
  cout << d <<" " ;
  }
  cout << endl;
  return 0;
}