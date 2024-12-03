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
    int n , m;
    cin >> n >> m;

    // 隣接行列の初期化
    vector<vector<int>> a(m, vector<int>(n));
    rep(i,m)rep(j,n) cin >>a[i][j];
    rep(i,m)rep(j,n) a[i][j]--;

    vector g(n,vector<bool>(n));

    rep(i,m){
      rep(j,n-1){
        g[a[i][j]][a[i][j+1]] = true;
      }
    }

    int count = 0;
    rep(x,n)rep(y,x){
      if(g[x][y] or g[y][x]) continue;
      count ++;
    }

    cout  << count << endl;
    return 0;
}