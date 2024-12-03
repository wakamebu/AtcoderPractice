#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int, int>;

#define all(v) (v).begin(), (v).end()
#define rep(i, n) for (int i = 0; i < (n); i++)
const int INF = 1 << 20;

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    rep(i,n) cin >> a[i];

    vector<int> dp;
    for(int x: a){
        auto itr = lower_bound(all(dp),x);
        if(itr != dp.end()){
            *itr = x;
        }else{
            dp.push_back(x);
        }
    }
    int ans = dp.size();
    cout << ans << endl;
}