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
  int h,w;
  ll k,v;
  cin >> h >> w >> k >> v;

  vector<vector<ll>> grid(h,vector<ll>(w,0));
  vector<vector<ll>> sum(h+1,vector<ll>(w+1,0));
  rep(i,h)rep(j,w)cin >> grid[i][j];
  //累積和
  rep(i,1,h+1)rep(j,1,w+1){
    sum[i][j] = grid[i-1][j-1] + sum[i-1][j] + sum[i][j-1] - sum[i-1][j-1];
  }

  int ans = 0;
  for(int i1 = 1; i1 <= h ; i1++){
    for(int j1 = 1; j1 <=w ; j1++){
      for(int i2 = i1; i2 <= h ; i2++){
        for(int j2 = j1 ; j2<=w ; j2++){
          ll areacost = sum[i2][j2]- sum[i1-1][j2] - sum[i2][j1-1] + sum[i1-1][j1-1];
          ll total = areacost + (i2 - i1 + 1) * (j2 - j1 +1) * k;
          if(total <= v){
            int area = (i2-i1+1) * (j2 - j1 +1);
            ans = max(ans,area);
          }
        }
      }
    }
  } 

  cout << ans << endl;
  return 0;
}