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
    vector<int> a(n);
    rep(i, n) {
        cin >> a[i];
    }

    map<int,vector<int>> d;
    rep(i,n)d[a[i]].push_back(i);


    ll s = accumulate(a.begin(),a.end(),0ll);
    vector<ll> ans(n);
    for(auto[v,i_list]:d){
      s -= (ll)v*i_list.size();
      for(auto i : i_list)ans[i] = s;
    }

    for(auto x :ans)cout << x << ' ';

    return 0;
}
