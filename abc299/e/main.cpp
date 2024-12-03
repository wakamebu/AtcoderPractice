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
  vector<vector<int>> G(n);

  rep(i,m){
    int u,v;
    cin >> u >> v;
    u--; v--;
    G[u].push_back(v);
    G[v].push_back(u);
  }

  int k;
  cin >> k;
  vector<P> t(k);
  if(k == 0){
    cout << "Yes" << endl;
    rep(i,n){
      cout << 1 ;
    }
    cout << endl;
    return 0;
  }

  //1 = black 0 = white
  vector<int> ans(n,1);

  //すべての頂点pから、最も近い黒で塗られた頂点xとの距離がちょうどd
  rep(i,k){
    int p , d;
    cin >> p >> d;
    p--;
    t[i] = {p,d};

    //すべての頂点を黒にして、途中で不適切な黒を見つけたら白に塗る
    vector<int> dist(n,-1);
    queue<int> que;
    dist[p] = 0;
    que.push(p);

    while(!que.empty()){
      int v = que.front();
      que.pop();
      if(dist[v] >= d)continue;
      ans[v] = 0;
      for(int nv : G[v]){
        if(dist[nv] != -1) continue;
        dist[nv] = dist[v] + 1;
        que.push(nv);
      }
    }
  }

  rep(i,k){
    int p , d;
    p = t[i].first;
    d = t[i].second;

    vector<int> dist(n,-1);
    queue<int> que;
    dist[p] = 0;
    que.push(p);
    bool found = false;

    while(!que.empty()){
      int v = que.front();
      que.pop();
      if(dist[v] > d) break;
      if(dist[v] == d && ans[v] == 1){
        found = true;
        break;
      }
      for(int nv : G[v]){
        if(dist[nv] != -1) continue;
        dist[nv] = dist[v] + 1;
        que.push(nv);
      }
    }
    if(!found){
      cout << "No" << endl;
      return 0;
    }
  }

  if(find(ans.begin(),ans.end(),1) == ans.end()){
    cout << "No" << endl;
    return 0;
  }

  cout << "Yes" << endl;
  rep(i,n){
    cout << ans[i];
  }
  cout << endl;
  return 0;
}