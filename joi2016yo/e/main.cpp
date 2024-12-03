#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using ll = long long;
using P = pair<int, int>;
using Graph = vector<vector<int>>;
using pl = pair<ll, int>;
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
    int n, m, k, s;
    cin >> n >> m >> k >> s;

    int p, q;
    cin >> p >> q;

    vector<int> zombie(k);
    set<int> zom;
    rep(i, k) {
        int a;
        cin >> a;
        a--;
        zombie[i] = a;
        zom.insert(a);
    }

    vector<vector<int>> edge(n);
    rep(i, m) {
        int from, to;
        cin >> from >> to;
        from--; to--;
        edge[from].emplace_back(to);
        edge[to].emplace_back(from);
    }

    // Use Dijkstra to find danger zones
    set<int> danger;
    vector<int> dist(n, INT_MAX);
    priority_queue<pl, vector<pl>, greater<pl>> pq;

    for (int z : zombie) {
        dist[z] = 0;
        pq.emplace(0, z);
    }

    while (!pq.empty()) {
        auto [d, v] = pq.top();
        pq.pop();
        if (d > dist[v]) continue;
        for (int nv : edge[v]) {
            if (dist[nv] > dist[v] + 1) {
                dist[nv] = dist[v] + 1;
                pq.emplace(dist[nv], nv);
            }
        }
    }

    rep(i, n) {
        if (dist[i] <= s && dist[i] != 0) {
            danger.insert(i);
        }
    }

    const ll INF = 1e18;
    vector<ll> dit(n, INF);
    priority_queue<pl, vector<pl>, greater<pl>> qu;
    dit[0] = 0;
    qu.emplace(0, 0);

    while (!qu.empty()) {
        auto [d, v] = qu.top();
        qu.pop();
        if (dit[v] < d) continue;
        for (auto ne : edge[v]) {
            if (zom.find(ne) != zom.end()) continue; // Skip zombie nodes
            ll nd = d;
            if (danger.count(ne) && ne != n-1) {
                nd += q;
            } else if(ne != n-1) {
                nd += p;
            }
            if (ne == n - 1) {  // Special handling for the last node
                if (nd < dit[ne]) {
                    dit[ne] = nd;
                }
            } else {
                if (nd >= dit[ne]) continue;
                dit[ne] = nd;
                qu.emplace(nd, ne);
            }
        }
    }

    cout << (dit[n - 1] == INF ? -1 : dit[n - 1]) << endl;
    return 0;
}
