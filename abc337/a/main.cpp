#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using ll = long long;
using P = pair<int,int>;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main() {
  int n,sumX = 0 , sumY = 0;
  cin >> n;

  rep(i,n){
    int x, y;
    cin >> x >> y;
    sumX += x;
    sumY += y;
  }

  if(sumX == sumY){
    cout << "Draw" << endl;
    return 0;
  }else if(sumX > sumY){
    cout << "Takahashi" << endl;
    return 0;
  }

  cout << "Aoki" << endl;
  return 0;
}