#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using ll = long long;
using P = pair<int,int>;
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
  int n,m,h,k;
  cin >> n >> m >> h >> k;
  string s;
  cin >> s;

  vector<P> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

  vector<int> d(n);
  rep(i,n){
    if(s[i] == 'U') d[i] =0;
    if(s[i] == 'R') d[i] =1;
    if(s[i] == 'D') d[i] =2;
    if(s[i] == 'L') d[i] =3;
  }

  map<P,int> item;
  rep(i,m){
    int x ,y;
    cin >> x >> y;
    item[make_pair(x,y)] ++;
  }

  int x = 0;
  int y = 0;
  rep(i,n){
    int dir = d[i];
    x += directions[dir].first;
    y += directions[dir].second;
    h--;
    if(h < 0){cout << "No" << endl;return 0;}
    if(h <= k){
      if(item[make_pair(x,y)] > 0){
        item[make_pair(x,y)] --;
        h = k;
      }
    }
  }

  cout << "Yes" << endl;
  return 0;
}