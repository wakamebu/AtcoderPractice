#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using ll = long long;
using P = pair<int,int>;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main() {
  int Atotal = 0;
  int Btotal = 0;

  rep(i,9){
    int A;
    cin >> A;
    Atotal += A;
  }

  rep(i,8){
    int B;
    cin >> B;
    Btotal += B;
  }

  int ans = Atotal - Btotal + 1;

  cout << ans << endl;
  return 0;
}