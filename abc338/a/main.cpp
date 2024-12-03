#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using ll = long long;
using P = pair<int,int>;
#define rep(i,n) for(int i = 0; i < (n); i++)


int main() {
    string S;
    cin >> S;
    bool ans = isupper(S[0]);
    for (int i = 1; i < S.size(); ++i) {
        ans &= bool(islower(S[i]));
    }
    cout << (ans ? "Yes" : "No") << endl;
}