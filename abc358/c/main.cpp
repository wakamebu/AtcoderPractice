#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using ll = long long;
using P = pair<int,int>;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main() {
    int N, M;
    cin >> N >> M;
    vector<string> S(N);
    for (int i = 0; i < N; ++i) {
        cin >> S[i];
    }

    int min_shops = N; // 初期値を最大値に設定

    for (int bit = 1; bit < (1 << N); ++bit) {
        vector<bool> covered(M, false);
        int shops_count = 0;

        for (int i = 0; i < N; ++i) {
            if (bit & (1 << i)) { // 売り場 i を訪問する
                shops_count++;
                for (int j = 0; j < M; ++j) {
                    if (S[i][j] == 'o') {
                        covered[j] = true;
                    }
                }
            }
        }

        // 全ての味がカバーされてるか
        bool all_covered = true;
        for (int j = 0; j < M; ++j) {
            if (!covered[j]) {
                all_covered = false;
                break;
            }
        }

        if (all_covered) {
            min_shops = min(min_shops, shops_count);
        }
    }

    cout << min_shops << endl;
    return 0;
}
