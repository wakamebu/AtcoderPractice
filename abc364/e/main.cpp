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

void chmin(int& a, int b){a = min(a,b);}

int main() {
    int n, x, y;
    cin >> n >> x >> y;

    const int INF = 1001001001;
    //答えをキーにする jは甘さの合計、 kは食べられる料理の合計
    vector dp(x+1,vector<int>(n+1,INF));
    dp[0][0] = 0;

    rep(i,n){
        int a,b;
        cin >> a >> b;
        
        vector old(x+1,vector<int>(n+1,INF));
        swap(dp,old);
        rep(j,x+1)rep(k,n+1){
            int now = old[j][k];
            if(now == INF) continue;
            chmin(dp[j][k], now); // not use
            if(j+a <= x)chmin(dp[j+a][k+1],now+b);
        }
    }

    int ans = 0;
    rep(j,x+1)rep(k,n+1) if (dp[j][k] <= y){
        ans = max(ans, k);
    }
    if (ans < n) ans++;

    cout << ans << endl;
    return 0;
}