#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using ll = long long;
using P = pair<int,int>;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main() {
  int n,s,m,l;
  cin >> n>> s >> m >> l;

  int ans = 100000000;
  for(int a=0; a<=100; a++){
    for(int b=0; b<=100; b++){
      for(int c=0; c<=100; c++){
        if(a*6 + b*8 + c*12 >= n){
          ans=min(ans, a*s + b*m + c*l);
        }
      }
    }
  }
  cout << ans << endl;
  return 0;
}