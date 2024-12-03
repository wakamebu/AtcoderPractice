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
  int h,w,n;
  cin >> h >> w >> n;
  vector<vector<char>> grid(h,vector<char>(w));

  vector<int> c(n,1e9);

  vector<P> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

  vector<vector<int>> dist(h,vector<int>(w,-1));
  vector<vector<int>> t(h,vector<int>(w,-1));
  queue<P> que;
  P start = {0,0};

  rep(i,h)rep(j,w){
    cin >> grid[i][j];
    if(grid[i][j] == 'S'){
      dist[i][j] = 0;
      que.push({i,j});
      start = {i,j};
    }
  }

  rep(i,n){
    while(!que.empty()){
      P v = que.front();
      que.pop();
      for (P nv : directions) {
                int x = v.first + nv.first;
                int y = v.second + nv.second;
                if (x < 0 || y < 0 || x >= h || y >= w) continue;
                if (dist[x][y] != -1) continue;
                if (grid[x][y] == 'X') continue;
                dist[x][y] = dist[v.first][v.second] + 1;
                que.push({x, y});
                if (grid[x][y] == '1' + i) {  // '1' + i として '1', '2', ..., 'n' を処理
                    c[i] = min(c[i], dist[x][y]);
                    start = {x, y};
                }
      }
    }
    while (!que.empty()) que.pop();  // キューのクリア
        dist = vector<vector<int>>(h, vector<int>(w, -1));  // 距離のリセット
        dist[start.first][start.second] = 0;
        que.push(start);
  }

  int sum = 0;
  for(auto x : c){
    sum += x;
  }

  cout << sum << endl;
  return 0;
}