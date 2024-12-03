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

  vector<int> a(n);
  rep(i,n) cin >> a[i];

  sort(a.rbegin(),a.rend());

  ll sum = 0;
  rep(i,n){
    sum += a[i];
  }

  ll mid = sum/n;
  ll rem = sum%n;
  ll cnt = 0;

  rep(i,n){
    if(a[i]> mid+(i<rem ? 1: 0)){
      cnt += a[i] - (mid +(i<rem ? 1:0));
    }
  }


  cout << cnt << endl;
  return 0;
}