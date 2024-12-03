#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using ll = long long;
using P = pair<int,int>;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main() {
  ll n,k;
  cin >> n >> k;
  set<ll> A;

  rep(i,n){
    ll a;
    cin >> a;
    if(a <= k){
    A.insert(a);
    }
  }

  ll sumA =0;
  for(auto x :A){
    sumA += x;
  }

  ll sumK = k * (k+1)/2;
  
  cout << (sumK - sumA) << endl;
  return 0;
}