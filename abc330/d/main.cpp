#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using ll = long long;
using P = pair<int,int>;
#define rep(i,n) for(int i = 0; i < (n); i++)

struct d{
  P a;
  P b;
  P c;
  bool operator<(const d& other) const {
        if (a != other.a) {
            return a < other.a;
        } else if (b != other.b) {
            return b < other.b;
        } else {
            return c < other.c;
        }
    }

};

int main() {
  int n;
  cin >> n;

  vector<vector<char>> grid(n,vector<char>(n));
  rep(i,n){
    rep(j,n){
      char c;
      cin >>c;
      grid[i][j] = c;
    }
  }

  set<d> ans;  int it  = n-1;
  vector<ll> bi(n,0), bj(n,0);

  rep(i,n){
    rep(j,n){
      it = n;
      if(grid[i][j]== 'o'){
        bi[i] ++;
        bj[j] ++;
      }
    }
  }

  long long res=0;
  for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
      if(grid[i][j]=='o'){
        res+=(bi[i]-1)*(bj[j]-1);
      }
    }
  }

  cout << res << endl;
  return 0;
}