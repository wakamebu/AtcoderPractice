#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using ll = long long;
using P = pair<int,int>;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main() {
  string s,t;
  cin >> s >> t;

  if(s != "AtCoder"){
    cout << "No" << endl;
    return 0;
  }
  if(t != "Land"){
    cout << "No" << endl;
    return 0;
  }

  cout << "Yes" << endl;
  return 0;
}