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

  rep(i,n-1){
    if(s[i] == 'a' && s[i+1] =='b'){
      cout << "Yes" << endl;
      return 0;
    }
    if(s[i] =='b' && s[i+1] == 'a'){
      cout << "Yes" << endl;
      return 0;
    }
  }

  cout << "No" << endl;
  return 0;
}