#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using ll = long long;
using P = pair<int,int>;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main() {
  int n ,a;
  cin >> n;
  vector<string> s(n);
  int it = 1e9;
  rep(i,n){
    cin >> s[i];
    cin >> a;
    it = min(a,it);
  }

  rep(i,n){
    s.emplace_back(s[i]);
  }

  for(int i = a;i<n+a;i++){
    cout << s[i] << endl;
  }
  return 0;
}