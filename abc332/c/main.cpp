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
  vector<int> s(n);

  rep(i,n){
    char a;
    cin >> a;
    int x = a - '0';
    s[i] = x;
  }

  int usedx = 0;
  int usedy = 0;
  int need = 0;
  int res = 0;
  int x = 0;
  int y = m;
  rep(i,n){
    int xt = s[i];
    if(xt == 2){
      if(x > 0){
      x --;
      usedx++;
      }else{
        need++;
        usedx++;
      }
    }else if(xt == 1){
      if(x + y >0){
        if(y > 0){
          y--;
          usedy++;
        }else{
          x--;
          usedx++;
        }
      }else{
          need++;
          usedx++;
        }
    }else if(xt == 0){
        x += usedx;
        y += usedy;
        usedx = 0;
        usedy = 0;
    }
    res = max(res,need);
  }

  cout << res << endl;
  return 0;
}