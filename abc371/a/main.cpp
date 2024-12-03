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
    char S_AB, S_AC, S_BC;
    cin >> S_AB >> S_AC >> S_BC;

    vector<char> brothers = {'A', 'B', 'C'};
    vector<pair<char, char>> inequalities;

    // Collect inequalities based on the input
    if (S_AB == '<') {
        inequalities.push_back({'A', 'B'});
    } else {
        inequalities.push_back({'B', 'A'});
    }

    if (S_AC == '<') {
        inequalities.push_back({'A', 'C'});
    } else {
        inequalities.push_back({'C', 'A'});
    }

    if (S_BC == '<') {
        inequalities.push_back({'B', 'C'});
    } else {
        inequalities.push_back({'C', 'B'});
    }

    // Try all permutations to find the valid one
    do {
        bool valid = true;
        for (auto& ineq : inequalities) {
            char less = ineq.first;
            char more = ineq.second;
            auto pos_less = find(brothers.begin(), brothers.end(), less) - brothers.begin();
            auto pos_more = find(brothers.begin(), brothers.end(), more) - brothers.begin();
            if (pos_less >= pos_more) {
                valid = false;
                break;
            }
        }
        if (valid) {
            // The second element is the middle brother
            cout << brothers[1] << endl;
            return 0;
        }
    } while (next_permutation(brothers.begin(), brothers.end()));

    // Since the input is guaranteed to be consistent, we should never reach here
    return 0;
}