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


bool contains_palindrome(const string& str, int K) {
    int n = str.size();
    for (int i = 0; i <= n - K; ++i) {
        bool is_palindrome = true;
        for (int j = 0; j < K / 2; ++j) {
            if (str[i + j] != str[i + K - 1 - j]) {
                is_palindrome = false;
                break;
            }
        }
        if (is_palindrome) {
            return true;
        }
    }
    return false;
}

int main() {
  int n,k;
  cin >> n >> k;
  string s;
  cin >> s;

  sort(s.begin(),s.end());
  set<string> unique;

  do {
        // 長さ K の回文を含まない場合にカウント
        if (!contains_palindrome(s, k)) {
            unique.insert(s);
        }
    } while (next_permutation(all(s)));

  cout << unique.size() << endl;
  return 0;
}