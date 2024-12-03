#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, int>;

#define rep(i, n) for (int i = 0; i < (n); i++)

struct Edge {
    int to;
    int cost;
    Edge(int to, int cost) : to(to), cost(cost) {}
};

int main() {
    int v, e;
    cin >> v >> e;
    int start;
    cin >> start;
    
    vector<vector<Edge>> edge(v);
    rep(i, e) {
        int from, to, cost;
        cin >> from >> to >> cost;
        edge[from].emplace_back(to, cost);
    }

    const int INF = 1e9;
    vector<int> dist(v, INF);
    priority_queue<P, vector<P>, greater<P>> q;
    dist[start] = 0;
    q.emplace(0, start);

    while (!q.empty()) {
        auto [d, u] = q.top();
        q.pop();
        if (dist[u] != d) continue; 
        for (auto &ei : edge[u]) {
            int nd = d + ei.cost;
            if (nd < dist[ei.to]) {
                dist[ei.to] = nd;
                q.emplace(nd, ei.to);
            }
        }
    }

    rep(i, v) {
        if (dist[i] == INF) cout << "INF" << endl;
        else cout << dist[i] << endl;
    }

    return 0;
}