#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int, int>;

#define rep(i, n) for (int i = 0; i < (n); i++)

int main() {
    int n;
    cin >> n;
    vector<int> p(n + 1);
    
    // 読み込みと p 配列の設定
    for (int i = 0; i < n; ++i) {
        int x, y;
        cin >> x >> y;
        p[i] = x;
        if (i == n - 1) {
            p[i + 1] = y;
        }
    }

    // DP テーブルの初期化
    vector<vector<int>> dp(n, vector<int>(n, 0));
    
    for (int l = 2; l <= n; ++l) {  // l はチェーンの長さ
        for (int i = 0; i <= n - l; ++i) {
            int j = i + l - 1;
            dp[i][j] = INT_MAX;
            for (int k = i; k < j; ++k) {
                int q = dp[i][k] + dp[k + 1][j] + p[i] * p[k + 1] * p[j + 1];
                if (q < dp[i][j]) {
                    dp[i][j] = q;
                }
            }
        }
    }

    cout << dp[0][n - 1] << endl;

    return 0;
}