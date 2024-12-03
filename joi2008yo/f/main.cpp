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

struct Edge {
    int to;
    int cost;
    Edge(int to, int cost) : to(to), cost(cost) {}
};

int main() {
  int n , k;
  cin >> n >> k;

  vector<vector<Edge>> g(n);
  rep(i,k){
    int a;
    cin >> a;
    if(a == 0){
      int b, c;
      cin >> b >> c;
      b--; c--;
      vector<int> dist(n,INF);
      priority_queue<P,vector<P>,greater<P>> q;
      dist[b] = 0;
      q.emplace(0,b);
      while(!q.empty()){
        auto[d,u] = q.top();
        q.pop();
        if(dist[u] != d)continue;
        for (auto e:g[u]){
          int nd = e.cost + d;
          if(nd < dist[e.to]){
            dist[e.to] = nd;
            q.emplace(nd,e.to);
          }
        }
      }
      if (dist[c] == INF)cout << -1 << endl;
      else cout << dist[c] << endl;
    } 
    else if(a == 1){
      int from , to ,cost;
      cin >> from >> to >> cost;
      from--; to--;
      g[from].emplace_back(to,cost);
      g[to].emplace_back(from,cost);
    }
  }

  return 0;
  }
