#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using ll = long long;
using P = pair<int,int>;
using vvi = vector<vector<int>>;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main() {
  int h,w;
  cin >> h >> w;

  vector<vector<int>> A(h,vector<int>(w));
  vector<vector<int>> B(h,vector<int>(w));

  rep(i,h){
    rep(j,w){
      cin >> A[i][j];
    }
  }
  rep(i,h){
    rep(j,w){
      cin >> B[i][j];
    }
  }

  queue<vvi> q;
  map<vvi,int> dist;

  auto push = [&](vvi& s,int d){
    if (dist.count(s)) return;
    dist[s] = d;
    q.push(s);
  };
  push(A,0);
  while(!q.empty()){
    vvi s = q.front();
    q.pop();
    int d = dist[s];
    rep(i,h-1){
      vvi ns = s;
      swap(ns[i],ns[i+1]);
      push(ns,d+1);
    }
    rep(j,w-1){
      vvi ns = s;
      rep(i,h) swap(ns[i][j] , ns[i][j+1]);
      push(ns,d+1);
    }
  }


  if(dist.count(B)) cout << dist[B] << endl;
  else cout << -1 << endl;
  return 0;
}