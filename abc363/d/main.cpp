#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using ll = long long;
using P = pair<int,int>;
using Graph = vector<vector<int>>;
#define OVERLOAD_REP(_1, _2, _3, name, ...) name
#define REP1(i, n) for (auto i = std::decay_t<decltype(n)>{}; (i) != (n); ++(i))
#define REP2(i, l, r) for (auto i = (l); (i) != (r); ++(i))
#define rep(...) OVERLOAD_REP(__VA_ARGS__, REP2, REP1)(__VA_ARGS__)
#define all(...) std::begin(__VA_ARGS__), std::end(__VA_ARGS__)
#define rall(...) std::rbegin(__VA_ARGS__), std::rend(__VA_ARGS__)
template<class T, size_t n, size_t idx = 0>
auto make_vec(const size_t (&d)[n], const T& init) noexcept {
    if constexpr (idx < n) return std::vector(d[idx], make_vec<T, n, idx + 1>(d, init));
    else return init;
}

template<class T, size_t n>
auto make_vec(const size_t (&d)[n]) noexcept {
    return make_vec(d, T{});
}



int main() {
    ll n;
    cin >> n;
    if(n ==1){
        cout << 0 << endl;
        return 0;
    }
    n--;

    for(int keta = 1 ;; keta++){
        int l = (keta+1)/2;
        ll num = 9;
        rep(i,l-1) num *=10;
        if(n > num){
            n -= num;
            continue;
        }
        n += num/9 - 1;
        string s = to_string(n);
        string rs = s;
        reverse(all(rs));
        if(keta%2 == 1) s.pop_back();
        s+= rs;
        cout << s << endl;
        return 0;
    }


}