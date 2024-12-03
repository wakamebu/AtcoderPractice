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

const ll INF = 1e18;

struct edge{
  int from;
  int to;
  ll cost;
  bool operator<(const edge& e) const {return this->cost<e.cost;}
};

int main() {
  int n;
  cin >> n;

  int e = n*n;
  vector<edge> edges(e);
  int it = 0;

//更新済みのDPテーブルが渡される。正しいかどうかを判定する

  rep(i,n)rep(j,n){
    ll a;
    cin >> a;
    edges[it].from = i;
    edges[it].to = j;
    edges[it].cost = a;
    it++;
  }

  sort(all(edges));

  vector<vector<ll>> dp(n, vector<ll>(n, INF));
  rep(i,n)rep(j,n){
    if(i == j)dp[i][j] = 0;
  }

  ll ans = 0;

//コストの小さい順に辺を見ていき、今のワーシャルフロイドテーブルで説明可能かどうかを試す
  for(int idx = 0; idx < e; idx++){
    int i = edges[idx].from;
    int j = edges[idx].to;
    ll A = edges[idx].cost;
    for(int k = 0; k < n; k++){
      dp[i][j] = min(dp[i][j] ,dp[i][k]+dp[k][j]);
    }
    if(A == dp[i][j])continue;
    else if(A < dp[i][j]){//Aを採用
      dp[i][j] = A;
      dp[j][i] = A;
      ans += A;
    }
    else if(A > dp[i][j]){
      ans = -1;
      break;
    }
  }

  cout << ans << endl;
  return 0;
}