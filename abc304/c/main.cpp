#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using ll = long long;
using P = pair<int,int>;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main() {
    int n, d;
    cin >> n >> d;

    vector<P> h(n);
    rep(i, n) {
        int x, y;
        cin >> x >> y;
        h[i] = make_pair(x, y);
    }

    d *= d;
    map<int, vector<int>> dist;

    rep(i, n) {
        rep(j, n) {
            if (i == j) continue;
            int defx = (h[i].first - h[j].first) * (h[i].first - h[j].first);
            int defy = (h[i].second - h[j].second) * (h[i].second - h[j].second);
            dist[i].emplace_back(defx + defy);
        }
    }

    vector<bool> ans(n, false);
    ans[0] = true;

    queue<int> q;
    q.push(0);

    while (!q.empty()) {
        int v = q.front();
        q.pop();

        rep(j, n) {
            if (v == j || ans[j]) continue;
            int defx = (h[v].first - h[j].first) * (h[v].first - h[j].first);
            int defy = (h[v].second - h[j].second) * (h[v].second - h[j].second);
            if (defx + defy <= d) {
                ans[j] = true;
                q.push(j);
            }
        }
    }

    for (auto x : ans) {
        cout << (x ? "Yes" : "No") << endl;
    }

    return 0;
}
