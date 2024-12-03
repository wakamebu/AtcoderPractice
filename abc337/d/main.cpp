#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using ll = long long;
using P = pair<int,int>;
#define rep(i,n) for(int i = 0; i < (n); i++)

int solve(string s, int k){
  int n= s.size();
  int res = 1e8;
  {
    int xs = 0, es = 0, len = 0;

    rep(i,n){
      xs += s[i]=='x';
      es += s[i]=='.';
      len++;
      if(len > k){
        xs -= s[i-k]=='x';
        es -= s[i-k]=='.';
        len--;
      }
      if(len == k){
        if(xs == 0)res = min(res,es);
      }
    }
  }
  return res;
}


int main() {
  int h,w,k;
  cin >> h >> w >> k;
  vector<string> s(h);
  rep(i,h) cin >> s[i];

  int ans = 1e8;
  rep(ri,2){
    rep(i,h) ans = min(ans,solve(s[i],k));
    {
      vector<string> t(w,string(h,'.'));
      rep(i,h)rep(j,w) t[j][i] = s[i][j];
      swap(h,w);
      s  = t;
    }
  }

  if(ans == 1e8) ans = -1;
  cout << ans << endl;
  return 0;
}