#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, int>;

#define OVERLOAD_REP(_1, _2, _3, name, ...) name
#define REP1(i, n) for (auto i = std::decay_t<decltype(n)>{}; (i) != (n); ++(i))
#define REP2(i, l, r) for (auto i = (l); (i) != (r); ++(i))
#define rep(...) OVERLOAD_REP(__VA_ARGS__, REP2, REP1)(__VA_ARGS__)
#define all(...) std::begin(__VA_ARGS__), std::end(__VA_ARGS__)
#define rall(...) std::rbegin(__VA_ARGS__), std::rend(__VA_ARGS__)


ll modpow(ll a,ll n,ll mod){
    ll res = 1;
    while(n > 0){
        if(n & 1)res = res * a % mod;
        a = a*a % mod;
        n >>=1;
    }
    return res;
}

int main() {
    ll n , m;
    cin >> n >> m;
    ll mod =  1000000007;

    cout << modpow(n,m,mod) << endl;
    return 0;
}