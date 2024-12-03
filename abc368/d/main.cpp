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

using Graph = vector<vector<int>>;
using P = pair<int, int>;

// BFSによってstartから他のすべてのノードへの最短距離を計算する
vector<int> bfs(const Graph &G, int start) {
    int n = G.size();
    vector<int> distance(n, INT_MAX);
    queue<int> q;
    q.push(start);
    distance[start] = 0;
    
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        
        for (int v : G[u]) {
            if (distance[v] == INT_MAX) {
                distance[v] = distance[u] + 1;
                q.push(v);
            }
        }
    }
    
    return distance;
}


int main() {
    int n, k;
    cin >> n >> k;
    
    Graph G(n);
    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        cin >> u >> v;
        --u; --v;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    
    vector<int> terminals(k);
    for (int i = 0; i < k; ++i) {
        cin >> terminals[i];
        --terminals[i]; // 0-indexedに変換
    }

    sort(all(terminals));

    vector<int> dist(n,-1);
    queue<int> que;

    dist[terminals[0]] = 0;
    que.push(terminals[0]);


    while(!que.empty()){
      int v = que.front();
      que.pop();

      for(int nv : G[v]){
        if(dist[nv] != -1)continue;
        if(G[nv].size() == 1){
          auto it = lower_bound(all(terminals), nv);
          if(it == terminals.end() || *it != nv){
            
            continue;
          }
          else 
        }
        dist[nv] = dist[v] + 1;
        que.push(nv);

      }
    } 

    int result = accumulate(all(dist), 0, [](int a, int b) { return b != -1 ? a + b : a; });
    cout << result << endl;
    
    return 0;
}