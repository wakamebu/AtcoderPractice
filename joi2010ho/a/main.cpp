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

const int mod = 1e5;

int main() {
  int n ,m;
  cin >> n >> m;

  vector<int> dist(n-1);
  rep(i,n-1)cin >> dist[i];

  vector<int> que(m);
  rep(i,m)cin >> que[i];

  vector<int> distsum(n,0);
  rep(i,n-1)distsum[i+1] = distsum[i] + dist[i];

  int now = 1;
  int total = 0;
  rep(i,m){
    int to = que[i] + now;
    if(to > now){
    total = (total + (distsum[to-1] - distsum[now-1])) % mod;
    now = to;
    }else{
      total = (total + (distsum[now-1] - distsum[to-1])) % mod;
      now = to;
    }
  }

  cout << total << endl;
  return 0;
}