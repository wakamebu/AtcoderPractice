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

  vector<P> m;

  rep(i,n){
    int w,x;
    cin >> w >> x;
    m.push_back(make_pair(w,x));
  }

  int ans = 0;
  rep(i,24){
  int res = 0;
    for(auto x : m){
      int time = i+x.second;
      if (time >= 24) time -= 24;
      if (time >= 9 && time <= 17) {
                res += x.first;
            }
    }
      ans = max(res,ans);
  }

  cout << ans << endl;
  return 0;
}