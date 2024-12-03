#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using ll = long long;
using P = pair<int, int>;
#define rep(i, n) for (int i = 0; i < (n); i++)

//方針例
//再帰で全探索
//next_permutationで全探索（辿れなくなったら次へ）
//DFS



struct Edge {
  int to;
  int weight;
  Edge(int to = 0, int weight = 0) : to(to), weight(weight) {}
};

int main() {
  int n, m;
  cin >> n >> m;

  vector<vector<Edge>> G(n);

  rep(i, m) {
    int from, to, weight;
    cin >> from >> to >> weight;
    --from; --to;
    G[from].push_back(Edge(to, weight));
    G[to].push_back(Edge(from, weight));
  }

  int ans = 0;
  vector<bool> visited(n);
  auto f = [&](auto f ,int v,int dist)-> void{
    visited[v] = true;
    ans = max(ans,dist);
    for(auto e:G[v]){
      if(visited[e.to]) continue;
      f(f,e.to,dist+e.weight);
    }
    visited[v] = false;
  };

  rep(i, n) {
    f(f,i,0);
  }
  cout << ans << endl;
  return 0;
}
