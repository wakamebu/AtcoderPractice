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

int main() {
    int n, k;
    cin >> n >> k;

    vector<int> c(n);
    vector<int> r(n);

    rep(i, n) {
        int cost, ride;
        cin >> cost >> ride;
        c[i] = cost;
        r[i] = ride;
    }

    vector<vector<int>> G(n);
    rep(i, k) {
        int from, to;
        cin >> from >> to;
        from--; to--;
        G[from].emplace_back(to);
        G[to].emplace_back(from);
    }

    const int INF = 1e9;
    priority_queue<P, vector<P>, greater<P>> q;
    vector<int> cost(n, INF);
    cost[0] = 0;
    q.emplace(0, 0);

    while (!q.empty()) {
        auto [ncost, nv] = q.top();
        q.pop();
        if (cost[nv] < ncost) continue;

        queue<P> arr;
        vector<bool> seen(n, false);
        arr.emplace(nv, r[nv]);

        while (!arr.empty()) {
            int arrtown = arr.front().first;
            int restpop = arr.front().second;
            arr.pop();
            if (seen[arrtown]) continue;
            seen[arrtown] = true;
            if (restpop <= 0) continue;

            for (int arrnext : G[arrtown]) {
                if (seen[arrnext]) continue;
                if (ncost + c[nv] < cost[arrnext]) {
                    cost[arrnext] = ncost + c[nv];
                    q.emplace(cost[arrnext], arrnext);
                }
                arr.emplace(arrnext, restpop - 1);
            }
        }
    }
    cout << cost[n - 1] << endl;
    return 0;
}
