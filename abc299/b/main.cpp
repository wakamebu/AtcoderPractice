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
  int n,t;
  cin >> n >> t;

  vector<int> c(n);
  vector<int> r(n);
  rep(i,n) cin >> c[i];
  rep(i,n) cin >> r[i];

  int first_color = c[0];
  int max_star = 0;
  int max_normal = 0;
  int winner = 0;
  int normal_winner = 0;
  rep(i,n){
    int color = c[i];
    int power = r[i];
    if(color == first_color)max_normal = max(power,max_normal);
    if(max_normal == power and color == first_color)normal_winner = i+1;
    if(color == t){
      max_star = max(power,max_star);
      if(max_star == power)winner = i+1;
    }
  }

  if(max_star != 0){
    cout << winner << endl;
  }else{
    cout << normal_winner << endl;
  }

  return 0;
}