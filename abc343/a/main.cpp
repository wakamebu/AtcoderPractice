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

  if(n>m){
    swap(n,m);
  }

  int ans = -1;

  rep(i,10){
    if(ans<0){
      ans++;
    }else if(ans == n+m){
      ans++;
    }
  }

  cout << ans << endl;
  return 0;
}