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

    vector<ll> x(n);
    vector<ll> p(n);

    for(int i = 0; i < n; ++i) cin >> x[i];
    for(int i = 0; i < n; ++i) cin >> p[i];

    vector<ll> sums(n + 1, 0);
    for(int i = 0; i < n; ++i) {
        sums[i + 1] = sums[i] + p[i];
    }

    int q;
    cin >> q;

    while(q--){
        ll ans = 0;
        ll l, r;
        cin >> l >> r;

        auto lit = lower_bound(x.begin(), x.end(), l);
        auto rit = upper_bound(x.begin(), x.end(), r);

        int idx_l = lit - x.begin();
        int idx_r = rit - x.begin();

        ans = sums[idx_r] - sums[idx_l];
        cout << ans << endl;
    }

    return 0;
}