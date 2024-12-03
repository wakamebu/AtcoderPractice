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

using mint = atcoder::modint998244353;
int mod = 998244353;

ll N;
  //dp(n) : (持っている数がn である状態からスタートしたときに, 最終的に持っている数がN に一致する確率)
  mint dp(ll n);
  //dp(n)= 1/5(dp(2n)+dp(3n)+dp(4n)+dp(5n)+dp(6n))

  map<long long, mint> memo;
  mint dp(ll n){
    if(n >= N) return n == N ? 1:  0;
    if(memo.count(n)) return memo[n];
    mint res = 0;
    for (int i = 2; i<= 6 ; i++)res+= dp(i*n);
    return memo[n] = res/5;
  }
int main() {
  cin >> N;
  cout << dp(1).val() << endl;
  return 0;
}