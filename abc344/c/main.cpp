#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using ll = long long;
using P = pair<int,int>;
#define rep(i,n) for(int i = 0; i < (n); i++)


int main() {
  int n;
  cin >> n;
  vector<int> A(n);
  rep(i,n)cin >> A[i];
  
  int m,l;
  cin >> m;
  vector<int> B(m);
  rep(i,m)cin >> B[i];

  cin >> l;
  vector<int> C(l);
  rep(i,l)cin >> C[i];

  int q;
  cin >> q;
  vector<int> Q(q);
  rep(i,q)cin >> Q[i];

  set<ll> ans;
  rep(i,n){
    rep(j,m){
      rep(k,l){
        ans.insert(A[i]+B[j]+C[k]);
      }
    }
  }

  rep(i,q){
    int x = 0;
    x = Q[i];
    if(ans.count(x)){
      cout << "Yes" << endl;
    }else{
      cout << "No" << endl;
    }
  }
  return 0;
}