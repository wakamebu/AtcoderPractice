#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using ll = long long;
using P = pair<int,int>;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main() {

  
  vector<int> grid(9);
  rep(i,9)cin >> grid[i];  

  vector<int> p(9);
  rep(i,9) p[i] = i;
  int wakuwaku = 0;
  int tot = 0;
  do{
    bool ok = true;
    auto f = [&](int i, int j ,int k){
      vector<P> d;
      d.emplace_back(p[i],grid[i]);
      d.emplace_back(p[j],grid[j]);
      d.emplace_back(p[k],grid[k]);
      sort(d.begin(),d.end());
      if(d[0].second == d[1].second) ok = false;
    };
    f(0,1,2);
    f(3,4,5);
    f(6,7,8);
    f(0,3,6);
    f(1,4,7);
    f(2,5,8);
    f(0,4,8);
    f(2,4,6);
    if(ok) wakuwaku++;
    tot++;
  }
  while (next_permutation(p.begin(),p.end()));

  double b = 1.*wakuwaku/tot;
  cout << setprecision(10) << b << endl;
  return 0;
}