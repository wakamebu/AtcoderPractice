#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, int>;

#define OVERLOAD_REP(_1, _2, _3, name, ...) name
#define REP1(i, n) for (auto i = std::decay_t<decltype(n)>{}; (i) != (n); ++(i))
#define REP2(i, l, r) for (auto i = (l); (i) != (r); ++(i))
#define rep(...) OVERLOAD_REP(__VA_ARGS__, REP2, REP1)(__VA_ARGS__)
#define all(...) std::begin(__VA_ARGS__), std::end(__VA_ARGS__)
#define rall(...) std::rbegin(__VA_ARGS__), std::rend(__VA_ARGS__)

const int MAX_N = 1000001;
const int INF = 1e+8;

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

struct edge{
	int from;
	int to;
	double cost;
	bool operator<(const edge& e) const {return this->cost<e.cost;}
};

struct cell{
	double x;
	double y;
	double z;
	double r;
	bool operator<(const cell& e) const {return this->r<e.r;}
};

int main() {
//	while(true) {
		int n;
		cin >> n;
//		if(n == 0) break; // ループを終了する

		vector<cell> cells;

		rep(i, n) {
			double a, b, c, d;
			cin >> a >> b >> c >> d;
			cells.push_back({a, b, c, d});
		}

		vector<edge> edges;

		for(int i = 0; i < n; i++) {
			auto[a, b, c, d] = cells[i];
			for(int j = i + 1; j < n; j++) { // j = i+1に変更
				auto[e, f, g, h] = cells[j];
				double dist = sqrt(pow(a - e, 2) + pow(b - f, 2) + pow(c - g, 2));
				dist -= (d + h);
				if(dist < 0) dist = 0;
				edges.push_back({i, j, dist});
			}
		}
		sort(all(edges));

		UnionFind uf(n);
		double ans = 0;
		for(const auto& e : edges) {
			if(!uf.same(e.from, e.to)) {
				uf.unite(e.from, e.to);
				ans += e.cost;
			}
		}
		cout << fixed << setprecision(3) << ans << endl;
//	}
	return 0;
}
