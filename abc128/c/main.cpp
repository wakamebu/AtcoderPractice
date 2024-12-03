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
  vector<int> light[10]; //電球配列を10個用意
  vector<int> swit(10); //スイッチ配列

  rep(i,m){
    int k;
    cin >> k;
    rep(j,k){
      int s;
      cin >> s;
      s--;
      light[i].emplace_back(s);
    }
  }

  rep(i,m){
    cin >> swit[i];
  }

  int ans = 0;
  for(int i = 0; i< (1<<n) ; i++){
    bool ok = true;
    for(int j = 0; j <m ; j++){
      int cnt = 0;
      for(auto s:light[j])if(i & (1<<s))cnt++;
      if (cnt %2 != swit[j]){
        ok = false;
        break;
      }
    }
    if(ok) ans ++;
  }

  cout << ans << endl;
  return 0;
}