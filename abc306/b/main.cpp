#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using ll = long long;
using P = pair<int,int>;
#define rep(i,n) for(int i = 0; i < (n); i++)
using ull = unsigned long long;

int main() {
  int n;
  ull sum = 0;
  rep(i,64){
    ull a = 1;
    cin >> n;
    if(n == 0) continue;
    rep(j,i){
      a *= 2;
    }
    sum += a;
  }

  cout << sum << endl;
  return 0;
}