#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using ll = long long;
using P = pair<int,int>;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main() {
  int n,m;
  cin >> n >> m;
  vector<int> H(n);
  rep(i,n){
    cin >> H[i];
  }
  int sum = 0;
  rep(i,n){
    sum += H[i];
    if(sum>m){
      cout << i << endl;
      return 0;
    }else if(sum == m){
      cout << i+1 << endl;
      return 0;
    }
  }
  cout << n << endl;
  return 0;

}