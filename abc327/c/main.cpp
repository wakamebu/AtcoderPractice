#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using ll = long long;
using P = pair<int,int>;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main() {
  vector<vector<int>> grid(9,vector<int>(9));
  bool ok = true;
  int ans = 1*2*3*4*5*6*7*8*9;

  rep(i,9){
    rep(j,9){
      cin >> grid[i][j];
    }
  }

  vector<vector<int>> t(9, vector<int>(9));
  rep(i,9) {
    rep(j,9) {
      t[j][i] = grid[i][j];
    }
  }

  rep(i,9){
    int x = 1;
    int y = 1;
    rep(j,9){
      x *= grid[i][j];
      y *= t[i][j];
    }
    if(x != ans) ok = false;
    if(y != ans) ok = false;
  }


  for (int row = 0; row < 9; row += 3) {
        for (int col = 0; col < 9; col += 3) {
            int res = 1;
            rep(i, 3) {
                rep(j, 3) {
                    res *= grid[row + i][col + j];
                }
            }
            if (res != ans) ok = false;
        }
    }


  cout << (ok ? "Yes" : "No") << endl;
  return 0;
}