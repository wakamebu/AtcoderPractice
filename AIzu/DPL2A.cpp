#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int, int>;

#define rep(i, n) for (int i = 0; i < (n); i++)
const int INF = 1 << 20;

int main() {
    int v, e;
    cin >> v >> e;
    vector<vector<int>> edge(v,vector<int>(v,INF));
    rep(i,e){
        int s, t, d;
        cin >> s >> t >> d;
        edge[s][t] = min(edge[s][t],d);
    }

    vector<vector<int>> memo(1 << v,vector<int>(v,INF));
    int res = INF;
    for(int i = 1; i < (1<<v);i++){
        for(int j = 0; j < v;j++){
            if(i == 1){
                if(j == 0) memo[i][j] = 0;
                continue;
            }
            if(!(i & (1 << j)))continue;
            for(int k = 0; k < v ; k++){
                if(k == j)continue;
                if(! (i & (1 << k)))continue;
                memo[i][j] = min (memo[i][j],memo[i-(1<<j)][k] + edge[k][j]);
            }
            if(i == (1<<v)-1){
                if(edge[j][0] == INF)continue;
                res = min(res,memo[i][j] + edge[j][0]);
            }
        }
    }
    cout << (res == INF ? -1:res) << endl;
    return 0;
}