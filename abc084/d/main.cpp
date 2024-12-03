#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define REP1(i, n) for (auto i = std::decay_t<decltype(n)>{}; (i) != (n); ++(i))
#define REP2(i, l, r) for (auto i = (l); (i) != (r); ++(i))
#define rep(...) OVERLOAD_REP(__VA_ARGS__, REP2, REP1)(__VA_ARGS__)

vector<int> makeBitPrimes(int n) {
    vector<int> v(n + 1, 1);
    v[0] = v[1] = 0;
    for (int i = 2; i * i <= n; i++) {
        if (v[i]) {
            for (int j = i * i; j <= n; j += i) {
                v[j] = 0;
            }
        }
    }
    return v;
}

int main() {
    int q;
    cin >> q;

    auto ps = makeBitPrimes(101010);
    vector<int> A(101010, 0);
    vector<int> B(101010, 0);
    for (int i = 1; i <= 101010; i++) {
        if (ps[i] && (i + 1) % 2 == 0 && ps[(i + 1) / 2]) {
            A[i] = 1;
        }
    }
    for (int i = 1; i <= 101010; i++) {
        B[i] = B[i - 1] + A[i];
    }

    while (q--) {
        int l, r;
        cin >> l >> r;
        int ans = B[r] - B[l - 1];
        cout << ans << endl;
    }

    return 0;
}
