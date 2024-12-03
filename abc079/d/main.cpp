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

const int INF = 1e9;

int main() {
  int h,w;
  cin >> h >> w;

  //0~9を0~9にするときにかかる最小の費用
  vector<vector<int>> dp(10,vector<int>(10,INF));
  for(int i = 0; i<10;i++)for(int j= i;j<10;j++)if(i==j)dp[i][j] = 0;
  rep(i,10)rep(j,10) cin >> dp[i][j];

  for(int k=0;k<10;k++){
        for(int i=0;i<10;i++){
            for(int j=0;j<10;j++){
                dp[i][j]=min(dp[i][j],dp[i][k]+dp[k][j]);
            }
        }
    }

  vector<vector<int>> wall(h,vector<int>(w,-1));
  rep(i,h)rep(j,w)cin >>wall[i][j];

  int ans = 0;
  rep(i,h)rep(j,w){
    int a  = wall[i][j];
    if(a == -1)continue;
    else ans += dp[a][1];
  }

  cout << ans << endl;
  return 0;
}