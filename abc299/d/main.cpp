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

  //中央あたりの値を切り上げで取得
  int mid = (n+1)/2;
  int m;
  //中央あたりの値を取ってくる
  cout << "? " << mid << endl;
  cin >> m;

  //はじめに与えられる制約より。
  int left = 0;
  int l = 0;
  int right = n;
  int r = 1;

  int focus = -1;
  if(m == 1){
    focus = 0;//左を探索する
  }else{
    focus = 1;//右を探索する
  }

  int ans = -1;
  int res = 0;
  if(focus == 0){
    //ここから二分探索
    while(left + 1 < mid){
      int left_mid = (left + mid)/2;
      cout << "? " << left_mid << endl;
      cin >> res;
      //どちらの端っこを動かすか？
      if(res == 1)mid = left_mid;
      else left = left_mid;
    }
    ans = left;
    cout << "! " << ans << endl;
    return 0;
  }

  if(focus == 1){
    while(mid + 1 < right){
      int right_mid = (right + mid)/2;
      cout << "? " << right_mid << endl;
      cin >> res;
      if(res == 0)mid = right_mid;
      else right = right_mid;
    }
    ans = mid;
    cout << "! " << ans << endl;
    return 0;
  }
}