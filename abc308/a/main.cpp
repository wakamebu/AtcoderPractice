#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using ll = long long;
using P = pair<int,int>;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main() {
  vector<int> a(8);
  rep(i,8)cin >> a[i];

  bool can = true;
  rep(i,8){
    int b = a[i];
    if(b % 25 != 0)can = false;
    if(b<100 or b>675)can = false;
  }
  rep(i,7){
    int b = a[i];
    int c = a[i+1];
    if(b>c)can = false;
  }

  cout << (can ? "Yes":"No") << endl;
  return 0;
}