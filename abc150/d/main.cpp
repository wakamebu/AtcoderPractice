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
  int n,m;
  cin >> n >> m;
  vector<int> a(n);
  rep(i,n) cin >> a[i];
  set<ll> ans;
  set<int> check;

  //最後に0.5倍分を足す用の配列
  vector<int> half;
  rep(i,n){
    int original = a[i];
    int halfed = original / 2;
    if(check.find(halfed) != check.end())half.push_back(halfed);
  }
  sort(all(half));

  ll res = 1;
  rep(i,n){
    if(res != half[i])res *= half[i];
    else continue;
  }
  if(res <= m)ans.insert(res);

  int flag =  m / res;
  
  int cnt = 0;
  while(res <= m){
    rep(i,n){
      res *= half[i];
      if(res <= m)ans.insert(res);
      res /= half[i];
    }
    if(cnt < n){
      res *= half[cnt];
      cnt++;
    }
  }

  cout << ans.size() << endl;
  return 0;
}