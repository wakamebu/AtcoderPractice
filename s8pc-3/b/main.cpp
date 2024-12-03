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
  int h,w,k;
  cin >> h >> w >> k;
  vector<vector<int>> grid;

  //素直に全探索する

  auto clear = [&](int cnt,int st,int ed,int H,vector<vector<int>>& G){
    int res = 0;
    if(cnt >= k){
      for(int i = st;i <= ed;i++){
        res += G[H][i];
        G[H][i] = 0;
      }
    }
    return res;
  };

  auto chain = [&](vector<vector<int>>& G){
    int cnt = 0,prev = -1,st = 0;
    int res = 0;
    rep(i,h){
      prev = -1;
      cnt = 0;
      st = 0;
      rep(j,w){
        if(prev == G[i][j] and G[i][j] != 0){
          cnt++;
          if(j == w-1){
            res += clear(cnt,st,j,i,G);
          }
        }else{
          res += clear(cnt, st, j - 1, i, G);
          prev = G[i][j];
          st = j;
          cnt = 1;
        }
      }
    }
    return res;
  };

  auto fall = [&](vector<vector<int>>& G) {
        for (int j = 0; j < w; j++) {
            for (int i = h - 1; i > 0; i--) {
                if (G[i][j] == 0) {
                    for (int k = i - 1; k >= 0; k--) {
                        if (G[k][j] != 0) {
                            swap(G[i][j], G[k][j]);
                            break;
                        }
                    }
                }
            }
        }
    };

  grid.assign(h,vector<int>(w,0));
  rep(i,h){
    string st;
    cin >> st;
    rep(j,w){
      char c = st[j];
      int ad = c - '0';
      grid[i][j] = ad;
    }
  }
  
  vector<vector<int>> copy = grid;
  int ans = 0;
  int res = 0;
  rep(i, h) {
        rep(j, w) {
            grid = copy;  // グリッドをコピー
            grid[i][j] = 0;  // 試しに一つのブロックを削除
            fall(grid); //まず落ちる
/*
            if(i == 2 and j == 2){
                rep(l,h){
                    rep(m,w){
                      cout << grid[l][m];
                    }
                  cout << endl;
              }
            }
*/
            int res = 0;
            int chained = 0;
            int score = 0;
            while (true) {

              if(chained == 0){
                score = chain(grid);
                }  // チェインで消えるスコアを計算
              if(chained >0 ){
                int bonus = 1;
                rep(l,chained){
                  bonus *= 2;
                }
                  score = bonus * chain(grid);
              }
                if (score == 0) break;    // スコアが0なら終了
                res += score;
                fall(grid);  // ブロックを落とす
                chained ++;
            }
            ans = max(ans, res);  // 最大スコアを更新
        }
    }

  cout << ans << endl;
  return 0;
}