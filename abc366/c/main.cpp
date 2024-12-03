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
    int q;
    cin >> q;

    map<int, int> bag;
    int non_zero_count = 0;  // 1以上のカウントがある要素数

    for (int i = 0; i < q; ++i) {
        int a;
        cin >> a;
        if (a == 1) {
            int x;
            cin >> x;
            if (bag[x] == 0) non_zero_count++;
            bag[x]++;
        } else if (a == 2) {
            int x;
            cin >> x;
            if (bag[x] > 0) {
                bag[x]--;
                if (bag[x] == 0) non_zero_count--;
            }
        } else if (a == 3) {
            cout << non_zero_count << endl;
        }
    }

    return 0;
}