#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using ll = long long;
using P = pair<int,int>;

int main() {
  int a,b;
  cin >> a >> b;
  for(int i = 1 ; i<=3;i++){
    if(a == b){
    cout << -1 << endl; break;
    }else if(i != a && i != b){
    cout << i << endl;
    break;}
    else if(i == 3)
    cout << -1 << endl;
  }

//  int ans = 0;

// cout << ans << endl;
  return 0;
}