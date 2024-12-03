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
  vector<P> city(n);
  rep(i,n){
    int a,b;
    cin >> a >> b;
    city[i] = {a,b};
  }

  sort(all(city));

  long double sum = 0;
  int count = 0;
  do{
    rep(i,n-1){
      auto [a,b] = city[i];
      auto [c,d] = city[i+1];
      long double dx = a-c;
      long double dy = b-d;
      sum+= hypot(dx,dy);
    }
    count ++;
  }while(next_permutation(all(city)));


  long double average = sum / count;
  cout << setprecision(10) << average << endl;

  return 0;
}