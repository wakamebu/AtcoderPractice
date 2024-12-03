#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using ll = long long;
using P = pair<int,int>;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main() {
  string n;
  cin >> n;
  string ans = "";
  for(char c:n){
    if(c != 'a' and c != 'e' and c != 'i' and c  != 'o' and c != 'u' )ans += c;
  }

  cout << ans << endl;
  return 0;
}