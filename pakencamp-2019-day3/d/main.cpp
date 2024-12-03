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
  vector<vector<int>> grid(5,vector<int>(n));
  rep(i,5)rep(j,n){
    char c;
    cin >> c;
    if(c == 'B')grid[i][j] = 0;
    if(c == 'R')grid[i][j] = 1;
    if(c == 'W')grid[i][j] = 2;
    if(c == '#')grid[i][j] = -1;
    // Blue Red White #lack
  }

  vector<int> color = {0,1,2}; //0 = Blue 1 = Red 2 = White
  //転置用配列
  vector<vector<int>> vgrid(n, vector<int>(5));
  for (int i = 0; i < 5; ++i) {
        for (int j = 0; j < n; ++j) {
            vgrid[j][i] = grid[i][j];
        }
    }

  //i列目がj色だった場合のそこまでの最短操作数
  vector<vector<int>> dp(n,vector<int>(3,1e9));
  for(int cs :color){
      int cnt = 0;
    rep(i,5){
      if(vgrid[0][i] != cs)cnt++;
    }
    dp[0][cs] = cnt;
  }

  for(int i = 1;i< n;i++){
    for(int cs :color){
      for(int k:color){
        if(k == cs)continue;
        int cnt = 0;
          rep(j,5){
            if(vgrid[i][j] != cs)cnt++;
          }
        dp[i][cs] = min(dp[i][cs], dp[i-1][k] + cnt);
      }
    }
  }

  int ans = 1e9;
  for(int k : color){
    ans = min(ans,dp[n-1][k]);
  }

  cout << ans << endl;
  return 0;
}