//これ丸写し
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
    ll n, m, k;
    cin >> n >> m >> k;
    // point, index
    vector<ll> A(n);
    rep(i,n) cin >> A[i];

    if(n == m){
        rep(i,n) cout << 0 << ' ';
        cout << endl;
        return 0;
    }

    vector<ll> a = A;
    sort(all(a));
    vector<ll> s(n+1);
    rep(i,n) s[i+1] = s[i] + a[i];

    ll remain = k;
    rep(i,n) remain -= a[i];

    map<int,ll> ans;

    rep(i,n){
        auto judge = [&](ll x){
            ll y = a[i] + x;
            int r = upper_bound(all(a),y+1) - a.begin();
            int l = n - m;
            if(r < l) return false;
            ll need = (y+1)*(r-l) - (s[r]-s[l]);
            if(l <= i && i < r){
                need += a[i];
                need -= a[l-1];
            }
            return need > remain - x;
        };

        ll ac = remain+1, wa = -1;
        while(ac-wa >1){
            ll wj = (ac + wa)/2;
            if(judge(wj)) ac = wj; else wa = wj;
        }
        if(ac == remain+1) ac = -1;
        ans[a[i]] = ac;
    }

    rep(i,n) cout << ans[A[i]] << ' ';
    cout << endl;

    return 0;
}
