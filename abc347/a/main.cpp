#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using ll = long long;
using P = pair<int,int>;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main() {
  int n,k;
  cin >> n >> k;

  vector<int> A(n);
  rep(i,n){
    cin >>A[i];
  }

    int ans =0;
    int it = 0;
    
  rep(i,n){
    if(A[i] %k == 0 && it == 0){
      ans = A[i]/k;
      cout << ans;
      it++;
    }else if(A[i] %k == 0 && it != 0){
      ans = A[i]/k;
      cout << " " << ans;
    }
}
  cout << endl;

  return 0;
}