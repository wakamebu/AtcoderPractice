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

const int MOD = 998244353;


struct SegmentTree {
    int n;
    vector<int> tree;

    SegmentTree(int size) {
        n = size;
        tree.assign(2 * n, 0);
    }

    void update(int pos, int value) {
        pos += n;
        tree[pos] = value;
        for (pos /= 2; pos > 0; pos /= 2) {
            tree[pos] = max(tree[2 * pos], tree[2 * pos + 1]);
        }
    }

    int query(int l, int r) {
        l += n;
        r += n;
        int res = 0;
        while (l < r) {
            if (l % 2 == 1) res = max(res, tree[l++]);
            if (r % 2 == 1) res = max(res, tree[--r]);
            l /= 2;
            r /= 2;
        }
        return res;
    }
};

int main() {
    int N, Q;
    cin >> N >> Q;
    vector<int> P(Q), V(Q);
    for (int i = 0; i < Q; ++i) {
        cin >> P[i] >> V[i];
    }

    SegmentTree seg_tree(N);
    vector<ll> dp(Q + 1, 0);
    dp[0] = 1;

    for (int i = 1; i <= Q; ++i) {
        int p = P[i - 1];
        int v = V[i - 1];
        
        // 前半部分の最大値をチェック
        bool can_left = seg_tree.query(0, p) <= v;
        // 後半部分の最大値をチェック
        bool can_right = seg_tree.query(p - 1, N) <= v;

        if (can_left && can_right) {
            dp[i] = (dp[i] + dp[i - 1]) % MOD;
            seg_tree.update(p - 1, v);
        } else if (can_left) {
            dp[i] = dp[i - 1];
            seg_tree.update(p - 1, v);
        } else if (can_right) {
            dp[i] = dp[i - 1];
            seg_tree.update(p - 1, v);
        } else {
            dp[i] = 0;
            break;
        }
    }

    cout << dp[Q] << endl;
    return 0;
}