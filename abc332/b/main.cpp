#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using ll = long long;
using P = pair<int,int>;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main() {
  int k,g,m;
  cin >>k>>g>>m;


  int p = m;
  m = 0;
  int now = 0;
  rep(i,k){
    if(now == g){
      now = 0;
    }else if(m == 0){
      m = p;
    }else{
      if(m>g-now){
        m -= (g -now);
        now += g - now;
      }else{
        now += m;
        m = 0;
      }
    }
  }

  cout << now << " " << m <<endl;
  return 0;
}