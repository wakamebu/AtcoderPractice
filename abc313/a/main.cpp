#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using ll = long long;
using P = pair<int,int>;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main() {
    int n;
    cin >> n;
    vector<int> p(n);
    for (int i = 0; i < n; i++) {
        cin >> p[i];
    }
    int m = 0;
    for (int i = 1; i < n; i++) {
        m = max(m, p[i]);
    }
    cout << max(0, m + 1 - p[0]) << endl;
}