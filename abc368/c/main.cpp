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
    vector<int> h(n);
    
    rep(i, n) cin >> h[i];

    ll ans = 0;
    int T = 1;
    for (int i = 0; i < n; ++i) {
        ll res = h[i];
        
        // 体力が5で割り切れる回数を計算
        ll full_five_chunks = res / 5;
        // 残りの体力
        int rem = res % 5;
        
        ans += full_five_chunks * 3;
        // 残りの体力が3で割り切れる場合は3減らす
        while(rem > 0){
          if(T %3 == 0) {
            rem -= 3;
            ans += 1;  // 3の体力を消費するのに1回の処理を加算
            T++;
          } else {
            rem--;
            ans += 1;  // 1の体力を消費するのに1回の処理を加算
            T++;
          }
        }
    }

    cout << ans << endl;
    return 0;
}