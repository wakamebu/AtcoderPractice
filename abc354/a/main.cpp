#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using ll = long long;
using P = pair<int,int>;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main() {
  int h;
  cin >> h;

//植物の高さ
  int plant = 0;
  int grow = 1;
  int res = 1;
  while(plant < h){
    grow = grow * 2;
    plant += grow;
    res ++;
  }

  cout << res << endl;
  return 0;
}