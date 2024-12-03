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
    vector<int> A(n);
    vector<int> B(n);
    vector<int> C(n);
    rep(i,n) cin >> A[i];
    rep(i,n) cin >> B[i];
    rep(i,n) cin >> C[i];

    sort(all(A));
    sort(all(B));
    sort(all(C));

    ll cnt = 0;
    rep(i, n) {
        int q = B[i];
        ll a = lower_bound(A.begin(),A.end(), q) - A.begin(); // A の中で q より小さい要素の数を求める
        ll c = n - (upper_bound(all(C), q) - C.begin()); // C の中で q より大きい要素の数を求める
        cnt += a*c;
    }

    cout << cnt << endl;
    return 0;
}