#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using ll = long long;
using P = pair<int,int>;

int main() {
    int n, m;
    cin >> n >> m;

    vector<int> A(m);
    // 必要な栄養素
    for (int i = 0; i < m; i++) {
        cin >> A[i];
    }

    vector<int> sum(m, 0);
    vector<int> kari(m);
    // 接種した栄養素
    // n番目の食事からそれぞれm種類目の栄養素をX接種
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < m; i++) {
            cin >> kari[i]; // X
        }
        for (int j = 0; j < m; j++) {
            sum[j] += kari[j];
        }
    }

    bool good = true;
    for (int i = 0; i < m; i++) {
        if (sum[i] < A[i]) {
            good = false;
            break;
        }
    }

    if (good) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }

    return 0;
}