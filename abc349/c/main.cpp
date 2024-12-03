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
  
  rep(i,3) t[i] = tolower(t[i]);

  //部分列判定
  auto isSubarray = [&](string x) -> bool {
    int xi = 0;
    for (char c : s){
      if(x[xi] == c) xi++;
      if(xi == x.size()) return true;
    }
    return false;
  };

  if(isSubarray(t)){
    cout << "Yes" << endl;
    return 0;
  }
  if(t.back() == 'x'){
    t.pop_back();
    if(isSubarray(t)){
      cout << "Yes" << endl;
      return 0;
    }
  }
  cout << "No" << endl;
  return 0;
}