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
  int n,m;
  cin >> n >> m;

  vector<vector<int>> cont(n,vector<int>(n,0));//n人の人間がそれぞれn人と知り合いかどうか
  rep(i,m){
    int x,y;
    cin >> x >> y;
    x--;
    y--;
    cont[x][y] = 1;
    cont[y][x] = 1;
  }
  
  rep(i,n){
    rep(j,n){
      if(i == j)cont[i][j] = 1;//最低その人自身を派閥に加えることができる
    }
  }

  int ans = 0;
  for(int msk = 0; msk< (1 << n) ; msk++){//全ての人の組み合わせを試す
    bool clique = true;
    vector<int> group;
    rep(i,n){//それぞれの人がお互いに知り合いかをチェックする
      if(msk & (1 << i)){
        group.push_back(i);//全てのグループを1になったフラグだけを集合して列挙
      }
    }
    
    rep(i,group.size()){//すべてのグループをチェック
      rep(j,i+1,group.size()){
        if(!cont[group[i]][group[j]]){
          clique = false;
          break;
        }
      }
      if(!clique)break;
    }
    if(clique){
      ans = max(ans,(int)group.size());
    }
  }
  cout << ans << endl;
  return 0;
}