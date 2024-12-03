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

int N, K;
vector<int> R;

// 再帰的に数列を生成し、条件を満たすものを保存
void dfs(int idx, vector<int> &current, vector<vector<int>> &result) {
    if (idx == N) {
        int sum = accumulate(current.begin(), current.end(), 0);
        if (sum % K == 0) {
            result.push_back(current);
        }
        return;
    }
    
    for (int i = 1; i <= R[idx]; ++i) {
        current.push_back(i);
        dfs(idx + 1, current, result);
        current.pop_back();
    }
}

int main() {
    // 入力
    cin >> N >> K;
    R.resize(N);
    for (int i = 0; i < N; ++i) cin >> R[i];
    
    vector<vector<int>> result;
    vector<int> current;
    
    // 全ての可能な数列を生成して確認
    dfs(0, current, result);
    
    // 辞書順に並べ替え
    sort(result.begin(), result.end());
    
    // 結果を出力
    for (const auto &seq : result) {
        for (int i = 0; i < seq.size(); ++i) {
            cout << seq[i] << " ";
        }
        cout << endl;
    }
    
    return 0;
}