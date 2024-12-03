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

  int one = n+1;
  vector<int> A(n+n+1);

  rep(i,n+n+1){
    if(i %2 == 0){
      A[i]=1;
    }else{
      A[i]=0;
    }
  }

  rep(i,A.size()){
    cout << A[i];
  }
  cout << endl;
  return 0;
}