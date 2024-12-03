#include <bits/stdc++.h>
using namespace std;

/*
円環は難しいので、最初に取る位置を全探索して残りを線形にする。

dp[i][j] := 残り[i, j]の状況から始めた時のJOIくんの取り分の最大値
残り[i, j]の状況から始めた時、のスタートがJOIくんかIOIちゃんかは残りの長さの偶奇で決まるから一意
なのでdp[i][j][0]、dp[i][j][0]のように分ける必要はない

更新式
JOIくんから始まる時
dp[i][j] = max(dp[i+1][j] + a[i], dp[i][j-1] + a[j]);

IOIちゃんから始まる時
(a[i] > a[j]の時)
dp[i][j] = dp[i+1][j] 

(a[i] < a[j]の時)
dp[i][j] = dp[i][j-1] 
//*/

vector<vector<long long>> dp;
vector<int> a;
int n;

// l, rは円環におけるインデックス、sはどちらがスタートか s == 1でIOIのばん
long long rep(int l, int r, int s) {
    if (dp[l][r] != -1) return dp[l][r];//計算済みならそれを使う
    if (l == r) {
        // もし最後のピースの時にIOIの時(s == 1)は値は増加しない。
        // JOIの時(s == 1) は値はそのピースの値になる。
        if (s == 1) {
            return dp[l][r] = 0;
        } else {
            return dp[l][r] = a[l];
        }
    }

    if (s == 1) {
        if (a[l] > a[r]) {
            return dp[l][r] = rep((l+1)%n, r, 0);
        } else {
            return dp[l][r] = rep(l, (r+n-1) % n, 0);
        }
    }

    return dp[l][r] = max(rep((l+1)%n, r, 1) + a[l], rep(l, (r+n-1) % n, 1) + a[r]);
}

int main() {
    cin >> n;
    a.resize(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }

    dp.assign(n, vector<long long>(n, -1));
    long long ret = 0;
    for (int i = 0; i < n; i++) {
        // lとrの渡し方は円環になっているから、これでいい。
        // l = (i+1)%n, r = (i+n-1)%nはそれぞれ
        // [1, 2, 3, 4, 0] [4, 0, 1, 2, 3]となる。
        // つまり、dp[1][4] + a[0], dp[2][0] + a[1], dp[3][1] + a[2], dp[4][2] + a[3], dp[0][3] + a[4]となる。
        // 区間で見ると少し違和感を感じるが、これは円環なので良い。
        ret = max(ret, rep((i+1)%n, (i+n-1)%n, 1) + a[i]);
    }
    cout << fixed << setprecision(10) << ret << endl;
    return 0;
}