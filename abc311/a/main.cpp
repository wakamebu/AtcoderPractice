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
  cin >> s;


  bool A = false;
  bool B = false;
  bool C = false;

  rep(i,n){
    if(s[i] == 'A') A= true;
    if(s[i] == 'B') B= true;
    if(s[i] == 'C') C= true;
    if(A and B and C) {cout << i+1 <<endl;
    return 0;
    }
  }

  int ans = 0;

  cout << ans << endl;
  return 0;
}