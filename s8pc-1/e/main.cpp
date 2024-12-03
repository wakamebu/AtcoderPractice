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

ll modpow(ll a, ll n, ll mod) {
    ll res = 1;
    while (n > 0) {
        if (n & 1) res = res * a % mod;
        a = a * a % mod;
        n >>= 1;
    }
    return res;
}

ll mod = 1000000007;

int main() {
    ll n, m;
    cin >> n >> m;

    vector<ll> A(n);
    vector<int> q(m);

    rep(i, n) cin >> A[i];
    rep(i, m) {
        int a;
        cin >> a;
        a--;
        q[i] = a;
    }
    q.push_back(0);

    vector<ll> road(n - 1);
    rep(i, n - 1) {
        road[i] = modpow(A[i], A[i + 1], mod);
    }

    vector<ll> sum(n);
    sum[0] = 0;
    rep(i, n - 1) {
        sum[i + 1] = (sum[i] + road[i]) % mod;
    }

    int now = 0;
    ll res = 0;
    rep(i, m + 1) {
        int to = q[i];
        if (now < to) {
            res = (res + sum[to] - sum[now] + mod) % mod;
        } else if (now > to) {
            res = (res + sum[now] - sum[to] + mod) % mod;
        }
        now = to;
    }

    cout << res % mod << endl;
    return 0;
}
