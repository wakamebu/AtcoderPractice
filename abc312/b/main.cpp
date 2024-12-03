#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using ll = long long;
using P = pair<int,int>;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main() {
  int n, m;
  cin >> n >> m;

  vector<vector<char>> grid(n, vector<char>(m, '.'));

  rep(i, n) {
    rep(j, m) {
      cin >> grid[i][j];
    }
  }

  auto f = [&](vector<vector<char>>& s, int i, int j) {
    // 左上3x3のチェック
    for (int x = 0; x < 3; x++) {
      for (int y = 0; y < 3; y++) {
        if (s[x + i][y + j] != '#') return false;
      }
    }

    // 右下3x3のチェック
    for (int x = 6; x < 9; x++) {
      for (int y = 6; y < 9; y++) {
        if (s[x + i][y + j] != '#') return false;
      }
    }

    // 左上3x4と上3x3のチェック
    for (int y = 0; y < 4; y++) {
      if (s[3 + i][y + j] != '.') return false;
    }
    for (int x = 0; x < 3; x++) {
      if (s[x + i][3 + j] != '.') return false;
    }

    // 右下4x3と下3x4のチェック
    for (int y = 5; y < 9; y++) {
      if (s[5 + i][y + j] != '.') return false;
    }
    for (int x = 6; x < 9; x++) {
      if (s[x + i][5 + j] != '.') return false;
    }

    return true;
  };

  rep(i, n - 8) {
    rep(j, m - 8) {
      if (f(grid, i, j)) {
        cout << i + 1 << " " << j + 1 << endl;
      }
    }
  }
  cout << endl;

  return 0;
}
