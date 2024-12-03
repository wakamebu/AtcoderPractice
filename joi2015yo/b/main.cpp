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

    vector<int> pieces(n);
    rep(i,n) cin >> pieces[i];

    // dpテーブルの初期化
    vector<vector<int>> dp(2*n, vector<int>(2*n, 0));

    // dpテーブルを更新
    for(int len = 1; len <= n; ++len) { // 長さ
        for(int l = 0; l + len <= n; ++l) { // 左端
            int r = l + len - 1; // 右端
            if((n - len) % 2 == 1) { // IOIのターン
                if(l == r) {
                    dp[l][r] = 0;
                } else if(pieces[l] > pieces[r]) {
                    dp[l][r] = dp[l + 1][r];
                } else {
                    dp[l][r] = dp[l][r - 1];
                }
            } else { // JOIのターン
                if(l == r) {
                    dp[l][r] = pieces[l];
                } else {
                    dp[l][r] = max(dp[l + 1][r] + pieces[l], dp[l][r - 1] + pieces[r]);
                }
            }
        }
    }

    int ans = 0;
    for(int i = ; i < n; ++i) {
        ans = max(ans, dp[i][i + n - 1]);
    }

    cout << ans << endl;
    return 0;
}