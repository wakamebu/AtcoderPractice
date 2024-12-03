#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

const int INF = 1e9; // 大きな値で初期化

int main() {
    int N;
    std::cin >> N;

    std::vector<int> A(N);
    std::vector<char> S(N);

    for (int i = 0; i < N; ++i) {
        std::cin >> A[i] >> S[i];
    }

    // dp[i][l][r] : i 回目までの演奏で、左手が l、右手が r のときの最小疲労度
    std::vector<std::vector<std::vector<int>>> dp(N + 1, std::vector<std::vector<int>>(101, std::vector<int>(101, INF)));

    // 初期状態
    for (int l = 1; l <= 100; ++l) {
        for (int r = 1; r <= 100; ++r) {
            dp[0][l][r] = 0;
        }
    }

    // 動的計画法で疲労度を計算
    for (int i = 0; i < N; ++i) {
        int a = A[i];
        char s = S[i];
        for (int l = 1; l <= 100; ++l) {
            for (int r = 1; r <= 100; ++r) {
                if (dp[i][l][r] < INF) {
                    if (s == 'L') {
                        // 左手が a に移動
                        dp[i + 1][a][r] = std::min(dp[i + 1][a][r], dp[i][l][r] + std::abs(l - a));
                    } else {
                        // 右手が a に移動
                        dp[i + 1][l][a] = std::min(dp[i + 1][l][a], dp[i][l][r] + std::abs(r - a));
                    }
                }
            }
        }
    }

    // 結果の取得
    int result = INF;
    for (int l = 1; l <= 100; ++l) {
        for (int r = 1; r <= 100; ++r) {
            result = std::min(result, dp[N][l][r]);
        }
    }

    std::cout << result << std::endl;

    return 0;
}
