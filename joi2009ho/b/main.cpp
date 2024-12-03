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
    ll d, n, m;
    cin >> d >> n >> m;

    vector<ll> shop(n);
    vector<ll> md(m);

    shop[0] = 0;
    rep(i, n - 1) cin >> shop[i + 1];
    rep(i, m) cin >> md[i];

    sort(all(shop));
    sort(all(md));

    shop.emplace_back(d); // add d as a shop location

    ll ans = 0;
    rep(i, m) {
        ll q = md[i];
        auto it = lower_bound(all(shop), q);
        ll res = LLONG_MAX;
        if (it != shop.end()) {
            res = min(res, abs(*it - q));
        }
        if (it != shop.begin()) {
            --it;
            res = min(res, abs(*it - q));
        }
        ans += res;
    }

    cout << ans << endl;
    return 0;
}