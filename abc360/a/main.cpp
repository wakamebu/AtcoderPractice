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

  int pos1 = 0;
  int pos2 = 0;
  rep(i,3){
    char c = n[i];
    if(c == 'R')pos1 = i;
    if(c == 'M')pos2 = i;
  }

  if(pos1 < pos2)  cout << "Yes" << endl;
  else cout << "No" << endl;
  return 0;
}