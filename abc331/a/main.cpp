#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using ll = long long;
using P = pair<int,int>;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main() {
  int M,D,y,m,d;
  cin >> M >> D >> y >> m >> d ;

  d++;
  while(d>D){
    d -= D;
    m++;
  }
  while(m>M){
    m -= M;
    y++;
  }

  cout << y <<" "<<m<<" "<<d<< endl;
  return 0;
}