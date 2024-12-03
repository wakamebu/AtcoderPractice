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
    int N;
    ll X ,Y;
    cin >> N >> X >> Y;
    vector<pair<ll, ll>> dishes(N);
    
    for (int i = 0; i < N; ++i) {
        cin >> dishes[i].first;
    }
    for (int i = 0; i < N; ++i) {
        cin >> dishes[i].second;
    }


    // 料理を甘さ優先でソートする
    sort(dishes.begin(), dishes.end(), [](pair<ll, ll> a, pair<ll, ll> b) {
        return a.first > b.first;
    });

    // 甘さの合計が X を超える最小の料理数を探す
    long long sumA = 0, sumB = 0;
    int countA = 0;
    for (int i = 0; i < N; ++i) {
        sumA += dishes[i].first;
        sumB += dishes[i].second;
        countA++;
        if (sumA > X || sumB > Y) {
            break;
        }
    }
    int minDishes = countA;

     // 料理をしょっぱさ優先でソートする
    sort(dishes.begin(), dishes.end(), [](pair<ll, ll> a, pair<ll, ll> b) {
        return a.second > b.second;
    });

    // しょっぱさの合計が Y を超える最小の料理数を探す
    sumA = 0, sumB = 0;
    int countB = 0;
    for (int i = 0; i < N; ++i) {
        sumA += dishes[i].first;
        sumB += dishes[i].second;
        countB++;
        if (sumA > X || sumB > Y) {
            break;
        }
    }
    minDishes = min(minDishes, countB);

    cout << minDishes << endl;

    return 0;
}