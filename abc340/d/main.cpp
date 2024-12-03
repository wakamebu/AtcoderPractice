#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using ll = long long;
using P = pair<int,int>;
#define rep(i,n) for(int i = 0; i < (n); i++)

struct Edge{
  int to,cost;
  Edge() {}
  Edge(int to, int cost): to(to),cost(cost) {}
};


int main() {
  ll n;
  cin >> n;

  vector<vector<Edge>> g(n);

  rep(i,n-1){
    ll a,b,x;
    cin >> a>>b>>x;
    x--;
    g[i].emplace_back(i+1,a);
    g[i].emplace_back(x,b);
  }

//ここからダイクストラ
  const ll INF = 1e18;
  vector<ll> dist(n, INF);
  using p = pair<ll,int>;
  priority_queue<p,vector<p>,greater<p>> q;
  dist[0] = 0;
  q.emplace(0,0);

  while(!q.empty()){
    auto [d,v] = q.top(); q.pop();
    if (dist[v] != d) continue;
    for(auto e : g[v]){
      ll nd = d+e.cost;
      if(nd >= dist[e.to])continue;
      dist[e.to] = nd;
      q.emplace(nd, e.to);
    }
  }

  cout << dist[n-1] << endl;
  return 0;
}