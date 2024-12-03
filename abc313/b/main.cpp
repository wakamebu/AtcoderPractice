#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using ll = long long;
using P = pair<int,int>;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main() {
  int n,m;
  cin >> n >> m;

  vector<int> p(n,100);

  rep(i,m){
    int a ,b;
    cin >> a >> b;
    p[b-1] = p[a-1]-1;
  }

  int ans = 0;
  int pos = 0;
  rep(i,n){
    ans = max(ans,p[i]);
    if(ans == p[i])pos = i+1;
  }

  int cnt = 0;
  for(auto &x:p){
    if(x == ans){cnt ++;}
  }

  if(cnt == 1)cout << pos << endl;
  else cout << -1 << endl;
  return 0;
}