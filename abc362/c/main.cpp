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


bool findX(const vector<pair<int, int>>& ranges, vector<int>& X, int N) {
    long long min_sum = 0;
    long long max_sum = 0;

    // 各範囲の最小値と最大値の合計を計算
    for (int i = 0; i < N; ++i) {
        min_sum += ranges[i].first;
        max_sum += ranges[i].second;
    }

    // 合計が0になり得るかをチェック
    if (min_sum > 0 || max_sum < 0) {
        return false;
    }

    // 初期化：各 X[i] を最小値に設定
    for (int i = 0; i < N; ++i) {
        X[i] = ranges[i].first;
    }

    long long current_sum = min_sum;

    // 合計が0になるように調整
    for (int i = 0; i < N; ++i) {
        if (current_sum == 0) {
            break;
        }

        ll sec = ranges[i].second;
        ll fis = ranges[i].first;
        ll increase = min(sec - fis, 0 - current_sum);
        X[i] += increase;
        current_sum += increase;
    }

    return current_sum == 0;
}

int main() {
    int N;
    cin >> N;

    vector<pair<int, int>> ranges(N);
    vector<int> X(N);

    for (int i = 0; i < N; ++i) {
        cin >> ranges[i].first >> ranges[i].second;
    }

    if (findX(ranges, X, N)) {
    cout << "Yes" << endl;
        for (int i = 0; i < N; ++i) {
            cout << X[i] << " ";
        }
        cout << endl;
    } else {
        cout << "No" << endl;
    }

    return 0;
}