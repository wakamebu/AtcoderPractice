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

  vector<int> a(n);
  rep(i,n) cin >> a[i];


  // dp[i][0] は、i匹目のモンスターまでを考慮したときに、モンスターを倒した回数が偶数回の場合の経験値の最大値
  // dp[i][1] は、奇数回のときの最大値
  vector<vector<ll>> dp(n+1, vector<ll>(2, -1e18)); 
  dp[0][0] = 0;  

  rep(i, 1, n+1) {
    // 逃がす場合
    dp[i][0] = dp[i-1][0];
    dp[i][1] = dp[i-1][1];

    // 偶数回で倒す場合
    dp[i][0] = max({dp[i][0], dp[i-1][0] + 2 * a[i-1], dp[i-1][1] + a[i-1]});

    // 奇数回で倒す場合
    dp[i][1] = max({dp[i][1], dp[i-1][0] + a[i-1], dp[i-1][1] + 2 * a[i-1]});
  }

  ll ans = max(dp[n][0], dp[n][1]);
  cout << ans << endl;

  return 0;
}