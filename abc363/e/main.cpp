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
auto make_vec(const size_t(&d)[n], const T& init) noexcept {
    if constexpr (idx < n) return std::vector(d[idx], make_vec<T, n, idx + 1>(d, init));
    else return init;
}

template<class T, size_t n>
auto make_vec(const size_t(&d)[n]) noexcept {
    return make_vec(d, T{});
}

int main() {
    int h, w, y;
    cin >> h >> w >> y;
    vector<vector<int>> grid(h + 2, vector<int>(w + 2));
    vector<vector<bool>> sink(h + 2, vector<bool>(w + 2, false));
    rep(i, h + 2) rep(j, w + 2) {
        if (i == 0 or i == h + 1 or j == 0 or j == w + 1) {
            grid[i][j] = 0;
            sink[i][j] = true;
        } else {
            cin >> grid[i][j];
        }
    }

    vector<P> directions = { {0, 1}, {1, 0}, {0, -1}, {-1, 0} };

    rep(i, y) {
        vector<vector<int>> dist(h + 2, vector<int>(w + 2, -1));
        queue<P> q;

        dist[0][0] = 0;
        q.push({ 0, 0 });

        int height = i + 1;
        while (!q.empty()) {
            auto [a, b] = q.front();
            q.pop();

            for (auto nv : directions) {
                int x = a + nv.first;
                int y = b + nv.second;
                if (x < 0 or y < 0 or x >= h + 2 or y >= w + 2) continue;
                if (dist[x][y] != -1) continue;
                dist[x][y] = dist[a][b] + 1;
                if (grid[x][y] <= height) {
                    sink[x][y] = true;
                    q.push({ x, y });
                }
            }
        }

        int cnt = 0;
        rep(i, h + 2) rep(j, w + 2) {
            if (!sink[i][j]) {
                cnt++;
            }
        }
        cout << cnt << endl;
    }

    return 0;
}
