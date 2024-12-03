#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using ll = long long;
using P = pair<int,int>;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main() {
  vector<ll> ans;
  int n;
  cin >> n;

  rep(s,1<<10){
    ll x = 0;
    for(int i = 9; i>= 0 ; i--){
      if(s>>i&1){
        x = x*10 + i;
      }
    }
    if (x == 0) continue;
    ans.push_back(x); 
  }
  sort(ans.begin(),ans.end());

  cout << ans[n-1] << endl;
  return 0;
}