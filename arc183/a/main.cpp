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

// 重複を考慮して並び替えの数を計算する関数
long long countPermutations(const vector<int>& counts) {
    int total = accumulate(counts.begin(), counts.end(), 0);
    long long numerator = 1;
    for (int i = 1; i <= total; ++i) {
        numerator *= i;
    }
    long long denominator = 1;
    for (int count : counts) {
        long long factorial = 1;
        for (int i = 1; i <= count; ++i) {
            factorial *= i;
        }
        denominator *= factorial;
    }
    return numerator / denominator;
}

// 辞書順で pos 番目の数列を生成する関数
vector<int> findPermutation(int pos, vector<int> counts) {
    vector<int> result;
    int totalCount = accumulate(counts.begin(), counts.end(), 0);

    while (totalCount > 0) {
        long long perms = 0;
        for (int i = 0; i < counts.size(); ++i) {
            if (counts[i] > 0) {
                counts[i]--;
                perms = countPermutations(counts);
                counts[i]++;

                if (perms >= pos) {
                    result.push_back(i + 1);
                    counts[i]--;
                    break;
                }
                pos -= perms;
            }
        }
        totalCount--;
    }
    
    return result;
}

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> counts(n, k); // 各数字の出現回数
    
    long long s = countPermutations(counts);
    int pos = (s + 1) / 2;

    vector<int> ans = findPermutation(pos, counts);

    for (int num : ans) {
        cout << num << ' ';
    }
    cout << '\n';
    
    return 0;
}