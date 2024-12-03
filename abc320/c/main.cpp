#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using ll = long long;
using P = pair<int,int>;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main() {
  int m;
  cin >> m;

  vector<string> s(3);
  rep(i,3)cin >> s[i];

  const int INF = 1001001001;
  int ans =INF;
  vector<int> p = {0,1,2};
  rep(d,10){
    char c = '0' + d;
        do{ 
          int t = -1;
          rep(i,3){
            t++;
            while(t<300 && s[p[i]][t%m] != c) t++;
          }
        if(t<300) ans = min(ans,t);
      } while (next_permutation(p.begin(),p.end()));
    }

  if(ans == INF) ans = -1;
  cout << ans << endl;
  return 0;
}