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
    int n, m;
    cin >> n >> m;
    vector<int> road(n);
    rep(i, n) cin >> road[i];
    vector<int> weather(m);
    rep(i, m) cin >> weather[i];

    // i番目の都市にj日目でたどり着いたときの最小の疲労度
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 1e9));
    dp[0][0] = 0;

    for (int i = 1; i <= n; ++i) {
        for (int j = i; j <= m; ++j) {
            for (int k = 0; k < j; ++k) {
                dp[i][j] = min(dp[i][j], dp[i - 1][k] + weather[j - 1] * road[i - 1]);
            }
        }
    }

    int ans = 1e9;
    for (int j = n; j <= m; ++j) {
        ans = min(ans, dp[n][j]);
    }

    cout << ans << endl;

    return 0;
}