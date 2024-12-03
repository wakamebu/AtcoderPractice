#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using ll = long long;
using P = pair<int,int>;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main() {
  ll n,m,k;
  cin >> n >> m >> k;

  ll out = n*m;

  if(n>m) swap(n,m);
  int it1 = 1;
  int it2 = 0;
  int ans = n;
  while(ans < out){
    if(it2+1*m > n*it1+1){
      it1++;
      ans += n;
    }else if(it2+1*m < n*it1+1){
      it2++;
      ans += m;
    }else if(it2+1*m == n*it1+1){
      ans += n;
    }
  }

  cout << it1 << ":" << it2 << endl;
  return 0;
}