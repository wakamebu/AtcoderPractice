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

bool found = false;
int final_N;
vector<int> final_A;

void backtrack(int current_N, ll current_sum, int M, vector<int>& A, vector<ll>& powers) {
    if (found) return; // 解が見つかっていれば終了

    if (current_sum == M) {
        found = true;
        final_N = current_N;
        final_A = A;
        return;
    }

    if (current_N == 20 || current_sum > M) {
        return;
    }

    // 残りの項数でMに達する可能性があるかをチェック
    // 最大で10の指数を使った場合の最大増加分を計算
    ll max_possible = current_sum;
    for(int i = 0; i < 20 - current_N; ++i){
        max_possible += powers[10];
    }
    if(max_possible < M){
        return;
    }

    // 3^10から3^0まで試す（大きいものから）
    for(int ai = 10; ai >= 0; --ai){
        ll next_sum = current_sum + powers[ai];
        if(next_sum > M) continue;
        A.push_back(ai);
        backtrack(current_N + 1, next_sum, M, A, powers);
        A.pop_back();
        if(found) return;
    }
}

int main(){
    int M;
    cin >> M;

    // 3^0 から 3^10 までの値を事前に計算
    vector<ll> powers(11, 1);
    for(int i = 1; i <=10; ++i){
        powers[i] = powers[i-1] * 3;
    }

    vector<int> A;
    backtrack(0, 0, M, A, powers);

    if(found){
        cout << final_N << "\n";
        for(auto ai : final_A){
            cout << ai << " ";
        }
    }
    else{
        // 問題の制約では必ず解が存在するとされています。
        // しかし念のため
        cout << -1 << "\n";
    }

    return 0;
}