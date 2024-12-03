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

bool comparePairs(const pair<int, int>& a, const pair<int, int>& b) {
    if (a.first == b.first) {
        return a.second < b.second;
    }
    return a.first < b.first;
}

bool isSubarrayBinarySearch(const vector<pair<int, int>>& A, vector<pair<int, int>>& B) {
    // Bをソート
    sort(B.begin(), B.end(), comparePairs);

    // Aの各要素がBに存在するかを二分探索で確認
    for (const auto& elem : A) {
        if (!binary_search(B.begin(), B.end(), elem, comparePairs)) {
            return false;
        }
    }
    return true;
}


int main() {
    // 目的星座と写真入力
    int m;
    cin >> m;
    vector<P> A(m);
    rep(i, m) {
        int a, b;
        cin >> a >> b;
        A[i] = {a, b};
    }
    int n;
    cin >> n;
    vector<P> B(n);
    rep(i, n) {
        int a, b;
        cin >> a >> b;
        B[i] = {a, b};
    }

    sort(all(B));

    // Bの各点からAの各点へのシフトを計算し、そのシフト量でA全体を動かす
    rep(i, n) {
        int dx = B[i].first - A[0].first;
        int dy = B[i].second - A[0].second;
        vector<P> shiftedA(m);
        rep(j, m) {
            shiftedA[j] = {A[j].first + dx, A[j].second + dy};
        }
        sort(all(shiftedA));
        if (isSubarrayBinarySearch(shiftedA, B)) {
            cout << dx << " " << dy << endl;
            return 0;
        }
    }

    cout << -1 << endl;
    return 0;
}