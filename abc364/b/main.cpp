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

vector<P> directions = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}}; // U R D L

int main() {
  int h, w;
  cin >> h >> w;
  int si, sj;
  cin >> si >> sj;
  si--; sj--; // 0-indexedに変換

  vector<vector<char>> grid(h, vector<char>(w));
  rep(i, h) {
    rep(j, w) {
      cin >> grid[i][j];
    }
  }

  string s;
  cin >> s;

  rep(i, s.size()) {
    char c = s[i];
    int u;
    if (c == 'U') u = 0;
    if (c == 'R') u = 1;
    if (c == 'D') u = 2;
    if (c == 'L') u = 3;
    int x = si + directions[u].first;
    int y = sj + directions[u].second;
    if (x < 0 || y < 0 || x >= h || y >= w) continue; // 修正済みの境界チェック
    if (grid[x][y] == '#') continue; // 障害物のチェック
    si = x;
    sj = y;
  }

  cout << si + 1 << " " << sj + 1 << endl; // 1-indexedに戻して出力
  return 0;
}