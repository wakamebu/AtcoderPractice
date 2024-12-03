#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using ll = long long;
using P = pair<int,int>;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main() {
  int a,b;
  cin >> a >> b;
  int x = 1,y=1;
  rep(i,b) x *= a;
  rep(i,a) y *= b;
  
  cout << x+y << endl;
  return 0;
}