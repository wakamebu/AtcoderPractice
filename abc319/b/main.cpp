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

  string s;

  rep(i,n+1){
    s += "-";
    for(int j=1;j<10;j++){
      if(n % j == 0 && i % (n/j) == 0){
        s[i] = j +'0';
        break;
      }
    }
  }

  cout << s << endl;
  return 0;
}