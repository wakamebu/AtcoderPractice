#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using ll = long long;
using P = pair<int,int>;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main() {
  int n,x;
  cin >> n >> x;
  int l = 100,r = 0, s= 0;
  rep(i,n-1){
    int a;
    cin >> a;
    l=min(l,a);
    r=max(r,a);
    s+=a;
  }

  if(s-r >=x){cout << "0\n";return 0;}
  int need = x -(s-l-r);
  if(need <= r){cout<< need <<"\n";return 0;}
  cout << "-1" << endl;
  return 0;
}