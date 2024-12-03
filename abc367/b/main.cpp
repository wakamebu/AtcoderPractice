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
    double X;
    cin >> X;
    
    // 小数点以下3位まで表示する
    string result = to_string(X);
    
    // 小数点以下3位までの部分を抽出
    size_t pos = result.find('.');
    if (pos != string::npos) {
        result = result.substr(0, pos + 4);  // 小数点以下3桁まで取得
    }

    // 末尾の0を削除
    while (result.back() == '0') {
        result.pop_back();
    }

    // 末尾に小数点が残る場合、それを削除
    if (result.back() == '.') {
        result.pop_back();
    }

    cout << result << endl;

    return 0;
}