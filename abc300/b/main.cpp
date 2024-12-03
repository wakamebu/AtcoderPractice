#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using ll = long long;
using P = pair<int, int>;
using Graph = vector<vector<int>>;
#define OVERLOAD_REP(_1, _2, _3, name, ...) name
#define REP1(i, n) for (auto i = std::decay_t<decltype(n)>{}; (i) != (n); ++(i))
#define REP2(i, l, r) for (auto i = (l); (i) != (r); ++(i))
#define rep(...) OVERLOAD_REP(__VA_ARGS__, REP2, REP1)(__VA_ARGS__)
#define all(...) std::begin(__VA_ARGS__), std::end(__VA_ARGS__)
#define rall(...) std::rbegin(__VA_ARGS__), std::rend(__VA_ARGS__)

template <class T, size_t n, size_t idx = 0>
auto make_vec(const size_t (&d)[n], const T &init) noexcept {
    if constexpr (idx < n)
        return std::vector(d[idx], make_vec<T, n, idx + 1>(d, init));
    else
        return init;
}

template <class T, size_t n>
auto make_vec(const size_t (&d)[n]) noexcept {
    return make_vec(d, T{});
}

int main() {
  int H, W;
  cin >> H >> W;
  vector<string> A(H), B(H);
  for (auto& x : A) cin >> x;
  for (auto& x : B) cin >> x;
  for (int s = 0; s < H; s++) {
    for (int t = 0; t < W; t++) {
      int ok = 1;
      for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
          if (A[(i - s + H) % H][(j - t + W) % W] != B[i][j]) ok = 0;
        }
      }
      if (ok) {
        cout << "Yes" << endl;
        exit(0);
      }
    }
  }
  cout << "No" << endl;
}
