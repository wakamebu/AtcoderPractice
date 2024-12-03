#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using ll = long long;
using P = pair<int,int>;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main() {
  string s;
  cin >> s;
  int sz = s.size();
  char l = s[0];

  rep(i,sz){
    char m = s[i];
    if(l != m){
      if(i == 1){
        if(l != s[2]){
          cout << 1 << endl;
          return 0;
        }else{
          cout << 2 << endl;
          return 0;
        }
      }else{
        cout << i + 1 << endl;
        return 0;
      }
    }

  }
  return 0;
}