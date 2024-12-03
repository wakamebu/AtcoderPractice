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
  vector<vector<string>> A(n,vector<string>(n));
  vector<vector<string>> B(n,vector<string>(n));
  
  rep(i,n){
      string jon;
      cin >> jon;
    rep(j,n){
      A.at(i).at(j) = jon.at(j);
    }
  }

  rep(i,n){
      string jon;
      cin >> jon;
    rep(j,n){
      B.at(i).at(j) = jon.at(j);
    }
  }

  rep(i,n){
    rep(j,n){
      if(A.at(i).at(j) != B.at(i).at(j)){
        cout << i+1 << " " << j+1 <<endl;
        return 0;
      }
    }
  }
}