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
#define MOD 998244353
template<class T, size_t n, size_t idx = 0>
auto make_vec(const size_t (&d)[n], const T& init) noexcept {
    if constexpr (idx < n) return std::vector(d[idx], make_vec<T, n, idx + 1>(d, init));
    else return init;
}

template<class T, size_t n>
auto make_vec(const size_t (&d)[n]) noexcept {
    return make_vec(d, T{});
}


int count_arithmetic_subsequences(vector<int>& A) {
    int N = A.size();
    vector<vector<int>> dp(N, vector<int>(N, 0));

    // 初期化：長さ 1 の等差数列は各要素自身
    for (int i = 0; i < N; ++i) {
        dp[0][i] = 1;
    }

    // 長さ k の等差数列の個数を計算する
    for (int k = 1; k < N; ++k) {
        for (int i = 0; i < N; ++i) {
            for (int j = i + 1; j < N; ++j) {
                int d = A[j] - A[i];
                // dp[k][j] に対して、dp[k-1][i] を足す
                dp[k][j] = (dp[k][j] + dp[k-1][i]) % MOD;
            }
        }
    }

    // 答えを格納する配列
    vector<int> answer(N);

    // dp の全ての要素の合計を求めて出力用の配列に格納する
    for (int k = 0; k < N; ++k) {
        int total_count = 0;
        for (int i = 0; i < N; ++i) {
            total_count = (total_count + dp[k][i]) % MOD;
        }
        answer[k] = total_count;
    }

    // 結果を出力
    for (int k = 0; k < N; ++k) {
        cout << answer[k] << " ";
    }
    cout << endl;
}

int main() {
    int N;
    cin >> N;

    vector<int> A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }

    count_arithmetic_subsequences(A);

    return 0;
}