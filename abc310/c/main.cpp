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
  set<string> s;
  rep(i,n) {
    string a;
    cin >> a;
    s.insert(a);
  }

  int ans = s.size();
  int res = 0;

  for(auto &x :s){
    string a = x;
    reverse(a.begin(),a.end());
    if(s.count(a) and a!= x)res++;
  }

  ans -= res/2;

  cout << ans << endl;
  return 0;
}