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

struct Edge{
  int to;
  int weight;
};

int main() {
  int n,m;
  cin >> n >> m;
  vector<vector<Edge>> G(n);

  rep(i, m) {
    int from, to, weight;
    cin >> from >> to >> weight;
    --from; --to;
    G[from].emplace_back(to,weight);
    G[to].emplace_back(from,-weight);
  }
  
  vector<bool> seen(n,false);
  vector<ll> ans(n,LLONG_MAX);
  
  auto dfs = [&](auto dfs,int v)-> void{
    seen[v] = true;
    for(auto e : G[v]){
      if(seen[e.to]) continue;
      if(ans[e.to] == LLONG_MAX){
        ans[e.to] = (ll)e.weight + ans[v];
      }
      dfs(dfs,e.to);
    }
  };

  rep(i,n){
    if(seen[i]) continue;
    if(ans[i] == LLONG_MAX)ans[i] = 0;
    dfs(dfs,i);
  }

  rep(i,n){
    cout << ans[i] << " ";
  }

  return 0;
}