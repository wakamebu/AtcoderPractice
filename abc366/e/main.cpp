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

const int MAX_COORD = 1000; // 座標の範囲を仮定
const int OFFSET = 1000; // 座標を0以上に変換するためのオフセット

int main() {
    int n, d;
    cin >> n >> d;

    vector<int> x_coords(n), y_coords(n);
    vector<vector<int>> grid(2 * MAX_COORD + 1, vector<int>(2 * MAX_COORD + 1, 0));

    // 点の座標を読み込み
    for (int i = 0; i < n; ++i) {
        int x, y;
        cin >> x >> y;
        x += OFFSET; // 座標を正の範囲に変換
        y += OFFSET;
        grid[x][y]++;
    }

    // 2D累積和を計算
    vector<vector<int>> prefix_sum(2 * MAX_COORD + 1, vector<int>(2 * MAX_COORD + 1, 0));
    for (int i = 0; i <= 2 * MAX_COORD; ++i) {
        for (int j = 0; j <= 2 * MAX_COORD; ++j) {
            prefix_sum[i][j] = grid[i][j]
                + (i > 0 ? prefix_sum[i - 1][j] : 0)
                + (j > 0 ? prefix_sum[i][j - 1] : 0)
                - (i > 0 && j > 0 ? prefix_sum[i - 1][j - 1] : 0);
        }
    }

    int count = 0;

    // (x, y) の範囲をスキャン
    for (int x = 0; x <= 2 * MAX_COORD; ++x) {
        for (int y = 0; y <= 2 * MAX_COORD; ++y) {
            ll sum_dist = 0;
            for (int xi = 0; xi <= 2 * MAX_COORD; ++xi) {
                for (int yi = 0; yi <= 2 * MAX_COORD; ++yi) {
                    ll dist = abs(x - xi - OFFSET) + abs(y - yi - OFFSET);
                    if (dist <= d) {
                        sum_dist += prefix_sum[xi][yi]
                            - (x > 0 ? prefix_sum[xi][y] : 0)
                            - (y > 0 ? prefix_sum[x][yi] : 0)
                            + (x > 0 && y > 0 ? prefix_sum[x][y] : 0);
                    }
                }
            }
            if (sum_dist <= d) {
                ++count;
            }
        }
    }

    cout << count << endl;

    return 0;
}