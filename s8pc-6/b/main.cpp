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

  vector<P> buy(n);
  vector<P> ans;

  rep(i,n){
    int a,b;
    cin >> a >> b;
    buy[i] = {a,b};
  }

  rep(i,n){
    rep(j,n){
      int a = buy[i].first;
      int b = buy[j].second;
      ans.emplace_back(make_pair(a,b));
    }
  }

  vector<ll> sum(ans.size());

  rep(i,ans.size()){
    auto [a,b] = ans[i];
    ll res = 0;
    rep(j,n){
        int c = buy[j].first;
        int d = buy[j].second;
        res += abs(c - a) + abs(d - c) + abs(b - d);
    }
    sum[i] = res;
  }

  sort(all(sum));

  cout << sum[0] << endl;
  return 0;
}