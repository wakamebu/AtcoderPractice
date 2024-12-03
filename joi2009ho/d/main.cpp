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
  int m,n;
  cin >> m >> n;

  Graph G(n,vector<int>(m));
  rep(i,n)rep(j,m) cin >> G[i][j];

  vector<P> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
  int ans = 0;

  vector<vector<bool>> seen(n, vector<bool>(m, false)); 
    auto dfs = [&](auto dfs, int i, int j) -> int {
        seen[i][j] = true;
        int length = 0;
        for (auto u : directions) {
            int x = i + u.first;
            int y = j + u.second;
            if (x < 0 or y < 0 or x >= n or y >= m) continue;
            if (seen[x][y]) continue;
            if (G[x][y] == 0) continue;
            length = max(length,dfs(dfs,x,y));
        }
        seen[i][j] = false;
        return length + 1;
    };

  for (int i = 0; i < n; ++i) {
        rep(j, m) {
            if (G[i][j] == 0) continue;
            if (!seen[i][j]) {
                ans = max(ans,dfs(dfs,i,j));
            }
        }
    }


  cout << ans << endl;
  return 0;
}