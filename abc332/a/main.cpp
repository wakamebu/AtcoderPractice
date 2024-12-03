#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using ll = long long;
using P = pair<int,int>;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main() {
  int n,s,k;
  cin >> n >> s >> k;

  int sum = 0;

  rep(i,n){
    int p,q;
    cin >> p >> q;
    sum += (p*q);
  }

  if(sum <s)sum += k;

  cout << sum << endl;
  return 0;
}