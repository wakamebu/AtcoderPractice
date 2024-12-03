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
    int n, m;
    cin >> n >> m;

    vector<int> plan(m);
    rep(i, 0, m) cin >> plan[i], plan[i]--;

    vector<long long> sum(n, 0);  // n駅分の配列

    rep(i, 0, m - 1) {
        int now = plan[i];
        int next = plan[i + 1];
        if (next > now) {
            sum[now]++;
            if (next < n) sum[next]--;
        } else if (next < now) {
            sum[next]++;
            if (now < n) sum[now]--;
        }
    }

    rep(i, 1, n) sum[i] += sum[i - 1];

    long long ans = 0;  // long long 型で合計を保持
    rep(i, 0, n - 1) {
        long long a, b, c;
        cin >> a >> b >> c;
        ans += min(a * sum[i], b * sum[i] + c);
    }

    cout << ans << endl;
    return 0;
}