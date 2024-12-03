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
  int v,e;
  cin >> v >> e;

    vector<vector<int>> dp(v,vector<int>(v,INF));
    for(int i = 0; i<v;i++)for(int j= i;j<v;j++)if(i==j)dp[i][j] = 0;

    rep(i, e) {
        int from, to, cost;
        cin >> from >> to >> cost;
        from--; to--;
        dp[from][to] = cost;
        dp[to][from] = cost;
    }

    for(int k=0;k<v;k++){
        for(int i=0;i<v;i++){
            for(int j=0;j<v;j++){
                dp[i][j]=min(dp[i][j],dp[i][k]+dp[k][j]);
            }
        }
    }

    int ans = INF;
    for(int i = 0;i<v;i++){
      int res = 0;
      for(int j = 0; j<v; j++){
        res = max(res,dp[i][j]);
      }
      ans = min(ans,res);
    }

  cout << ans << endl;
  return 0;
}