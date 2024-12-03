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
  int siz = s.size();

  rep(i,siz){
    char C = s[i];
    if(i == 0){
      if(C != '<'){
        cout << "No" << endl;
        return 0;
      }
    }else if(i == siz -1){
      if(C != '>'){
        cout << "No" << endl;
        return 0;
      }
    }else{
      if(C != '='){
        cout << "No" << endl;
        return 0;
      }
    }
  }

  cout << "Yes" << endl;
  return 0;
}