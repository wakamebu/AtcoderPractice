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

int main() {
    int n, q;
    cin >> n >> q;

    Graph g(n);
    rep(i, n - 1) { // n-1 because there are n-1 edges in a tree
        int from, to;
        cin >> from >> to;
        from--;
        to--;
        g[from].emplace_back(to);
        g[to].emplace_back(from); // assuming the graph is undirected
    }

    vector<int> point(n, 0);

    rep(i, q) {
        int a, b;
        cin >> a >> b;
        a--;
        point[a] += b;
    }

    vector<bool> seen(n, false);
    auto dfs = [&](auto dfs, int v) -> void {
        seen[v] = true;
        for (int u : g[v]) {
            if (seen[u]) continue;
            point[u] += point[v];
            dfs(dfs, u);
        }
    };

    dfs(dfs, 0);

    rep(i, n) {
        cout << point[i] << endl;
    }

    return 0;
}