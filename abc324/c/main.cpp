#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using ll = long long;
using P = pair<int,int>;
#define rep(i,n) for(int i = 0; i < (n); i++)

ll calc(const string &s, const string &t) {
    for (int i = 0; i < (int)t.size(); i++) {
        if (i >= (int)s.size()) return s.size();
        if (s[i] != t[i]) return i;
    }
    return t.size();
}

int main() {
    ll n;
    cin >> n;
    string t2;
    cin >> t2;
    vector<string> s(n + 1);
    vector<ll> a(n + 1), b(n + 1);

    for (int i = 1; i <= n; i++) cin >> s[i];
    for (int i = 1; i <= n; i++) a[i] = calc(s[i], t2);
    reverse(t2.begin(), t2.end());
    for (int i = 1; i <= n; i++) {
        reverse(s[i].begin(), s[i].end());
        b[i] = calc(s[i], t2);
        reverse(s[i].begin(), s[i].end()); // Reverse back to original
    }

    reverse(t2.begin(), t2.end()); // Reverse back to original

    vector<ll> ans;
    for (int i = 1; i <= n; i++) {
        const string &t = s[i];
        bool flag = false;
        if(a[i] == t.size() && t.size() == t2.size()) flag = true;
        if(a[i]+b[i] >= t.size() && t.size()+1 == t2.size()) flag = true;
        if(a[i]+b[i] >= t.size()-1 && t.size()-1 == t2.size()) flag = true;
        if(a[i]+b[i] == t.size()-1 && t.size() == t2.size()) flag = true;
        if (flag) ans.push_back(i);
    }

    cout << ans.size() << endl;
    for (auto x : ans) cout << x << " ";
    cout << endl;

    return 0;
}