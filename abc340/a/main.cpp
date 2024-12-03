#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using ll = long long;
using P = pair<int,int>;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main() {
  int a,b,d;
  cin >> a >> b >> d;

  cout << a;

  int res = a;
  while(res<b){
    cout <<" "<< res+d;
    res += d;
  }
  cout << endl;
  return 0;
}