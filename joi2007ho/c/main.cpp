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
    int n;
    cin >> n;
    vector<P> points(n);
    set<P> pointSet;
    for (int i = 0; i < n; ++i) {
        cin >> points[i].first >> points[i].second;
        pointSet.insert(points[i]);
    }

    int maxArea = 0;

    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            int dx = points[j].first - points[i].first;
            int dy = points[j].second - points[i].second;
            
            P p3 = {points[i].first - dy, points[i].second + dx};
            P p4 = {points[j].first - dy, points[j].second + dx};

            if (pointSet.count(p3) && pointSet.count(p4)) {
                int area = dx * dx + dy * dy;
                maxArea = max(maxArea, area);
            }
            
            p3 = {points[i].first + dy, points[i].second - dx};
            p4 = {points[j].first + dy, points[j].second - dx};

            if (pointSet.count(p3) && pointSet.count(p4)) {
                int area = dx * dx + dy * dy;
                maxArea = max(maxArea, area);
            }
        }
    }

    cout << maxArea << endl;
    return 0;
}