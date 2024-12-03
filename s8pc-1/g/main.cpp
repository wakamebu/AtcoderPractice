#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int,int>;
using Graph = vector<vector<int>>;

#define rep(i, n) for (int i = 0; i < (n); i++)

ll dp[1 << 16][16];
ll cnt[1 << 16][16];
const ll INF = 1e18;

struct Edge
{
    ll to;
    ll dist;
    ll time;
    Edge (ll to, ll dist, ll time) : to(to), dist(dist), time(time) {}
};

int main() {
    ll n, m;
    cin >> n >> m;

    vector<Edge> Graph[16];
    rep(i, m) {
        ll s, t;
        ll d, ti;
        cin >> s >> t >> d >> ti;
        s--; t--;
        Graph[s].emplace_back(t, d, ti);
        Graph[t].emplace_back(s, d, ti);
    }

    for (int i = 0; i < (1 << n); i++)  {
          for (int j = 0; j < n; j++) {
              dp[i][j] = INF;
              cnt[i][j] = 0;
          }
      }

    dp[1][0] = 0;
    cnt[1][0] = 1;

    // スタートのみから全都市制覇までbitDP
    for (int i = 1; i < (1 << n); i++) {
        // 最後の都市をjとする
        for (int j = 0; j < n; j++) {
            if (!(i & (1 << j))) continue;
            // 次に行く都市をkとする
            for (const auto& city : Graph[j]){
                ll nex = city.to;
                ll dist = city.dist;
                ll time = city.time;
                if(i & (1 << nex))continue;
                if(dp[i][j] + dist > time)continue;
                if(dp[i | (1 << nex)][nex] > dp[i][j] + dist){
                  dp[i | (1 << nex)][nex] = dp[i][j] + dist;
                  cnt[i | (1 << nex)][nex] = cnt[i][j];
                }
                else if(dp[i | (1 << nex)][nex] == dp[i][j] + dist){
                  cnt[i | (1 << nex)][nex] += cnt[i][j];
                }
            }
        }
    }

    ll ans = INF;
    ll count = 0;
    for (const auto &city : Graph[0]) {
        ll k = city.to;
        ll dist = city.dist;
        if(dp[(1<<n)-1][k]+dist <=city.time){
          if(ans > dp[(1<<n)-1][k]+dist){
            ans = dp[(1<<n)-1][k]+dist;
            count = cnt[(1 << n) - 1][k];
          }
        }else if(ans == dp[(1<<n)-1][k] + dist){
          count += cnt[(1<<n)-1][k];
        }
    }

    if(ans == INF) cout << "IMPOSSIBLE" << endl;
    else cout << ans << " " << count << endl;
    return 0;
}
