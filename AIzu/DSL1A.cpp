#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int, int>;

#define all(v) (v).begin(), (v).end()
#define rep(i, n) for (int i = 0; i < (n); i++)
const int INF = 1 << 20;

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



int main() {
    int n, q;
    cin >> n >> q;
    UnionFind uf(n);

    for (int i = 0; i < q; ++i) {
        int com, x, y;
        cin >> com >> x >> y;
        if (com == 0) {
            uf.unite(x, y);
        } else {
            cout << (uf.same(x, y) ? 1 : 0) << endl;
        }
    }
    return 0;
}