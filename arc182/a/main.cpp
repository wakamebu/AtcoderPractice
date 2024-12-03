#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using ll = long long;
using P = pair<int, int>;
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

int main() {
    int N, Q;
    cin >> N >> Q;
    vector<int> P(Q), V(Q);
    for (int i = 0; i < Q; i++) {
        cin >> P[i] >> V[i];
    }

    vector<int> tst(N, 0);
    vector<vector<int>> dp(Q, vector<int>(2, -1));

    ll res1 = 0;
    ll res2 = 0;

    for(int i = 0; i < Q; i++) {
        int a = P[i];
        int b = V[i];
        tst[a] = b;
        bool can1 = true;
        bool can2 = true;
        for(int j = 0; j <= a; j++) {
            if(tst[j] > b) can1 = false;
        }
        for(int j = a; j < N; j++) {
            if(tst[j] > b) can2 = false;
        }
        if(can1) dp[i][0] = 1;
        if(can2) dp[i][1] = 1;
    }

    if(dp[Q-1][0] != -1) res1 += 1;
    for(int i = 0; i < Q; i++) {
        int cnt = 0;
        for(int j = 0; j < 2; j++) {
            if(dp[i][j] == -1) cnt++;
        }
        if(cnt == 0) res1 *= 2;
        if(cnt == 2) res1 = 0;
    }

    if(dp[Q-1][1] != -1) res2 += 1;
    for(int i = 0; i < Q; i++) {
        int cnt = 0;
        for(int j = 0; j < 2; j++) {
            if(dp[i][j] == -1) cnt++;
        }
        if(cnt == 0) res2 *= 2;
        if(cnt == 2) res2 = 0;
    }

    cout << (res1 + res2) % MOD << endl;
    return 0;
}
