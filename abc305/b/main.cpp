#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using ll = long long;
using P = pair<int,int>;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main() {
  char p, q;
  cin >> p >> q;
  p -= 'A', q -= 'A';
  if(p > q) swap(p, q);
  int e[] = {3, 1, 4, 1, 5, 9}, ans = 0;
  for (int i = p; i < q; i++) ans += e[i];
  cout << ans << "\n";
}