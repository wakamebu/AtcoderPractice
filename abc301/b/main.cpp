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
  int n;
  cin >> n;

  queue<int> a;
  rep(i,n){
    int c;
    cin >> c;
    a.push(c);
  }

  queue<int> ans;
  int t = a.front();
  a.pop();
  ans.push(t);
  while (!a.empty()) {
        int v = a.front();
        a.pop();
        int res = abs(t - v);
        
        if (res <= 1) {
            t = v;
            ans.push(v);
            continue;
        }

        if (t > v) {
            while (t > v) {
                t--;
                ans.push(t);
            }
        } else {
            while (t < v) {
                t++;
                ans.push(t);
            }
        }
        t = v;
    }

  while(!ans.empty()){
    cout << ans.front() << " ";
    ans.pop();
  }
  cout << endl;
  return 0;
}