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
  int t;
  cin >> t;
  while(t--){
    int n,k;
    cin >> n >> k;
    vector<vector<ll>> dp(n + 1, vector<ll>((1 << k), 0));

    for (int i = 1; i <= n; ++i) {
            for (int j = 1; j < (1 << k); ++j) {
                dp[i][j] = dp[i - 1][j];  // jを使わない場合

                // jを使う場合、スコアを最大化する
                ll max_score = 0;
                for (int k = 0; (1 << k) <= j; ++k) {
                    max_score = max(max_score, dp[i - 1][j / (1 << k)] + j / (1 << k));
                }

                dp[i][j] = max(dp[i][j], max_score);
            }
        }
  ll result = 0;
  
        for (int j = 1; j < (1 << k); ++j) {
            result = max(result, dp[n][j]);
        }

        cout << result << endl;
  }
  return 0;
}