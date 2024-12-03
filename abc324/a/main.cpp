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

  rep(i,n){
    cin >>a[i];
  }
  rep(i,n-1){
    if(a[i+1]!= a[i]){
    cout << "No" << endl;
    return 0;
  }
  }

  cout << "Yes" << endl;
  return 0;
}