#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using ll = long long;
using P = pair<int,int>;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main() {
  int n,k;
  cin >> n >> k;

  vector<P> t(n);

  int ma = 0;

  rep(i,n){
    int a,b;
    cin >> a >> b;
    t.push_back(make_pair(a,b)); 
    ma = max(a,ma);
  }
  vector<ll> sum(ma+2,0); 

  for(auto x :t){
    int c = x.first;
    int d = x.second;
    sum[c] += d;
  }

  for(int i = ma;i>=0;i--){
    sum[i] += sum[i+1];
  }

  int ok = ma+1, ng = 0;
  if(sum[0] <= k) {cout << 1 << endl;  return 0;}
  while(ok-1 < ng){
    int res = (ok + ng)/2;
    if(sum[res] <= k)ok = res;
    else ng = res;
  }

  cout << ok << endl;
  return 0;
}