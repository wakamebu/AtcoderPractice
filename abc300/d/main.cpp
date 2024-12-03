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

//エラトステネス
struct Sieve {
  int n;
  vector<int> f, primes;
  Sieve(int n = 1):n(n),f(n+1){
    f[0] = f[1] = -1;
    for(ll i = 2; i <= n ; ++i){
      if(f[i]) continue;
      primes.push_back(i);
      f[i] = i;
      for(ll j = i*i ; j <= n ; j+= i){
        if(!f[j]) f[j] = i;
      }
    }
  }
};

int main() {
  ll n;
  cin >> n;
  Sieve p(1e6);
  int ans = 0;

  int m = p.primes.size();
  rep(ai,m){
    ll a = p.primes[ai];
    if((ll)a*a*a*a*a > n) break;
    for (int bi = ai + 1 ; bi < m ; bi++){
      ll b = p.primes[bi];
      if ((ll)a*a*b*b*b > n)break;
      for(int ci = bi+1 ; ci < m ; ci++){
        ll c = p.primes[ci];
        if(a*a*b*c*c > n) break;
        ans++;
      }
    }
  }

  cout << ans << endl;
  return 0;
}