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

  vector<int> c(2*n);

  rep(i,2*n) cin >> c[i];

  int cnt = 0;
  rep(i,2*n-2){
    if(c[i] == c[i+2])cnt++;
  }


  cout << cnt << endl;
  return 0;
}