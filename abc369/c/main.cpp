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
    vector<int> a(n);
    
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

  //長さ1をカウント
    ll result = n;

    int l = 0;
    while (l < n - 1) {
        int r = l + 1;
        int d = a[r] - a[l];

        // 等差数列の条件を満たす限り右端を進める
        while (r + 1 < n && a[r + 1] - a[r] == d) {
            r++;
        }

        int len = r - l + 1;
        if (len >= 2) {
            result += (ll)(len - 1) * (len) / 2;
        }
        l = r;
    }

    cout << result << endl;

    return 0;
}