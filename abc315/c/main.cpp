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

  vector<P> ice(n);

  rep(i,n){
    int f,s;
    cin >> f >> s;
    P a = make_pair(s,f);
    ice[i] = a;
  }

  sort(ice.rbegin(),ice.rend());

  int ans = ice[0].first;
  for(int i = 1 ; i < n; i++){
  int res = 0;
  int fla = ice[0].second;
  if(ice[i].second != fla) res = ice[i].first;
  else res = ice[i].first/2;
  int t = ice[0].first + res;
  ans = max(t,ans);
  }

  cout << ans << endl;
  return 0;
}