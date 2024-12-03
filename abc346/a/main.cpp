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
  vector<int> A(n);

  int ans = 0;
  rep(i,n){
    if(i == 0){
    cin >> A[i];
    continue;
    }else if( i != n-1){
      cin >> A[i];
    ans = A[i]*A[i-1];
    cout << ans << " ";
    }else{
      cin >> A[i];
      ans = A[i]*A[i-1];
      cout << ans << endl;
      return 0;
    }
  }

  return 0;
}