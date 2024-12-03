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
    ll k;
    cin >> n >> k;

    vector<int> x(n);
    vector<int> a(n);
    rep(i,n)cin >> x[i] , x[i]--;
    rep(i,n)cin >> a[i];

    const int D = 60;
    vector<vector<int>> d(D,vector<int>(n));
    d[0] = x;
    rep(i,D-1){
        rep(v,n) d[i+1][v] = d[i][d[i][v]];
    }

    vector<int> ans(n);
    rep(i,n){
        int v = i;
        rep(j,D){
            if(k>>j&1) v = d[j][v];
            ans[i] = a[v];
        }
    }
        rep(i,n)cout << ans[i] << ' ';
        cout << endl;

    return 0;
}