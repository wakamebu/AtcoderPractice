#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using ll = long long;
using P = pair<int,int>;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main() {
  int n,m;
  cin >> n >>m;
  map<string,int> c;
  vector<string> d(m);
  vector<int> p(m+1);

  rep(i,n) {
    string s;
    cin >> s;
    c[s]++;
  }
  rep(i,m) cin >> d[i];
  rep(i,m+1) cin >> p[i];

  int sum = 0;

  for(auto x :c){
    string s;
    rep(i,m){
      if(x.first == d[i]){sum += (p[i+1] * x.second); break;}
      if(i == m-1 and x.first != d[i])sum += (p[0]* x.second);
    }
  }

  cout << sum << endl;
  return 0;
}