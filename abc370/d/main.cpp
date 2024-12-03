#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using ll = long long;
using P = pair<int,int>;
using Graph = vector<vector<int>>;
#define OVERLOAD_REP(_1, _2, _3, name, ...) name
#define REP1(i, n) for (auto i = std::decay_t<decltype(n)>{}; (i) != (n); ++(i))
#define REP2(i, l, r) for (auto i = (l); (i) != (r); ++(i))
#define rep(...) OVERLOAD_REP(__VA_ARGS__, REP2, REP1)(__VA_ARGS__)
#define all(...) std::begin(__VA_ARGS__), std::end(__VA_ARGS__)
#define rall(...) std::rbegin(__VA_ARGS__), std::rend(__VA_ARGS__)
template<class T, size_t n, size_t idx = 0>
auto make_vec(const size_t (&d)[n], const T& init) noexcept {
    if constexpr (idx < n) return std::vector(d[idx], make_vec<T, n, idx + 1>(d, init));
    else return init;
}

template<class T, size_t n>
auto make_vec(const size_t (&d)[n]) noexcept {
    return make_vec(d, T{});
}


int main() {
  int h, w, q;
  cin >> h >> w >> q;

  vector<vector<int>> grid(h, vector<int>(w, 1));

  auto clear_line = [&](int r, int c, int dr, int dc) {
      while (r >= 0 && r < h && c >= 0 && c < w) {
          if (grid[r][c] == 0){
          r += dr;
          c += dc;
          } else {
            grid[r][c] = 0;
            break;
          }
      }
  };

  while (q--) {
      int r, c;
      cin >> r >> c;
      r--; c--; // 0-indexed に変換

      if (grid[r][c] == 1) {
          grid[r][c] = 0;
      } else {
          clear_line(r, c, -1, 0); // 上方向
          clear_line(r, c, 1, 0);  // 下方向
          clear_line(r, c, 0, -1); // 左方向
          clear_line(r, c, 0, 1);  // 右方向
      }
  }

  int ans = 0;
  rep(i, h) {
      rep(j, w) {
          if (grid[i][j] == 1) ans++;
      }
  }

  cout << ans << endl;
  return 0;

}