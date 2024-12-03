#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using ll = long long;
using P = pair<int,int>;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main() {
    int a, b, c, d, e, f;
    int g, h, i, j, k, l;
    cin >> a >> b >> c >> d >> e >> f;
    cin >> g >> h >> i >> j >> k >> l;

    int x_min = max(a, g);
    int x_max = min(d, j);
    int y_min = max(b, h);
    int y_max = min(e, k);
    int z_min = max(c, i);
    int z_max = min(f, l);

    if (x_min < x_max && y_min < y_max && z_min < z_max) {
        int volume = (x_max - x_min) * (y_max - y_min) * (z_max - z_min);
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }

    return 0;
}