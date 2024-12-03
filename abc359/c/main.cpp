#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using ll = long long;
using P = pair<int,int>;
#define rep(i,n) for(int i = 0; i < (n); i++)


int main() {
    long Sx, Sy, Tx, Ty;
    cin >> Sx >> Sy >> Tx >> Ty;
    // タイルの左側に寄せておく
    if ((Sx + Sy) % 2 == 1) {
        --Sx;
    }
    if ((Tx + Ty) % 2 == 1) {
        --Tx;
    }
    // 答えは (|Sy - Ty| + max(|Sx - Tx|, |Sy - Ty|)) / 2
    long Dx = abs(Sx - Tx);
    long Dy = abs(Sy - Ty);
    
    cout << (Dy + max(Dx, Dy)) / 2 << endl;
    return 0;
}

