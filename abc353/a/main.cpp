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
  vector<int> b(n);

  rep(i,n){
    int H;
    cin >> H;
    b[i] = H;
  }

  bool high = false;
  int res = 0;
  rep(i,n){
    if(b[i]>b[0]){
      high = true;
      res += i + 1;
      break;
    }
  }

  if(high == true){
  cout << res << endl;
  }else{
      cout << "-1" << endl;
  }


  return 0;
}