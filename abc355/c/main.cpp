#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using ll = long long;
using P = pair<int,int>;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main() {
    int n, t;
    cin >> n >> t;
    vector<int> row(n, 0), col(n, 0); // 0で初期化
    int dial = 0, dial2 = 0; // 初期化

    for (int ti = 0; ti < t; ti++) {
        int a;
        cin >> a;
        a--;
        int i = a / n, j = a % n; // 行と列の計算修正

        auto add = [&](int& x) {
            x++;
            if (x == n) {
                cout << ti + 1 << endl;
                exit(0);
            }
        };

        add(row[i]);
        add(col[j]);
        if (i == j) add(dial); // 主対角線
        if (i + j == n - 1) add(dial2); // 副対角線
    }

    cout << -1 << endl;
    return 0;
}