#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using ll = long long;
using P = pair<int,int>;
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
    string s, t;
    cin >> s >> t;

    if (s.size() != t.size()) {
        cout << "No" << endl;
        return 0;
    }

    map<char, int> S, T;
    for (char c : s) S[c]++;
    for (char c : t) T[c]++;

    string atcoder = "atcoder";

    // 各文字の差分を補正
    for (char c = 'a'; c <= 'z'; c++) {
        int diff = S[c] - T[c];
        if (diff > 0) {
            if (atcoder.find(c) != string::npos) {
                T['@'] -= diff;
            } else {
                cout << "No" << endl;
                return 0;
            }
        } else if (diff < 0) {
            if (atcoder.find(c) != string::npos) {
                S['@'] += diff;
            } else {
                cout << "No" << endl;
                return 0;
            }
        }
    }

    // '@' の数が両方で十分にあるか確認
    if (S['@'] >= 0 && T['@'] >= 0) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }

    return 0;
}