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

  bitset<100> bs(n);

  int cnt = 0;
  rep(i,100){
    if(bs.test(i) == false){
      cnt++;
    }else if(bs.test(i) == 1){
      break;
    }
  }

  cout << cnt << endl;
  return 0;
}