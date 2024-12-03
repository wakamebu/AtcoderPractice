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
  int A;
  queue<int> num;

  rep(i,n){
    cin >> A;
    num.push(A);
  }
  int ans = 0;

  int test = 0;
  rep(i,n){
    rep(j,n){
      test = num.front();
      num.pop();
      if(j>n){
      ans = 100000000 % (test + num.front());
      }
    }

  }

  cout << ans << endl;
  return 0;
}