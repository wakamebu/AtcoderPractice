#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using ll = long long;
using P = pair<int,int>;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main() {
  int n,x,y,z;
  cin >> n >> x >> y >> z;

  bool can = false;
  if(x<z && z<y){
    can = true;
  }else if(y<z && z<x){
    can = true;
  }
  if(can == true){
  cout << "Yes" << endl;
  }else{
  cout << "No" << endl;
  }
  return 0;
}