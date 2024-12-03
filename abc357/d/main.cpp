#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using ll = long long;
using P = pair<int,int>;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main() {
  ll n;
  cin >> n;


  ll d = 1;
  rep(i,n){
    if(i< 9){
    d = 10*d;
    }else{
      d = 1;
    }
  }

  rep(i,n.size()){

  }

  

  int ans = 0;

  cout << ans << endl;
  return 0;
}