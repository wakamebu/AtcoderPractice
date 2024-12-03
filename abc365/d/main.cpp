#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    string s;
    cin >> s;

    // DPテーブルの初期化
    // dp[i][j] = i番目までじゃんけんをし、そのときjを出した時の最大勝利数
    // j = 0: R, 1: P, 2: S
    vector<vector<int>> dp(n, vector<int>(3, -1));

    // 初期設定
    for (int j = 0; j < 3; ++j) {
        // s[0] が R, P, S のいずれかで、j の手が負ける場合は -1、そうでなければ 0
        if (s[0] == 'R') {
            if (j == 0) dp[0][j] = 0; // R vs R → 負け
            else dp[0][j] = (j == 2) ? -1 : 1; // R vs P → 負け, R vs S → 勝ち
        } else if (s[0] == 'P') {
            if (j == 1) dp[0][j] = 0; // P vs P → 負け
            else dp[0][j] = (j == 0) ? -1 : 1; // P vs R → 勝ち, P vs S → 負け
        } else if (s[0] == 'S') {
            if (j == 2) dp[0][j] = 0; // S vs S → 負け
            else dp[0][j] = (j == 1) ? -1 : 1; // S vs P → 勝ち, S vs R → 負け
        }
    }

    // DPテーブルの更新
    for (int i = 1; i < n; ++i) {
        for (int prev = 0; prev < 3; ++prev) {
            if (dp[i-1][prev] == -1) continue; // 到達不可能な状態はスキップ

            for (int curr = 0; curr < 3; ++curr) {
                if (curr == prev) continue; // 同じ手は連続してはならない

                // 手の結果
                bool win = (curr == 0 && s[i] == 'S') || // currがRでs[i]がS → 勝ち
                           (curr == 1 && s[i] == 'R') || // currがPでs[i]がR → 勝ち
                           (curr == 2 && s[i] == 'P'); // currがSでs[i]がP → 勝ち

                // 勝つ場合は勝利数を更新
                if (win) {
                    dp[i][curr] = max(dp[i][curr], dp[i-1][prev] + 1);
                } else {
                    dp[i][curr] = max(dp[i][curr], dp[i-1][prev]);
                }
            }
        }
    }

    // 最大の勝利数を求める
    int result = 0;
    for (int j = 0; j < 3; ++j) {
        result = max(result, dp[n-1][j]);
        //cout << dp[n-1][j] << " ";
    }
    //cout << endl;
    cout << result << endl;
    return 0;
}