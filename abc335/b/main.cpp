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

  int x = 0;
  int y = 0;
  int z = 0;
  vector<tuple<int,int,int>> ans;

  rep(i,n+1){
    x = i;
    rep(j,n+1){
      z = 0;
      y = j;
      while(x+y+z <= n){
        ans.emplace_back(x,y,z);
        z++;
      }
    }
  }

  for (const auto& t : ans) {
    int x, y, z;
    tie(x, y, z) = t;
    cout <<  x << " " << y << " " << z <<  endl;
  }
  return 0;
}