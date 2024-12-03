#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using ll = long long;
using P = pair<int,int>;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main() {
  int h,w,n;
  cin >> h >> w >> n;

  string s;
  cin >> s;

  vector<char> grid(h*w);
  rep(i,h){
    rep(j,w){
    char l ;
    cin >> l;
    grid[(i*w)+j] = l;
    }
  }

  auto f = [&](auto x,auto y){
    if(y == 'L'){
      return x-1;
    }else if(y == 'R'){
      return x+1;
    }else if(y == 'U'){
      return x-w;
    }else if(y == 'D'){
      return x+w;
    }
    return x;
  };

  int now = 0;
  int ans = 0;
  rep(i, h * w) {
        if (grid[i] == '#') continue;
        int now = i;
        bool success = true;
        rep(j, n) {
            char c = s[j];
            now = f(now, c);
            if (grid[now] == '#') {
                success = false;
                break;
            }
        }
        if (success) {
            ans++;
        }
    }

  cout << ans << endl;
  return 0;
}