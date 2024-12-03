#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using ll = long long;
using P = pair<int,int>;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main() {
  int n,m;
  cin >> n>>m;

  vector<int> p(m);
  rep(i,m) cin >> p[i];

  vector<string> grid(n);
  vector<int> r(n,0);
  vector<vector<int>> l(n);

  rep(i,n)cin >> grid[i];

  rep(i,n){
    r[i] += i+1;
    rep(j,m){
      char c = grid[i][j];
      if(c ==  'o')  r[i] += p[j];
      else l[i].push_back(p[j]);
    }
  }

  int maxp = 0;
  rep(i,n){
    int t = r[i];
    maxp = max(maxp,t);
  }
  rep(i,n){
    sort(l[i].rbegin(),l[i].rend());
  }

  rep(i,n){
    int cnt = 0;
    int t = r[i];
    if(maxp == t){
      cout << 0 << endl;
      continue;
    }
    else{
      int less = maxp -t;
      int it = 0;
      while(less>0){
        cnt++;
        less -= l[i][it];
        it++;
      }
      cout << cnt << endl;
    }
  }

  return 0;
}