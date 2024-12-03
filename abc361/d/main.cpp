#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using ll = long long;
using P = pair<int, int>;
#define rep(i, n) for (int i = 0; i < (n); i++)

int main() {
    int n;
    cin >> n;

    string s, t;
    cin >> s >> t;

    if (s == t) {
        cout << "0" << endl;
        return 0;
    }

    int cnt_w = 0, cnt_b = 0;
    for (int i = 0; i < n; ++i) {
        if (s[i] != t[i]) {
            if (s[i] == 'W') cnt_w++;
            else cnt_b++;
        }
    }

    if (cnt_w != cnt_b) {
        cout << "-1" << endl;
        return 0;
    }

    int moves = cnt_w; 

    cout << moves << endl;

    return 0;
}