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
  int h,w;
  cin >> h >> w;

  vector<vector<char>> G(h,vector<char>(w));
  rep(i,h)rep(j,w)cin >> G[i][j];

  vector<vector<char>> G2(h+2,vector<char>(w+1,'.'));
  for(int i = 1;i<h+1;i++){
    for(int j = 1;j<w+1;j++){
      G2[i][j] = G[i-1][j-1];
    }
  }

  vector<P> directions = {{1, 1}, {1, -1}, {-1, 1}, {-1, -1}};
  vector<int> ans(min(h, w), 0);

    for (int i = 1; i <= h; ++i) {
        for (int j = 1; j <= w; ++j) {
            if (G2[i][j] == '#') {
                int k = 0;
                while (true) {
                    bool isCross = true;
                    for (auto [dx, dy] : directions) {
                        int ni = i + (k + 1) * dx;
                        int nj = j + (k + 1) * dy;
                        if (ni < 1 || ni > h || nj < 1 || nj > w || G2[ni][nj] != '#') {
                            isCross = false;
                            break;
                        }
                    }
                    if (isCross) ++k;
                    else break;
                }
                if (k > 0) ++ans[k - 1];
            }
        }
    }

    for (int a : ans) cout << a << " ";
    cout << endl;

    return 0;
}