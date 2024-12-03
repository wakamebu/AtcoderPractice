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
    int N;
    cin >> N;
    vector<int> A(N);
    
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }
    
    // Prefix XOR array
    vector<int> prefixXOR(N + 1, 0);
    
    for (int i = 0; i < N; ++i) {
        prefixXOR[i + 1] = prefixXOR[i] ^ A[i];
    }
    
    long long result = 0;

    // 計算
    for (int i = 0; i < N - 1; ++i) {
        for (int j = i + 1; j < N; ++j) {
            int xor_sum = prefixXOR[j + 1] ^ prefixXOR[i];
            result += xor_sum;
        }
    }
    
    cout << result << endl;
    
    return 0;
}