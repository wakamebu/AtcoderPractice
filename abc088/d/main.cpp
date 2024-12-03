#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using ll = long long;
using P = pair<int,int>;
#define OVERLOAD_REP(_1, _2, _3, name, ...) name
#define REP1(i, n) for (auto i = std::decay_t<decltype(n)>{}; (i) != (n); ++(i))
#define REP2(i, l, r) for (auto i = (l); (i) != (r); ++(i))
#define rep(...) OVERLOAD_REP(__VA_ARGS__, REP2, REP1)(__VA_ARGS__)
#define all(...) std::begin(__VA_ARGS__), std::end(__VA_ARGS__)
#define rall(...) std::rbegin(__VA_ARGS__), std::rend(__VA_ARGS__)

int main() {
  int h,w;
  cin >> h >> w;
  vector<vector<char>> grid(h,vector<char>(w,'.'));
  int before = 0;
  rep(i,h)rep(j,w){
    cin >> grid[i][j];
    if(grid[i][j] == '#')before++;
  }
  vector<P> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

  vector<vector<int>> dist(h,vector<int>(w,-1));
  queue<P> q;
  dist[0][0] = 1;
  q.push({0,0});

  while(!q.empty()){
    auto [a,b] = q.front();
    q.pop();
    for(auto [dx,dy] : directions){
      int x = a + dx;
      int y = b + dy;
      if(x<0 or y < 0 or x >= h or y >= w)continue;
      if(dist[x][y] != -1)continue;
      if(grid[x][y] == '#')continue;
      dist[x][y] = dist[a][b] + 1;
      q.push({x,y});
    }
  }

  if(dist[h-1][w-1] == -1){
    cout << -1 << endl;
    return 0;
  }

  int ans = h*w;
  int black = ans - dist[h-1][w-1];
  black -= before;

  cout << black << endl;
  return 0;
}