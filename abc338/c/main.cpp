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
  vector<int> q(n);//max
  vector<int> A(n);
  vector<int> B(n);

  rep(i,n){
    cin >> q[i];
  }
  rep(i,n){
    cin >> A[i];
  }
  rep(i,n){
    cin >> B[i];
  }

  int ans = 0;
  for(int x = 0;;x++){
    vector<int> r(n);
    rep(i,n) r[i] = q[i] - A[i]*x;
    bool ok = true;
    rep(i,n) if(r[i] < 0) ok = false;
    if(!ok) break;
    int y = 1e6;
    rep(i,n){
      if(B[i] == 0)continue;
      y = min(y, r[i]/B[i]);
    }
    ans = max(ans,x+y);
  }
  cout << ans << endl;  
  return 0;
}