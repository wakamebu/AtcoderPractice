#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using ll = long long;
using P = pair<int,int>;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main() {
    int n; ll t;
    cin >> n >> t;

    string s;
    cin >> s;

    vector<ll> x(n);
    for (int i = 0; i < n; ++i) {
        cin >> x[i];
    }

    vector<ll> right, left;
    for (int i = 0; i < n; ++i) {
        if (s[i] == '1') {
            right.push_back(x[i]);
        } else {
            left.push_back(x[i]);
        }
    }

    sort(right.begin(), right.end());
    sort(left.begin(), left.end());

    int l = 0, r  = 0;
    ll ans = 0;

    auto leftcount = [&](ll rant){
        return lower_bound(right.begin(),right.end(),left) - right.begin();
    };

    for(int i = 0; i < (int)right.size();i++){
    while (l < (int)left.size() && left[l] < right[i]) l++;
      while (r < (int)left.size() && left[r] <= right[i] + 2 * t) r++;
    ans += r - l;
    }

    cout << ans << endl;
    return 0;
}
