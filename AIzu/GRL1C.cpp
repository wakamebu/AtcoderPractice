#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, int>;

#define rep(i, n) for (int i = 0; i < (n); i++)

const int INF = 10010010;

struct Edge {
    int to;
    int cost;
    Edge(int to, int cost) : to(to), cost(cost) {}
};

int main() {
    int v, e;
    cin >> v >> e;
    
    vector<vector<int>> dp(v,vector<int>(v,INF));
    for(int i = 0; i<v;i++)for(int j= i;j<v;j++)if(i==j)dp[i][j] = 0;

    rep(i, e) {
        int from, to, cost;
        cin >> from >> to >> cost;
        dp[from][to] = cost;
    }

    for(int k=0;k<v;k++){
        for(int i=0;i<v;i++){
            for(int j=0;j<v;j++){
                dp[i][j]=min(dp[i][j],dp[i][k]+dp[k][j]);
            }
    }
}

    for(int i = 0;i<v;i++){
        for(int j = 0;j<v;j++){
            if(dp[i][j] == INF)cout << "INF" << " ";
            else cout << dp[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}