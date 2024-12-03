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
  string s,t;
  cin >> s >> t;

  //i文字だけ変えた時を全列挙して一番小さいものを採用し続ける
  vector<string> ans;

  while(s != t){
    string ts = s;
    vector<string> x;
      rep(i,s.size()){
        char cs = ts[i];
        char ct = t[i];
        if(cs != ct){
          ts[i] = ct;
          x.push_back(ts);
        }
        ts = s;
      }

    sort(all(x));
    s = x[0];
    ans.push_back(s);
  }

  cout << ans.size() << endl;
  for(auto x:ans){
    cout << x << endl;
  }
  return 0;
}