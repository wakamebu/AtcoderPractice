#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using ll = long long;
using P = pair<int,int>;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> A(n);
    rep(i,n)cin >> A[i];

    sort(A.begin(), A.end());

    int md = INT_MAX;

    for (int i = 0; i <= n - (n - k); i++) {
        int cd = A[i + (n - k - 1)] - A[i];
        md = min(md, cd);
    }

    cout << md << endl;
    return 0;
}