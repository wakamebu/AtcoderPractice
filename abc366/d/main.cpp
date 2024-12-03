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
    int n;
    cin >> n;
    vector<vector<vector<ll>>> x(n + 1, vector<vector<ll>>(n + 1, vector<ll>(n + 1)));
    
    // 入力の読み取り
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            for (int k = 1; k <= n; ++k) {
                cin >> x[i][j][k];
            }
        }
    }

    // 累積和の計算
    vector<vector<vector<ll>>> sums(n + 1, vector<vector<ll>>(n + 1, vector<ll>(n + 1, 0)));
    
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            for (int k = 1; k <= n; ++k) {
                sums[i][j][k] = x[i][j][k]
                              + (i > 1 ? sums[i - 1][j][k] : 0)
                              + (j > 1 ? sums[i][j - 1][k] : 0)
                              + (k > 1 ? sums[i][j][k - 1] : 0)
                              - (i > 1 && j > 1 ? sums[i - 1][j - 1][k] : 0)
                              - (i > 1 && k > 1 ? sums[i - 1][j][k - 1] : 0)
                              - (j > 1 && k > 1 ? sums[i][j - 1][k - 1] : 0)
                              + (i > 1 && j > 1 && k > 1 ? sums[i - 1][j - 1][k - 1] : 0);
            }
        }
    }

    int q;
    cin >> q;

    while (q--) {
        int lx, rx, ly, ry, lz, rz;
        cin >> lx >> rx >> ly >> ry >> lz >> rz;

        ll result = sums[rx][ry][rz]
                  - (lx > 1 ? sums[lx - 1][ry][rz] : 0)
                  - (ly > 1 ? sums[rx][ly - 1][rz] : 0)
                  - (lz > 1 ? sums[rx][ry][lz - 1] : 0)
                  + (lx > 1 && ly > 1 ? sums[lx - 1][ly - 1][rz] : 0)
                  + (lx > 1 && lz > 1 ? sums[lx - 1][ry][lz - 1] : 0)
                  + (ly > 1 && lz > 1 ? sums[rx][ly - 1][lz - 1] : 0)
                  - (lx > 1 && ly > 1 && lz > 1 ? sums[lx - 1][ly - 1][lz - 1] : 0);

        cout << result << endl;
    }
  return 0;
}