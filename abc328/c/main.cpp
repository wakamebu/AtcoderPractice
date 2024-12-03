#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using ll = long long;
using P = pair<int,int>;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main() {
  int n,q;
  cin >> n>>q;
  string s;
  cin >> s;
  vector<char> subs(n);

  rep(i,s.size()){
    char c = s[i];
    subs[i] = c;
  }

  vector<int> ck(n,0);
  rep(i,n-1){
    if(subs[i+1] == subs[i])ck[i] = 1;
  }

  vector<int> sums(n,0);

  rep(i,n-1){
    sums[i+1] = sums[i] + ck[i];
  }

  rep(i,q){
    int l,r;
    cin >> l >> r;
    cout << sums[r-1] - sums[l-1] << '\n';
  }

  cout << endl;
  return 0;
}