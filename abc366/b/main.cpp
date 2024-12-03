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

  vector<string> t(n);
  rep(i,n)cin >> t[i];

  int len = 0;
  rep(i,n)len = max(len, (int)t[i].size());

  vector<string> ts(len);
    for(int i = 0; i < len; ++i) {
        for(int j = 0; j < n; ++j) {
            if(i < t[j].size()) {
                ts[i].push_back(t[j][i]);
            } else {
                ts[i].push_back('*');
            }
        }
    }

  rep(i,len){
    reverse(all(ts[i]));
  }

  for(int i = 0; i < len; ++i) {
        while (!ts[i].empty() && ts[i].back() == '*') {
            ts[i].pop_back();
        }
        while (ts[i].size() < n) {
            ts[i].push_back(' ');
        }
    }

  for(auto row : ts) {
                cout << row << endl;
    }
  return 0;
}