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


int main() {
  int r,c;
  cin >> r >> c;
  int sy,sx,gy,gx;
  cin >> sy >> sx >> gy >> gx;
  sy--;sx--;gy--;gx--;
  P start = {sx,sy};
  P goal = {gx,gy};

  vector<vector<char>> grid(r,vector<char>(c));
  rep(i,r)rep(j,c)cin >> grid[i][j];

  vector<P> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

    // BFS のためのデータ構造
    vector<vector<int>> dist(r, vector<int>(c, -1)); // 全頂点を「未訪問」に初期化
    queue<P> que;

    // 初期条件 (頂点 0 を初期ノードとする)
    dist[sy][sx] = 0;
    que.push(start); // 0 を橙色頂点にする

  while(!que.empty()){
    P v = que.front();
    que.pop();
    for(P nv: directions){
      int x = v.first + nv.first;
      int y = v.second + nv.second;
      if(x<0 or y < 0 or x >= c or y >= r)continue;
      if(dist[y][x] != -1)continue;
      if(grid[y][x] == '#')continue;
      dist[y][x] = dist[v.second][v.first] + 1;
      que.push({x,y});
    }
  }

  cout << dist[gy][gx] << endl;
  return 0;
}