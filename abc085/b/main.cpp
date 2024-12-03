#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using ll = long long;
using P = pair<int,int>;

int main() {
  int n;
  cin >> n;

  set<int> mochi;
  for(int i = 0; i<n ; i++){
    int d;
    cin >> d;
    mochi.insert(d);
  }

  int ans = mochi.size();

  cout << ans << endl;
  return 0;
}