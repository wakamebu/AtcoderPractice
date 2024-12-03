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


int N, MG, MH;
vector<vector<int>> G, H;
vector<vector<int>> A;

int main() {
    cin >> N;
    cin >> MG;
    G.assign(N, vector<int>(N, 0));
    for (int i = 0; i < MG; ++i) {
        int u, v;
        cin >> u >> v;
        --u; --v;
        G[u][v] = G[v][u] = 1;
    }
    //操作対象
    cin >> MH;
    H.assign(N, vector<int>(N, 0));
    for (int i = 0; i < MH; ++i) {
        int a, b;
        cin >> a >> b;
        --a; --b;
        H[a][b] = H[b][a] = 1;
    }
    //cost
    A.assign(N, vector<int>(N, 0));
    for (int i = 0; i < N; ++i) {
        for (int j = i + 1; j < N; ++j) {
            cin >> A[i][j];
            A[j][i] = A[i][j]; 
        }
    }

    vector<int> perm(N);
    iota(perm.begin(), perm.end(), 0);
    long long ans = LLONG_MAX;
    do {
        long long cost = 0;
        for (int i = 0; i < N; ++i) {
            for (int j = i + 1; j < N; ++j) {
                int u = perm[i], v = perm[j];
                if (G[i][j] != H[u][v]) {
                    cost += A[u][v];
                }
            }
        }
        ans = min(ans, cost);
    } while (next_permutation(perm.begin(), perm.end()));

    cout << ans << endl;
    return 0;
}