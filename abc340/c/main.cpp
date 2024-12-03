#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using ll = long long;
using P = pair<int,int>;
#define rep(i,n) for(int i = 0; i < (n); i++)

unordered_map<ll,ll> memo;

ll sum(ll x){
  if(x == 1){
    return 0;
  }
  if (memo.count(x)) return memo[x];
  ll s = sum(x/2);
  ll m = sum((x+1)/2);
  ll res = x+s+m;
  return memo[x] = res;
}

int main() {
  ll x;
  cin >> x;

  cout << sum(x) << endl;  
  return 0;
}