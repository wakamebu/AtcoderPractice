#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using ll = long long;
using P = pair<int,int>;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main() {
  int n,h,x;
  cin >> n >> h >> x;

  vector<int> p(n);
  rep(i,n)cin >> p[i];

  sort(p.begin(),p.end());

  rep(i,n){
    if(h+p[i]>=x){
      cout << i+1 << endl;
      return 0;
    }
  }

  return 0;
}