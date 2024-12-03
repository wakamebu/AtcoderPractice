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
  string s;
  cin >> s;

  map<char,int> t;
  char c = 'a';
  rep(i,26){
    c += i;
    t[c] = 0;
  }

  int res = 1;
  rep(i,n-1){
    if(s[i+1] == s[i])res++;
    else{
      if(t[s[i]] < res){
        t[s[i]]  = res;
      }
      res = 1;
    }
  }

  if (t[s[n-1]] < res) {
        t[s[n-1]] = res;
    }

  int ans = 0;
  for(auto x : t){
    ans += x.second;
  }

  cout << ans << endl;
  return 0;
}