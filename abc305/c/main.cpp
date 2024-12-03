#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using ll = long long;
using P = pair<int,int>;
#define rep(i,n) for(int i = 0; i < (n); i++)


int main() {
  int U = 1e9, D = -1e9, L = 1e9, R = -1e9;
  int h,w;
  cin >> h >> w;
  vector<vector<char>> grid(h,vector<char>(w));

  rep(i,h){
    rep(j,w){
      cin >> grid[i][j];
    }
  }

  rep(i,h){
    rep(j,w){
      if(grid[i][j] == '#') {
        U = min(U,i);
        D= max(D,i);
        L = min(L,j);
        R = max(R,j);
      }
    }
  }

  for(int i = U;i<=D ; i++){
    for(int j = L;j<=R;j++){
      if(grid[i][j] == '.')cout << i+1 << " " << j+1 << endl;
    }
  }


  return 0;
}