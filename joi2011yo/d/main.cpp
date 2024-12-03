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
  int n , ans;
  cin >> n;
  vector<int> a(n-1);
  rep(i,0,n-1)cin >> a[i];
  cin >> ans;

  vector<vector<ll>> dp(n,vector<ll>(21,0));
  dp[0][a[0]] = 1;


    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j <= 20; j++) {
            if (dp[i][j] != 0) {
                if (j + a[i + 1] <= 20) {
                    dp[i + 1][j + a[i + 1]] += dp[i][j];
                }
                if (j - a[i + 1] >= 0) {
                    dp[i + 1][j - a[i + 1]] += dp[i][j];
                }
            }
        }
    }

    cout << dp[n - 2][ans] << endl;
}