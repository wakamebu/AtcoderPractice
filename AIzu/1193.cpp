#include <bits/stdc++.h>
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
using ll = long long;
using P = pair<int, int>;
#define rep(i, n) for (int i = 0; i < (n); i++)

int main() {
    int h;

    vector<vector<int>> puzzle;

    auto erase = [&](int nowh, int cnt, int st, int ed) -> int {
        int res = 0;
        if (cnt >= 3) { // 3つ以上の連続する数字を消す
            for (int i = st; i <= ed; i++) {
                res += puzzle[nowh][i]; // 消す数字の合計をスコアに加算
                puzzle[nowh][i] = 0;    // 消去
            }
        }
        return res;
    };

    auto chain = [&]() {
        int res = 0;
        int prev = -1, cnt = 0, st = 0;
        rep(i, h) {
            prev = -1; // 各行の処理のたびに初期化
            cnt = 0;
            st = 0;
            rep(w, 5) {
                if (w > 0 && prev == puzzle[i][w] && puzzle[i][w] != 0) {
                    cnt++;
                    if (w == 4) { // 最後の列で連続している場合のチェック
                        res += erase(i, cnt, st, w);
                    }
                } else {
                    res += erase(i, cnt, st, w - 1);
                    st = w;
                    cnt = 1;
                    prev = puzzle[i][w];
                }
            }
        }
        return res;
    };

    auto fall = [&]() {
        bool moved = true;
        while (moved) {
            moved = false;
            for (int i = h - 1; i > 0; i--) {
                for (int w = 4; w >= 0; w--) {
                    if (puzzle[i][w] == 0 && puzzle[i - 1][w] != 0) {
                        swap(puzzle[i][w], puzzle[i - 1][w]);
                        moved = true;
                    }
                }
            }
        }
    };

    while (cin >> h && h) {
        puzzle.assign(h, vector<int>(5, 0));
        rep(i, h) {
            rep(w, 5) {
                cin >> puzzle[i][w];
            }
        }

        int score = 0;
        int ans = 0;
        while (true) {
            score = chain();
            if (score == 0) {
                break;
            }
            ans += score;
            fall();
        }
        cout << ans << endl;
    }
    return 0;
}
