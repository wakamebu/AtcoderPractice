#include <bits/stdc++.h>
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
using ll = long long;
using P = pair<int, int>;
#define rep(i, n) for (int i = 0; i < (n); i++)

int main() {
    int n;
    cin >> n;
    vector<string> x(n);
    vector<string> y(n);
    rep(i,n) cin >> x[i] >> y[i];

    rep(k, n) {
        int m = x[k].size();
        int l = y[k].size();
        vector<vector<int>> dp(m + 1, vector<int>(l + 1, 0));

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < l; j++) {
                if (x[k][i] == y[k][j]) {
                    dp[i+1][j+1] = dp[i][j] + 1;//左上+1更新
                } else {
                    dp[i+1][j+1] = max(dp[i+1][j], dp[i][j+1]);//↑と←の最大値更新
                }
            }
        }

        cout << dp[m][l] << endl;
    }

    return 0;
}
