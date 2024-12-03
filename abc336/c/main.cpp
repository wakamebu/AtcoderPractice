#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using ll = long long;
using P = pair<int,int>;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main() {
  ll n;
  cin >> n;

  n--;
  vector<int> a;
  while(n){
    a.push_back(n % 5);
    n /= 5;
  }

  if(a.empty()) a.push_back(0);
  reverse(a.begin(),a.end());
  for(auto x :a)cout << x*2;

  cout << endl;
  return 0;
}