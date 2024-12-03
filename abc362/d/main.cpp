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

struct Edge {
    int to;
    long long weight;
};

struct Node {
    int vertex;
    long long cost;
    bool operator>(const Node& other) const {
        return cost > other.cost;
    }
};

const long long INF = numeric_limits<long long>::max();

void dijkstra(int N, const vector<long long>& A, const vector<vector<Edge>>& graph, vector<long long>& min_cost) {
    priority_queue<Node, vector<Node>, greater<Node>> pq;
    pq.push({1, A[1]});
    min_cost[1] = A[1];

    while (!pq.empty()) {
        Node current = pq.top();
        pq.pop();
        int u = current.vertex;
        long long current_cost = current.cost;

        if (current_cost > min_cost[u]) {
            continue;
        }

        for (const Edge& edge : graph[u]) {
            int v = edge.to;
            long long new_cost = current_cost + edge.weight + A[v];
            if (new_cost < min_cost[v]) {
                min_cost[v] = new_cost;
                pq.push({v, new_cost});
            }
        }
    }
}

int main() {
    int N, M;
    cin >> N >> M;

    vector<long long> A(N + 1);
    for (int i = 1; i <= N; ++i) {
        cin >> A[i];
    }

    vector<vector<Edge>> graph(N + 1);
    for (int j = 0; j < M; ++j) {
        int U, V;
        long long B;
        cin >> U >> V >> B;
        graph[U].push_back({V, B});
        graph[V].push_back({U, B});
    }

    vector<long long> min_cost(N + 1, INF);
    dijkstra(N, A, graph, min_cost);

    for (int i = 2; i <= N; ++i) {
        if (min_cost[i] == INF) {
            cout << -1 << endl;
        } else {
            cout << min_cost[i] << endl;
        }
    }

    return 0;
}