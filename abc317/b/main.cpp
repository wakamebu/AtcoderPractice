#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using ll = long long;
using P = pair<int,int>;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main() {
  int n;
  cin >> n;

  vector<int> a(n);
  rep(i,n) cin >> a[i];

  sort(a.begin(),a.end());

  rep(i,n-1){
    int p = a[i];
    if(p+1 != a[i+1]){
      cout << p+1 << endl;
    }
  }
  return 0;
}