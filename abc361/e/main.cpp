#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using ll = long long;
using P = pair<ll,int>;
#define rep(i,n) for(int i = 0; i < (n); i++)

struct Edge {
    int to;
    int weight;
    Edge(int to = 0, int weight = 0) : to(to), weight(weight) {}
};

int main() {
    int n;
    cin >> n;

    vector<vector<Edge>> G(n);

    int total_weight = 0;
    for (int i = 0; i < n - 1; ++i) {
        int from, to, weight;
        cin >> from >> to >> weight;
        --from; --to;
        G[from].push_back(Edge(to, weight));
        G[to].push_back(Edge(from, weight));
        total_weight += weight;
    }

    // Implementing Prim's algorithm to find MST
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    vector<bool> visited(n, false);
    pq.push({0, 0}); // {weight, node}
    int mst_weight = 0;

    while (!pq.empty()) {
        auto [weight, u] = pq.top(); pq.pop();
        if (visited[u]) continue;
        visited[u] = true;
        mst_weight += weight;

        for (auto &edge : G[u]) {
            if (!visited[edge.to]) {
                pq.push({edge.weight, edge.to});
            }
        }
    }

    // The minimum distance to visit all cities at least once
    int min_distance = 2 * mst_weight; // Because an Eulerian circuit visits each edge twice
    cout << min_distance << endl;

    return 0;
}