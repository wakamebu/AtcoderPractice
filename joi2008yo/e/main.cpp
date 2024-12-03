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

  vector<vector<int>> senbei(n,vector<int>(m));
  rep(i,n)rep(j,m)cin >> senbei[i][j];

  int sum = 0;
  for(int mask = 0;mask<(1<<n);mask++){//それぞれの横串をひっくり返すかどうかで全検索
    vector<vector<int>> syukka(n,vector<int>(m));
    rep(i,n){
      if(mask & (1 << i)){
        syukka[i] = senbei[i];
        for(auto &a :syukka[i]){//ひっくり返す
          a = 1 -a;
        }
      }
      else{
        syukka[i] = senbei[i];
      }
    }
    vector<int> ans(m,0);
    rep(j,m){
      int cnt = 0;
      rep(i,n){
        if(syukka[i][j] == 1)cnt++;
      }
      ans[j] =cnt;
    }
    int res = 0;
        rep(j, m) {
            res += max(ans[j], n - ans[j]); // 表になる最大数を数える
        }
    sum = max(sum,res);
  }

  cout << sum << endl;
  return 0;
}