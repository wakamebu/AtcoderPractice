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
  int n , m , q;
  cin >> n >> m >> q;


  vector<vector<int>> dp(n+1,vector<int>(n+1,0));

  rep(i,m){
    int l , r;
    cin >> l >> r;
    dp[l][r]++;
  }

  rep(l,1,n+1)rep(r,2,n+1) dp[l][r] += dp[l][r-1];

  rep(i,q){
    int l, r;
    cin >> l >> r;
    int ans = 0;
    rep(L,l,r+1) ans += dp[L][r];
    cout << ans << endl;
  }

  //各クエリの左右端をまたいでるものを省きたい

  return 0;
}