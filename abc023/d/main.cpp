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
const long long INF = 1LL << 60;

int main() {
    int N;
    cin >> N;
    vector<long long> h(N), s(N);
    for (int i = 0; i < N; i++) cin >> h[i] >> s[i];
    long long left = 0, right = INF;
    while (right - left > 1) {
        long long mid = (left + right) / 2;
        bool ok = true;
        vector<long long> t(N, 0);
        for (int i = 0; i < N; i++) {
            if (mid < h[i]) ok = false;
            else t[i] = (mid - h[i]) / s[i];
        }
        sort(t.begin(), t.end());
        for (int i = 0; i < N; i++) {
            if (t[i] < i) ok = false;
        }
        if (ok) right = mid;
        else left = mid;
    }
    cout << right << endl;
    return 0;
}