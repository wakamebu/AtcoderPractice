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

struct UnionFind {
    int n;
    vector<int> parent;
    vector<int> rank_;
    vector<vector<int>> top_list; // 各連結成分のトップ10の頂点番号（降順）

    UnionFind(int size) : n(size), parent(size + 1), rank_(size + 1, 0), top_list(size + 1, vector<int>()) {
        for(int i = 1; i <= n; ++i){
            parent[i] = i;
            top_list[i].push_back(i);
        }
    }

    // パス圧縮を伴うFind
    int find_set(int x){
        if(parent[x] != x){
            parent[x] = find_set(parent[x]);
        }
        return parent[x];
    }

    // 2つの連結成分をUnion
    void union_set(int x, int y){
        int fx = find_set(x);
        int fy = find_set(y);
        if(fx == fy) return;

        // Union by rank
        if(rank_[fx] < rank_[fy]){
            parent[fx] = fy;
            merge_top(fx, fy);
        }
        else{
            parent[fy] = fx;
            merge_top(fy, fx);
            if(rank_[fx] == rank_[fy]){
                rank_[fx]++;
            }
        }
    }

    // 連結成分のトップ10をマージ
    void merge_top(int from, int to){
        // マージ対象のリスト
        vector<int> merged;
        int i = 0, j = 0;
        // 両方のリストは降順にソートされていることを前提
        while(i < top_list[from].size() && j < top_list[to].size() && merged.size() < 10){
            if(top_list[from][i] > top_list[to][j]){
                merged.push_back(top_list[from][i++]);
            }
            else{
                merged.push_back(top_list[to][j++]);
            }
        }
        while(i < top_list[from].size() && merged.size() < 10){
            merged.push_back(top_list[from][i++]);
        }
        while(j < top_list[to].size() && merged.size() < 10){
            merged.push_back(top_list[to][j++]);
        }
        // 更新
        top_list[to] = merged;
    }
};


int main() {
  int n,q;
  cin >> n >> q;
  UnionFind uf(n);
  vector<string> results;
  

  while(q--){
    int o;
    cin >> o;

    if(o == 1){
      //結合
      int u,v;
      cin >> u >> v;
      uf.union_set(u,v);
      

    }else{
      //出力
      int v,k;
      cin >> v >> k;
      int root = uf.find_set(v);
      if(uf.top_list[root].size() >= k){
        results.push_back(to_string(uf.top_list[root][k-1]));
      }else{
        results.push_back("-1");
      }
    }
  }

  for(auto &res : results){
        cout << res << "\n";
  }

  return 0;
}