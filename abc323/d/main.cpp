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

  map<ll,ll> mp;
  rep(i,n){
    int s,c;
    cin >> s >> c;
    mp[s] = c;
  }

  int ans = 0;

  while(mp.size()){
    auto it = mp.begin();
        ll s = it->first;
        ll c = it->second;
    mp.erase(mp.begin());
    ans += c%2;
    s *=2 ;c/=2;
    if(c) mp[s]+=c;
  }

  cout << ans << endl;
  return 0;
}