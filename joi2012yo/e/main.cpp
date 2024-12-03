#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using ll = long long;
using P = pair<int, int>;
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
    int w, h;
    cin >> w >> h;
    vector<P> tower;
    vector<vector<int>> hexgrid(h+2, vector<int>(w+2));
    rep(i, h+2) rep(j, w+2) {
      if(i == 0 or i == h+1){
        hexgrid[i][j] = 0;
        continue;
      }
      if(j == 0 or j == w+1){
        hexgrid[i][j] = 0;
        continue;
      }
        cin >> hexgrid[i][j];
        if (hexgrid[i][j] == 1) {
            tower.emplace_back(i, j);
        }
    }

    vector<vector<P>> directions = {
        {{-1, -1}, {0, -1}, {1, 0}, {0, 1}, {-1, 1}, {-1, 0}}, // 奇数行
        {{0, -1}, {1, -1}, {1, 0}, {1, 1}, {0, 1}, {-1, 0}}   // 偶数行
    };

    vector<vector<int>> dist(h+2, vector<int>(w+2, -1));
    queue<P> q;
    q.push({0,0});
    dist[0][0] = 1;
    int cnt = 0;

        while (!q.empty()) {
            P v = q.front();
            q.pop();
            int row_type = v.first % 2; // 偶数行か奇数行かの判定
            for (const P& nv : directions[row_type]) {
                int x = v.first + nv.first;
                int y = v.second + nv.second;
                if (x < 0 || y < 0 || x >= h+2 || y >= w+2) continue;
                if (dist[x][y] != -1) continue;
                if (hexgrid[x][y] == 1) {
                  cnt++;
                    continue;
                }
                dist[x][y] = dist[v.first][v.second] + 1;
                q.push({x, y});
            }
        }

    cout << cnt << endl;
    return 0;
}
