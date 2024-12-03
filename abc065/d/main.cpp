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

class UnionFind{
    public:
    vector<ll> parent;//parent[i] = iの親
    vector<ll> siz;
    map<ll,vector<ll>> group; //集合ごとに管理する(key:集合の代表元、value:集合の要素の配列)
    ll n;//要素数

    UnionFind(ll n_):n(n_),parent(n_),siz(n_,1){//はじめ、全ての要素の根は自分自身である
        for(ll i = 0; i < n; i++){parent[i] = i;}
    }

    ll root(ll x){//データxの属する木の根を取得(経路圧縮も行う)
        if(parent[x] == x) return x;
        return parent[x] = root(parent[x]);//代入式の値は代入した変数の値なので、経路圧縮できる
    }

    void unite(ll x, ll y){
        ll rx = root(x);
        ll ry = root(y);
        if(rx == ry) return;//同じ木なら帰る
        if(siz[rx]<siz[ry]) swap(rx,ry);
        siz[rx]+=siz[ry];
        parent[ry] = rx;//xとyが同じ木にない時はyの根ryをxの根rxにつける
    }

    bool same(ll x, ll y){
        ll rx = root(x);
        ll ry = root(y);
        return rx == ry;
    }

    ll size(ll x){
        return siz[root(x)];
    }

    //素集合をグループ化
    void grouping(){
        rep(i,n)root(i);
        rep(i,n)group[parent[i]].emplace_back(i);
    }

    //素集合を削除して初期化
    void clear(){
        rep(i,n){parent[i] = i;}
        siz = vector<ll>(n,1);
        group.clear();
    }
};


struct city{
  int x;
  int y;
  int num;
  bool operator<(const city& e) const {return this->x<e.x;}
};

struct edge{
  int from;
  int to;
  int cost;
  bool operator<(const edge& e) const {return this->cost<e.cost;}
};

int main() {
  int n;
  cin >> n;

  vector<city> cities(n);
  vector<city> cities2(n);

  rep(i,n){
    int a, b;
    cin >> a >> b;
    cities[i] = {a,b,i};
    cities2[i] = {b,a,i};
  }

  sort(all(cities));
  sort(all(cities2));
  vector<edge> edges;

  for(int i = 0;i<n-1;i++){
    auto[a,b,c] = cities[i];
    auto[d,e,f] = cities[i+1];
    int cost = abs(a-d);
    edges.push_back({c,f,cost});
  }

  for(int i = 0;i<n-1;i++){
    auto[a,b,c] = cities2[i];
    auto[d,e,f] = cities2[i+1];
    int cost = abs(a-d);
    edges.push_back({c,f,cost});
  }

  sort(all(edges));

		UnionFind uf(n);
		ll ans = 0;
		for(const auto& e : edges) {
			if(!uf.same(e.from, e.to)) {
				uf.unite(e.from, e.to);
				ans += e.cost;
			}
		}

  cout << ans << endl;
  return 0;
}