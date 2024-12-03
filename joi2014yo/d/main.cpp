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

// i 日目に j 状態だった時の累積通り数
ll dp[1009][8];
const int MOD = 10007;

int main()
{
    int N ;
    string S;
    cin >> N >> S;
    // 初期値
    for (int j = 0; j < 8; j++)
    {
        dp[0][j] = 0;
    }
    dp[0][1] = 1; // 最初の日はJが必須

    // bitDP
    for (int i = 1; i <= N; i++)
    {
        ll tantou = 0;
        if (S[i-1] == 'J') tantou = 0;
        else if (S[i-1] == 'O') tantou = 1;
        else if (S[i-1] == 'I') tantou = 2;
        
        for (int j = 0; j < 8; j++) // 当日の参加状況
        {
            // 必須参加者がいなければcontinue
            if (!(j & (1 << tantou))) continue;
            for (int k = 0; k < 8; k++) // 前日の参加状況
            {
                // 前日に参加したメンバーが1人もいなければcontinue
                if (!(k & j)) continue;
                dp[i][j] = (dp[i][j] + dp[i - 1][k]) % MOD;
            }
        }
    }

    // 出力
    ll ans = 0;
    for (int j = 0; j < 8; j++)
    {
        ans = (ans + dp[N][j]) % MOD;
    }
    cout << ans << endl;
    return 0;
}