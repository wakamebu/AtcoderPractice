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
  vector<int> P(n);
  rep(i,n)cin >> P[i];
  int q;
  cin >> q;

      int aa = 0;
      int bb = 0;
  rep(i,q){
    int a,b = 0;
    cin >> a >> b;
    rep(j,n){
      if(a == P[j]){aa = j+1;
      }}
    rep(k,n){
        if(b == P[k])bb = k+1;}
    if(aa > bb){
          cout << b << endl;
        }else{
        cout << a << endl;
        }
  }
  return 0;
}