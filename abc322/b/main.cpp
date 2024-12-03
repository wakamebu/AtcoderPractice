#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using ll = long long;
using P = pair<int,int>;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main() {
  int n,m;
  cin >> n >> m;
  string s;
  string t;
  cin >> s >> t;

  string rs , rt;
  rs = s;
  rt = t;
  reverse(rs.begin(),rs.end());
  reverse(rt.begin(),rt.end());

  string pret = t.substr(0,n);
  string suft = rt.substr(0,n);

  if(pret == s and suft == rs)cout << 0 <<endl;
  else if(pret == s and suft != rs)cout << 1 << endl;
  else if(pret != s and suft == rs)cout << 2 << endl;
  else cout << 3 << endl; 

  return 0;
}