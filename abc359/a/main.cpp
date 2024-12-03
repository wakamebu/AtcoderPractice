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
  vector<string> s(n);
  rep(i,n)cin >> s[i];
  int cnt = 0;
  for(auto x :s){
    if(x =="Takahashi") cnt++;
  }


  cout << cnt << endl;
  return 0;
}