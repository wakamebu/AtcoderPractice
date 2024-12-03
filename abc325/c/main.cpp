#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using ll = long long;
using P = pair<int,int>;
#define rep(i,n) for(int i = 0; i < (n); i++)

//たてよこななめ
const vector<P> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}, {-1, -1}, {-1, 1}, {1, 1}, {1, -1}};

void dfs(int x, int y, int h, int w, vector<vector<char>>& grid, vector<vector<bool>>& visited) {
    stack<P> s;
    s.push({x, y});
    visited[x][y] = true;

    while (!s.empty()) {
        P current = s.top();
        s.pop();

        for (auto dir : directions) {
            int nx = current.first + dir.first;
            int ny = current.second + dir.second;

            if (nx >= 0 && ny >= 0 && nx < h && ny < w && grid[nx][ny] == '#' && !visited[nx][ny]) {
                visited[nx][ny] = true;
                s.push({nx, ny});
            }
        }
    }
}

int main() {
  int h,w;
  cin >> h >> w;
  vector<vector<char>> grid(h,vector<char>(w));
  vector<P> sen;

  rep(i,h){
    rep(j,w){
    cin >> grid[i][j];
    if(grid[i][j]=='#') sen.push_back(make_pair(i,j));
    }
  }

  map<P,P> list;
  rep(i,sen.size()){
    int nowx = sen[i].first;
    int nowy = sen[i].second;
    for(auto x :directions){
      nowx += x.first;
      nowy += x.second;
      if(nowx < 0 or nowy <0  or nowx >= h or nowy >= w)continue;
      if(grid[nowx][nowy] == '#'){
        list[sen[i]] = make_pair(nowx,nowy);
      }
    }
  }

  vector<vector<bool>> visited(h, vector<bool>(w, false));
  int tree_count = 0;

  rep(i, h) {
    rep(j, w) {
        if (grid[i][j] == '#' && !visited[i][j]) {
            dfs(i, j, h, w, grid, visited);
            tree_count++;
            }
        }
    }

    cout << tree_count << endl;

}