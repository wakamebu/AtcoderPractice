#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using ll = long long;
using P = pair<int,int>;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main() {
  int n,l;
  cin >> n >> l;
  vector<int> a;

  rep(i,n){
    int b;
    cin >> b;
    a.push_back(b);
  }
  
  int ans = 0;
  for(auto x :a){
    if(x >= l)ans++;
  }

  cout << ans << endl;
  return 0;
}