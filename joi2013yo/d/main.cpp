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
  int d,n;
  cin >> d >> n;

  vector<int> temp(d+1);
  rep(i,1,d+1)cin >> temp[i];
  vector<P> com(n,{0,0});
  vector<int> fla(n,0);
  rep(i,n){
    int a , b, c;
    cin >> a  >> b >> c;
    com[i] = {a,b};
    fla[i] = c;
  }

  auto check = [&](int d , P a){
    auto [b,c] = a;
    if(temp[d] > c) return false;
    if(temp[d] < b) return false;
    return true;
  };

  //dp[i][j]はi日目にjを着たときの最大値
  vector<vector<int>> dp(d+1,vector<int>(n+1,0));
    rep(j,n){
      if(!check(1,com[j])) dp[1][j] = 100000*(-1);
  }

  for (int i = 2; i <= d; ++i) {
        for (int j = 0; j < n; ++j) {
            for(int k = 0; k < n; ++k){
              if(check(i,com[j])){
                dp[i][j] = max(dp[i][j],dp[i-1][k] + abs(fla[k] - fla[j]));
              }
              else dp[i][j] = 100000*(-1);
            }
        }
    }

  int anc = 0;
  for(int i = 0; i< n;i++){
    anc = max(anc,dp[d][i]);
  }

  cout << anc << endl;
  return 0;
}