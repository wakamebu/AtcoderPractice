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
  int n , k;
  cin >> n >> k;


  vector<int> check(n,-1);

  rep(i,k){
    int a, b;
    cin >> a >> b;
    b--; a--;
    check[a] = b;
  }

  //i日目、2個前、1個前
  vector<vector<vector<int>>> dp(n+1,vector<vector<int>>(3,vector<int>(3)));
  dp[0][0][0] = 1;

  for(int i = 0;i<n;i++){
    for(int j = 0;j<3;j++){
      for(int l = 0; l <3;l++ ){
        vector<int> cs = {0, 1, 2};
        if(check[i] != -1){
          cs = {check[i]};
        }
        for(int c :cs){
          if(i>= 2 and c == j and c == l)continue;
          dp[i+1][l][c] += dp[i][j][l];
          dp[i+1][l][c] %= 10000;
        }
      }
    }
  }
  ll ans = 0;
  rep(i,3){
    rep(j,3){
      ans += dp[n][i][j];
      ans %= 10000;
    }
  }

  cout << ans << endl;
  return 0;
}